# PromptPreprocessor ��ʾ��Ԥ������

## ���
���������ڽ�����Ȼ������ʾ���е�����-Ȩ�ر�ǣ���ʽ��`(����:Ȩ��)`����֧����ĸ/����/�»�������������ͨ��OpenMPʵ�ֶ��̲߳��д���

## ��װ�빹��

### ������
- C++17 ���������Ƽ�GCC 11+��MSVC 2019+��
- CMake 3.16+���������ߣ�
- Flex 2.6+���ʷ���������������
- Bison 3.8+���﷨��������������
- OpenMP�����м���֧�֣����������������ã�

### �������裨Windows��
```bash
# ��¡��Ŀ������
git clone https://github.com/your-username/preprocessor.git
cd preprocessor

# ���������빹��Ŀ¼
mkdir build
cd build

# ������Ŀ�ļ���ʹ��MinGW Makefiles��
cmake .. -G "MinGW Makefiles"

# ����
mingw32-make
```

---

## ʹ��ʾ��

### �����ʽ
������ʾ�������`(����:Ȩ��)`��ʽ�ı�ǣ�������ź�ð�ţ���ʾ����
```text
"another_prompt(feel:0.5)(style:0.7)"
```

### ���ʾ��
```json
{ "prompt": "another_prompt(feel:0.5)(style:0.7)", "attributes": [ { "feel": 0.5 }, { "style": 0.7 } ] }
```

---

## Ŀ¼�ṹ
```
preprocessor/
������ build/              # �������Ŀ¼�����ԣ�
������ include/            # ͷ�ļ�
��   ������ preprocessor.h  # Ԥ�������������
��   ������ regex_engine.h  # �������������
������ src/                # Դ�ļ�
��   ������ main.cpp        # �������
��   ������ omp_processor.cpp # ���д���ʵ��
��   ������ preprocessor.cpp # Ԥ��������߼�
��   ������ regex_engine.cpp # ���������ʵ��
������ .gitignore          # Git���Թ���
������ CMakeLists.txt      # ��������
```

        