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
#include "textquery.h"





TextQuery::TextQuery(std::ifstream& is)
    :lines(std::make_shared<std::vector<std::shared_ptr<std::string>>>())
{
    std::string text;
    while(getline(is,text)){
        lines->push_back(std::make_shared<std::string>(text));
        line_no n = lines->size();
        std::stringstream ss(text);
        std::string word;
        while(ss>>word){
            auto clean_word=cleanup_word(word);
            if(!word_map[clean_word]){
                word_map[clean_word]=std::make_shared<std::set<line_no>>();
            }
            word_map[clean_word]->insert(n);
        }
    }
}

std::string TextQuery::cleanup_word(const std::string& word){
    std::string res;
    auto is_letter=[](char c){return isalpha(static_cast<unsigned char>(c));};
    auto to_lower=[](char c){return std::tolower(static_cast<unsigned char>(c));};
    for(char c : word){
        if(is_letter(c)){
            res += to_lower(c);
        }
    }
    return res;
}

std::shared_ptr<std::set<TextQuery::line_no>> TextQuery::query(const std::string& word) const{
    std::string clean_word = cleanup_word(word);
    auto f = word_map.find(clean_word);
    if(f == word_map.end()){
        return std::make_shared<std::set<line_no>>();
    }
    return f->second;
}

void print_results(std::ostream& os, const std::shared_ptr<std::set<TextQuery::line_no>>& lines, const TextQuery& tq, const std::string& word){
    os<<"-----------------------------"<<std::endl;
    os <<"["<<word<< "]"<<"一共出现了"<<lines->size()<<"次"<<std::endl;
    for(auto num : *lines){
        os<<"\t(第"<<num<<"行) "<<tq.get_line(num)<<std::endl;
    }
    os<<"-----------------------------"<<std::endl;
}






