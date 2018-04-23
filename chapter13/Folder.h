#ifndef _FOLDER_H_
#define _FOLDER_H_

#include <set>

class Message;
class Folder{
    friend void swap(Folder &lhs, Folder &rhs);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder& folder);
    Folder& operator=(Folder& rhs);
    ~Folder(); 
private:
    std::set<Message*> msgs_;
    // 用于本Folder拷贝赋值以及析构
    void addToMsg();
    void removeFromMsg();
    //用于Message向Folder添加删减message指针
    void addMsg(Message&);
    void removeMsg(Message&);
};
void swap(Folder &lhs, Folder &rhs);
#endif
