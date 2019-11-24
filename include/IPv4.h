#include <string>

namespace lf {

std::vector<std::string> split_str(const std::string &word, char delim) {
  std::stringstream ss{word};
  std::string item;
  std::vector<std::string> result;
  while (std::getline(ss, item, delim)) {
    result.emplace_back(std::move(item));
  }
  return result;
}

bool is_digits(const std::string &str) {
  return std::all_of(str.begin(), str.end(), ::isdigit);
}

bool validate_string_ipv4_octets(const std::vector<std::string> &octets) {
  if (octets.size() != 4)
    return false;

  for (const auto &octet : octets) {
    if (!is_digits(octet) || std::stoul(octet) > 255) return false;
  }
  return true;
}

class IPv4 {
 public:
  constexpr IPv4() : octets_{{0}} {};
  constexpr IPv4(uint8_t a, uint8_t b, uint8_t c, uint8_t d) : octets_{{a, b, c, d}} {}
  constexpr IPv4(unsigned long address) :
      octets_{{static_cast<uint8_t >((address >> 24) & 0xFF),
               static_cast<uint8_t >((address >> 16) & 0xFF),
               static_cast<uint8_t >((address >> 8) & 0xFF),
               static_cast<uint8_t >(address & 0xFF)}} {}
  explicit constexpr IPv4(std::array<uint8_t, 4> octets) : octets_(octets) {}
  explicit IPv4(const std::string &ip_str) {
    set_value(ip_str);
  }
  IPv4(IPv4 const &other) noexcept : octets_{other.octets_} {}
  IPv4 &operator=(IPv4 const &other) noexcept {
    octets_ = other.octets_;
    return *this;
  }

  void set_value(const std::string &ip_str) {
    auto octets = split_str(ip_str, '.');
    if (!validate_string_ipv4_octets(octets)) throw std::runtime_error("Incorrect ipv4 format");
    octets_ = {
        static_cast<uint8_t >(std::stol(octets[0])),
        static_cast<uint8_t >(std::stol(octets[1])),
        static_cast<uint8_t >(std::stol(octets[2])),
        static_cast<uint8_t >(std::stol(octets[3]))
    };
  }

  std::string to_string() {
    std::stringstream sstr;
    sstr << *this;
    return sstr.str();
  }

  constexpr unsigned long to_ulong() const noexcept {
    return (static_cast<unsigned long>(octets_[0]) << 24) |
        (static_cast<unsigned long>(octets_[1]) << 16) |
        (static_cast<unsigned long>(octets_[2]) << 8) |
        static_cast<unsigned long>(octets_[3]);
  }

  friend std::ostream &operator<<(std::ostream &os, const IPv4 &a) {
    os << static_cast<int>(a.octets_[0]) << '.'
       << static_cast<int>(a.octets_[1]) << '.'
       << static_cast<int>(a.octets_[2]) << '.'
       << static_cast<int>(a.octets_[3]);
    return os;
  }

  friend std::istream &operator>>(std::istream &is, IPv4 &a) {
    char d1, d2, d3;
    int b1, b2, b3, b4;
    is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b3;
    if (d1 == '.' && d2 == '.' && d3 == '.')
      a = IPv4(b1, b2, b3, b4);
    else
      is.setstate(std::ios_base::failbit);
    return is;
  }

 private:
  std::array<uint8_t, 4> octets_{0, 0, 0, 0};

};

}