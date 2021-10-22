cmake_minimum_required (VERSION 3.8)

project ("vector_ssau_2C1S_lab2")
# Включение высокого уровня предупреждений
if(MSVC) # Компилятор MSVC /W3
    if(CMAKE_C_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
    else()
        set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /W4")
    endif()
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(/experimental:external /external:anglebrackets /external:W0)
elseif(CMAKE_COMPILER_IS_GNUCC) # Компилятор GCC    
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wconversion -Wextra -Wpedantic")
endif()

set(gtest_force_shared_crt ONCACHEBOOL""FORCE)
add_subdirectory ("vector_ssau_2C1S_lab2")
add_subdirectory ("lib/googletest")
add_subdirectory("vector_tests")