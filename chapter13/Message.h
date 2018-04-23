#ifndef _MESSAGE_H_
#define _MESSAGE_H_

#include <string>
#include <set>
class Folder;
class Message{
    friend void swap(Message &lhs, Message &rhs);
    friend class Folder;
public:
    // 构造函数
    explicit Message(const std::string &str = " ") : contents_(str) { } //加上explicit禁止利用该构造函数进行隐式初始化
    Message(const Message &msg);
    // 移动构造函数
    Message(Message &&obj): contents_(obj.contents_) { moveFolders(&obj); }
    // 拷贝赋值运算符
    Message& operator=(const Message& msg);
    // 移动赋值运算符
    Message& operator=(Message&& rhs);
    // 析构函数
    ~Message();
    // 从给定folder集合中添加删除本Message
    void save(Folder&);
    void remove(Folder&);
private:
    std::string contents_;
    std::set<Folder*> folders_;
    // 将本Message添加到对应的Folder
    void addToFolders();
    // 从Folders中的每个Folders删除本Message
    void removeFromFolders();
    // 移动folder_, 并且在对应folder中删减旧Message指针和增加新Message指针
    void moveFolders(Message*);
};
void swap(Message &lhs, Message &rhs);
#endif
