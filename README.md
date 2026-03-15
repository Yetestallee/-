# TextQuery 文本查询程序

这是一个基于 C++ 的简单文本查询工具，实现从文件中按词查找出现行号并打印对应行内容。

## 目录结构

- `res/main.cpp`：程序入口，读取要查询文件并循环处理查询请求。
- `res/textquery.h`：`TextQuery` 类和 `print_results` 函数声明。
- `res/textquery.cpp`：`TextQuery` 类实现（词清洗、索引构建、查询）和结果打印实现。
- `res/test.txt`：示例测试文本文件。
- `TechnologyAndHumanFlourishing.txt`：示例文本文件（可用于查询）。

## 功能简介

- 加载文本文件，按行存储。
- 将每个单词清洗：只保留字母并转换为小写。
- 构建单词 -> 行号集合索引。
- 支持交互式查询单词并显示出现行号与对应文本行。

## 使用说明

1. 在 `res/` 目录下编译：

```powershell
cd d:\keep_going\cpp_workspace\textquery\res
g++ -g main.cpp textquery.cpp -o textquery.exe
```

2. 运行程序：

```powershell
main.exe
```

3. 按提示输入要查询的文件绝对路径，例如：

```
d:\keep_going\cpp_workspace\textquery\res\test.txt
```

4. 输入要查询的单词（例如：`human`），程序会打印出现次数及每个出现行的内容。

5. 输入 `q` 退出程序。

## 编译与调试（VS Code）

你可以使用 VS Code 的 `tasks.json` 或 C/C++ 扩展自动编译。当前工作区已提供 `G++ Compiler` 任务（位于 `res` 文件夹）可以快速构建。

## 改进建议

- 支持更多字符集（例如中文分词）
- 支持正则查询
- 支持统计输出（词频、TopN）
- 支持导出查询结果到文件

## 注意

- 当前 `cleanup_word` 仅识别字母字符，中文、数字、标点会被过滤。
- 查询是区分大小写前统一小写处理。

---