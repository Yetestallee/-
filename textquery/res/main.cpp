#include<iostream>
#include<fstream>
#include<string>
#ifdef _WIN32
#include<windows.h>
#endif
#include "textquery.h"

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
    std::cout << "-------------start------------"<< std::endl;
    std::string file_name;
    std::cout << "请输入要查询的文件名：(请输入文件的绝对路径，而且不要带有引号)"<<std::endl;
    std::cin >> file_name;
    std::ifstream infile(file_name);
    if (!infile) {
        std::cerr << "无法打开文件: " << file_name << std::endl;
        return 1;
    }
    TextQuery tq(infile);
    while (true) {
        std::string word;
        std::cout << "请输入要查询的单词（输入\"q\"退出）："<<std::endl;
        std::cin >> word;
        if (word == "q") {
            break;
        }
        auto lines = tq.query(word);
        print_results(std::cout, lines, tq, word);
    }

    std::cout << "-------------end------------"<< std::endl;
    return 0;
}