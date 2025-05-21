#include "regex_engine.h"
#include <regex>
#include <stdexcept>

/**
 * @brief 解析输入字符串中的属性-权重对
 * @param input 包含属性权重标记的输入字符串（格式示例："提示词(属性:0.75)(属性:0.8)"）
 * @return 解析得到的属性-权重对向量
 * @note 使用正则表达式匹配格式为`(属性名:数值)`的标记，支持中文/字母/数字/下划线属性名
 */
std::vector<AttributeWeight> RegexEngine::parse(const std::string& input) {
    std::vector<AttributeWeight> results;
    std::regex pattern(R"(\(([\p{Han}a-zA-Z0-9_]+):([0-9]+(\.[0-9]+)?)\))");
    std::sregex_iterator it(input.begin(), input.end(), pattern);
    std::sregex_iterator end;

    for (; it != end; ++it) {
        std::smatch match = *it;
        if (match.size() < 3) continue;

        AttributeWeight aw;
        aw.attribute = match[1].str();
        try {
            aw.weight = std::stod(match[2].str());
        } catch (const std::invalid_argument& e) {
            continue;
        }
        results.push_back(aw);
    }
    return results;
}