cmake_minimum_required(VERSION 3.1)
project(BlitRPG)
include(libs/32blit-beta/32blit.cmake)
blit_executable(rpg src/rpg.cpp)
