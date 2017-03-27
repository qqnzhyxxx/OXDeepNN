cmake_minimum_required(VERSION 2.8.11)
FILE(GLOB_RECURSE EigenHeadFiles "*")
add_custom_target(EigenHeadFilesShow SOURCES ${EigenHeadFiles})

