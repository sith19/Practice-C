cmake_minimum_required(VERSION 3.31)
project(Practice C)

set(CMAKE_C_STANDARD 11)
add_executable(Practice htoi.c
        calculator.c
        reverse.c
        pointer_str_fuctions.c
        "more pointer stuff.c"
        day_of_year.c
        "reading input.c"
        "pointer to array.c"
        BST.c
        case.c
        "reading lines of files.c"
        compareFiles.c
        practice.c
)
