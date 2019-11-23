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
  if (octets.size()!=4)
    return false;

  for (const auto &octet : octets) {
    if (!is_digits(octet) || std::stoul(octet) > 255) return false;
  }
  return true;
}

class IPv4 {
 public:
  explicit IPv4(const std::string &ip_str) {
    set_value(ip_str);
  }
  explicit IPv4(std::array<uint8_t, 4> octets) : octets_(octets) {}

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
    return {
        std::to_string(octets_[0]) + "." +
            std::to_string(octets_[1]) + "." +
            std::to_string(octets_[2]) + "." +
            std::to_string(octets_[3])
    };
  }
  std::array<uint8_t, 4> octets_{0, 0, 0, 0};

};

}