# PromptPreprocessor 提示词预处理工具

## 简介
本工具用于解析自然语言提示词中的属性-权重标记（格式如`(属性:权重)`），支持字母/数字/下划线属性名，并通过OpenMP实现多线程并行处理。

## 安装与构建

### 依赖项
- C++17 编译器（推荐GCC 11+或MSVC 2019+）
- CMake 3.16+（构建工具）
- Flex 2.6+（词法分析器生成器）
- Bison 3.8+（语法分析器生成器）
- OpenMP（并行计算支持，多数编译器已内置）

### 构建步骤（Windows）
```bash
# 克隆项目到本地
git clone https://github.com/your-username/preprocessor.git
cd preprocessor

# 创建并进入构建目录
mkdir build
cd build

# 生成项目文件（使用MinGW Makefiles）
cmake .. -G "MinGW Makefiles"

# 编译
mingw32-make
```

---

## 使用示例

### 输入格式
输入提示词需包含`(属性:权重)`格式的标记（半角括号和冒号），示例：
```text
"another_prompt(feel:0.5)(style:0.7)"
```

### 输出示例
```json
{ "prompt": "another_prompt(feel:0.5)(style:0.7)", "attributes": [ { "feel": 0.5 }, { "style": 0.7 } ] }
```

---

## 目录结构
```
preprocessor/
├── build/              # 构建输出目录（忽略）
├── include/            # 头文件
│   ├── preprocessor.h  # 预处理核心类声明
│   └── regex_engine.h  # 正则解析器声明
├── src/                # 源文件
│   ├── main.cpp        # 程序入口
│   ├── omp_processor.cpp # 并行处理实现
│   ├── preprocessor.cpp # 预处理核心逻辑
│   └── regex_engine.cpp # 正则解析器实现
├── .gitignore          # Git忽略规则
└── CMakeLists.txt      # 构建配置
```

        