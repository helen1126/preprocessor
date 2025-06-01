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
        "提示词1(feel:0.8)(style:0.6)",
        "提示词2(feel:0.9)(style:0.5)",
        "another_prompt(feel:0.5)(style:0.7)"
    };

    process_in_parallel(test_prompts);

    std::cout << "预处理完成！" << std::endl;
    system("pause"); // 暂停以查看输出结果
    return 0;
}