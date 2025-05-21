#include "preprocessor.h"
#include "omp_processor.h"  
#include <vector>
#include <iostream>

/**
 * @brief 程序主入口，测试预处理功能
 * @details 构造测试提示词列表，调用并行处理函数处理并输出结果，最后打印完成信息
 * @return 0表示正常退出
 */
int main() {
    std::vector<std::string> test_prompts = {
        "这是测试提示词(情感:0.75)(场景:0.8)",
        "另一个提示词(人物:0.6)(时间:0.9)",
        "another_prompt(feel:0.5)(style:0.7)"
    };

    process_in_parallel(test_prompts);

    std::cout << "预处理完成！" << std::endl;
    return 0;
}