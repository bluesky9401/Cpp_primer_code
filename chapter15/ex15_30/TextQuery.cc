#include "TextQuery.h"
#include "QueryResult.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cstring>

using std::shared_ptr;
using std::ifstream;
using std::istringstream;
using std::string;
using std::vector;
using std::set;
using std::cout;
using std::endl;
using std::ispunct;
using std::tolower;
using std::find;

/** 构造函数 **/
TextQuery::TextQuery(ifstream &fis): ptr_file_(new vector<string> )
{
    string str_line;
    line_no curr_line_number;

    while (getline(fis, str_line)) { // 将文件中的字符按行存进ptr_file_指向的vector容器
        ptr_file_->push_back(str_line);
        curr_line_number = ptr_file_->size();// 当前str_line所对应的行号
        istringstream str_is(str_line);
        // 把str_line中每个单词都加入到映射表中，并且保存单词所对应的行号
        for(string word; str_is >> word;){
            cleanUpAndPunc(word);
            // 注意此处ptr_set_line是引用方式，而auto方式需自己加引用
            auto &ptr_set_line = map_string_to_line_[word];// 若map表没有该word，则自动添加对应shared_ptr初始化为nullptr（注意并没绑定内存）
            if (!ptr_set_line){ // 若ptr_set_line为nullptr，则需给其分配内存空间
                ptr_set_line.reset(new set<line_no>);
            }
            ptr_set_line->insert(curr_line_number);
        }
    }
}

// 查询文本中单词str所在的行，以QueryResult的形式返回
QueryResult TextQuery::query(const std::string &stri) const
{
    
    string str = stri;
    cleanUpAndPunc(str);
    static shared_ptr<set<line_no>> no_data(new set<line_no>);
    auto iter_str = map_string_to_line_.find(str);// 返回指向key为str的pair组迭代器
    
    // 返回查询结果
    if (iter_str == map_string_to_line_.end())
        return QueryResult(str, no_data, ptr_file_);
    else
        return QueryResult(str, iter_str->second, ptr_file_);
}

// 打印文本中所有单词所对应的行
void TextQuery::displayMap() const
{
    auto iter_beg = map_string_to_line_.begin(), iter_end = map_string_to_line_.end();

    for(auto iter_map = iter_beg; iter_map != iter_end; ++iter_map){
        cout << "word: " << iter_map->first << " {";
        auto ptr_set_line = iter_map->second;
        auto iter_set = ptr_set_line->begin(), iter_set_end = ptr_set_line->end();// set集合中的首尾迭代器
        while (iter_set != iter_set_end) {
            cout << (*iter_set);       
            if (++iter_set != iter_set_end)
                cout << ',';
        }
        cout << endl;
    }    
}

// 将单词全部转为小写形式并且忽略标点符号
void TextQuery::cleanUpAndPunc(std::string &word)
{
    string str_cat;

    for(auto iter = word.begin(), end = word.end(); iter != end; ++iter){
        if(!ispunct(*iter))
            str_cat += tolower(*iter);
    }
    word = str_cat;
}

/** 打印查询结果 **/
void print(std::ostream &os, const QueryResult &result)
{
    os << "the word " << result.sought_ << " oucurr " 
       << result.size() << " times" << endl;
    for(auto iter = result.cbegin(), iter_end = result.cend(); 
                    iter != iter_end; ++iter){
        cout << "\t(line " << *iter << ") ";
        cout << ' ' << *(result.ptr_file_->begin() + (*iter) - 1) << endl; 
    }    
}
