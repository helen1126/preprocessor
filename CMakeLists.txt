cmake_minimum_required(VERSION 3.16)
project(PromptPreprocessor LANGUAGES CXX)

# 启用C++17标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找Flex/Bison
find_package(FLEX REQUIRED)
find_package(BISON REQUIRED)

# 生成词法/语法分析器代码
FLEX_TARGET(Lexer src/lexer.l ${CMAKE_CURRENT_BINARY_DIR}/lexer.cpp)
BISON_TARGET(Parser src/parser.y ${CMAKE_CURRENT_BINARY_DIR}/parser.cpp)
ADD_FLEX_BISON_DEPENDENCY(Lexer Parser)

# 启用OpenMP
find_package(OpenMP REQUIRED)
if(OpenMP_CXX_FOUND)
    add_compile_options(${OpenMP_CXX_FLAGS})
endif()

# 包含生成文件目录
include_directories(${CMAKE_CURRENT_BINARY_DIR} include)

# 构建目标（添加main.cpp到源文件列表）
add_executable(prompt_preprocessor 
    src/preprocessor.cpp
    src/regex_engine.cpp
    src/omp_processor.cpp
    src/main.cpp 
    ${FLEX_Lexer_OUTPUTS}
    ${BISON_Parser_OUTPUTS}
)

# 链接库
target_link_libraries(prompt_preprocessor 
    OpenMP::OpenMP_CXX
)