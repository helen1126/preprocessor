#include "preprocessor.h"
#include "omp_processor.h"  
#include <vector>
#include <iostream>

/**
 * @brief ��������ڣ�����Ԥ������
 * @details ���������ʾ���б����ò��д���������������������ӡ�����Ϣ
 * @return 0��ʾ�����˳�
 */
int main() {
    std::vector<std::string> test_prompts = {
        "��ʾ��1(feel:0.8)(style:0.6)",
        "��ʾ��2(feel:0.9)(style:0.5)",
        "another_prompt(feel:0.5)(style:0.7)"
    };

    process_in_parallel(test_prompts);

    std::cout << "Ԥ������ɣ�" << std::endl;
    system("pause"); // ��ͣ�Բ鿴������
    return 0;
}