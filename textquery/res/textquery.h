#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<algorithm>
#include<cctype>

class TextQuery
{
public:
    using line_no = std::vector<std::string>::size_type;//行号类型
    TextQuery(std::ifstream&);//构造函数，接受一个ifstream对象
    std::shared_ptr<std::set<line_no>> query(const std::string& word) const;//查询函数，接受一个单词，返回一个指向包含该单词所在行号的集合的shared_ptr
    const std::string& get_line(line_no line) const{return *lines->at(line -1);};//获取指定行的文本
    line_no get_line_size() const{return lines->size();}//获取行数
private:
    std::shared_ptr<std::vector<std::shared_ptr<std::string>>> lines;//存储文本行的vector，每行是一个shared_ptr指向一个string
    std::map<std::string, std::shared_ptr<std::set<line_no>>> word_map;//存储单词到行号集合的映射
    static std::string cleanup_word(const std::string& word);//清理单词，去除标点符号等
};

void print_results(std::ostream& os, const std::shared_ptr<std::set<TextQuery::line_no>>& lines, const TextQuery& tq, const std::string& word);//打印查询结果的函数，接受一个输出流、一个包含行号的集合、一个TextQuery对象和一个单词