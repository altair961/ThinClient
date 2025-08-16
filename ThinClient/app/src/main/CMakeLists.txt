cmake_minimum_required(VERSION 3.22.1)
project("native-activity")

add_library(native-activity SHARED main.cpp)

find_library(log-lib log)
find_library(android-lib android)

target_link_libraries(native-activity
    android
    ${log-lib}
    ${android-lib})