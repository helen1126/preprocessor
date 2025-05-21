#include "regex_engine.h"
#include <regex>
#include <stdexcept>

/**
 * @brief ���������ַ����е�����-Ȩ�ض�
 * @param input ��������Ȩ�ر�ǵ������ַ�������ʽʾ����"��ʾ��(����:0.75)(����:0.8)"��
 * @return �����õ�������-Ȩ�ض�����
 * @note ʹ��������ʽƥ���ʽΪ`(������:��ֵ)`�ı�ǣ�֧������/��ĸ/����/�»���������
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