#cmake_minimum_required(VERSION 3.8)
#project(loggi LANGUAGES CXX)
#
#
#set(HEADER_FILES
#        ${CMAKE_SOURCE_DIR}/include/CommandExecute.h
#        ${CMAKE_SOURCE_DIR}/include/CommandExecuteBase.h
#        ${CMAKE_SOURCE_DIR}/include/Config.h
#        ${CMAKE_SOURCE_DIR}/include/LinuxConfig.h
#        )
#
#set(SOURCE_FILES
#        ${CMAKE_CURRENT_SOURCE_DIR}/CommandExecute.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/Config.cpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/LinuxConfig.cpp
#        )
#
#add_executable(loggi
#        main.cpp
#        ${HEADER_FILES}
#        ${SOURCE_FILES}
#        )
#
#target_include_directories(loggi PUBLIC ${PROJECT_SOURCE_DIR}/include)
#target_compile_options(loggi PRIVATE -Werror)
#target_compile_features(loggi PRIVATE cxx_std_17)
