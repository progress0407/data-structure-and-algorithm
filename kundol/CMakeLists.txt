cmake_minimum_required(VERSION 3.25)
project(kundol)

set(CMAKE_CXX_STANDARD 11)

add_executable(kundol main.cpp ch_0_basic/mm.cpp ch_0_basic/mm.h ch_0_basic/concept/combination_by_recursive.cpp ch_1_big_o_impl/prefix_sum__not_good.cpp ch_1_big_o_impl/prefix_sum.cpp)
