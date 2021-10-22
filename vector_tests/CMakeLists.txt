cmake_minimum_required (VERSION 3.8)
add_executable (VectorTests "Vector_test.cpp" "../vector_ssau_2C1S_lab2/Vector.h" "../vector_ssau_2C1S_lab2/Vector.inl")
target_link_libraries(VectorTests "gmock_main")