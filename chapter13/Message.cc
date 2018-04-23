#include "Folder.h"
#include "Message.h"
#include <iostream>
Message::Message(const Message &msg): contents_(msg.contents_),folders_(msg.folders_)
{
    addToFolders();
}
//拷贝赋值运算符
Message& Message::operator=(const Message& rhs)
{
    if (this != &rhs){
        removeFromFolders();
        contents_ = rhs.contents_;

        folders_ = rhs.folders_;
        addToFolders();
    }
    return *this;
}

/** 移动赋值运算符 **/
Message& Message::operator=(Message&& rhs)
{
    if (this != &rhs)
    {
        removeFromFolders();        
        contents_ = rhs.contents_;
        moveFolders(&rhs);
    }
    std::cout << "move assigned operating" << std::endl;
    return *this;
}

// 
void Message::moveFolders(Message *ptr_m)
{
    folders_ = std::move(ptr_m->folders_);
    for(auto f : folders_) {
        f->removeMsg(*ptr_m);
        f->addMsg(*this);
    }
    ptr_m->folders_.clear();
}
//析构函数
Message::~Message()
{
    removeFromFolders();
}
/**在指定的folder中存放/删除message指针**/
void Message::save(Folder& folder)
{
    folders_.insert(&folder);
    folder.addMsg(*this);
}
void Message::remove(Folder& folder)
{
    folders_.erase(&folder);
    folder.removeMsg(*this);
}
/**根据message中的folders_成员中存放的folder指针在对应folder中存放message指针**/
void Message::addToFolders()
{
    for(auto element: folders_){
        element->addMsg(*this);
    }
}
void Message::removeFromFolders()
{
    for(auto element: folders_){
        element->removeMsg(*this);
    }
}
/**交换两个Message类型的对象，注意更新folder中的信息**/
void swap(Message &lhs, Message &rhs)
{
    using std::swap;
    //清除对应folders中存放的message指针
    lhs.removeFromFolders();
    rhs.removeFromFolders();
    //交换两个对象的内容
    swap(lhs.contents_, rhs.contents_);
    swap(lhs.folders_, rhs.folders_);
    //将message指针存放到对应的folder
    lhs.addToFolders(); 
    rhs.addToFolders();
}
