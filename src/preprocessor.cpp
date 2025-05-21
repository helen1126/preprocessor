#include "preprocessor.h"
#include "regex_engine.h"
#include <iostream>

/**
 * @brief 执行提示词预处理，调用正则引擎解析属性权重
 * @param input 原始提示词字符串
 * @return 解析得到的属性-权重对向量
 * @note 输出解析到的属性数量（用于调试验证）
 */
std::vector<AttributeWeight> PromptPreprocessor::process(const std::string& input) {
    RegexEngine engine;
    auto results = engine.parse(input);
    std::cout << "Processed " << results.size() << " attribute-weight pairs" << std::endl;
    return results;
}
// Remove the line: #include "omp_processor.cpp"  <-- 关键修改