#pragma once
#include <string>
#include <vector>
#include "regex_engine.h"  // Include to access AttributeWeight definition

// 手动定义缺失的 Windows 类型别名（如果不需要 Windows 依赖）
#ifndef CHAR
typedef char CHAR;
#endif

#ifndef DWORD
typedef unsigned long DWORD;
#endif

class PromptPreprocessor {
public:
    std::vector<AttributeWeight> process(const std::string& input);
};