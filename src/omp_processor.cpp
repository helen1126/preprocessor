#include "omp_processor.h"
#include "preprocessor.h"
#include <vector>
#include <omp.h>
#include <iostream>
#include <sstream>

/**
 * @brief 并行处理多个提示词，输出JSON格式的解析结果
 * @param prompts 需要处理的提示词向量
 * @details 使用OpenMP并行处理每个提示词，调用PromptPreprocessor解析属性权重，
 *          并通过线程安全的方式输出JSON格式的解析结果
 */
void process_in_parallel(const std::vector<std::string>& prompts) {
    #pragma omp parallel for
    for (size_t i = 0; i < prompts.size(); ++i) {
        PromptPreprocessor processor;
        std::vector<AttributeWeight> attributes = processor.process(prompts[i]);
        
        #pragma omp critical
        {
            // 提取提示词关键词（去除括号及之后的属性）
            std::string prompt_keyword = prompts[i];
            size_t bracket_pos = prompt_keyword.find('(');
            if (bracket_pos != std::string::npos) {
                prompt_keyword = prompt_keyword.substr(0, bracket_pos);
            }

            std::ostringstream json_stream;
            // 使用提取的关键词代替原始prompt
            json_stream << "{ \"prompt\": \"" << prompt_keyword << "\", \"attributes\": [";
            
            for (size_t j = 0; j < attributes.size(); ++j) {
                if (j > 0) json_stream << ", ";
                json_stream << "{ \"" << attributes[j].attribute << "\": " << attributes[j].weight << " }";
            }
            
            json_stream << " ] }";
            std::cout << json_stream.str() << std::endl;
        }
    }
}