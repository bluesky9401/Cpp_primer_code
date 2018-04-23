#include "Folder.h"
#include "Message.h"
// 拷贝构造函数
Folder::Folder(const Folder& folder):msgs_(folder.msgs_)
{
    addToMsg();
}
// 拷贝赋值运算符
Folder& Folder::operator=(Folder& rhs)
{
    msgs_ = rhs.msgs_;    
    addToMsg();
}
// 析构函数
Folder::~Folder()
{
    removeFromMsg();
}
/** 根据msgs_成员中存放的指针分别清除对应message中存放的folder信息 **/
void Folder::addToMsg()
{
    for(auto element: msgs_){
        element->folders_.insert(this);
    }
}
void Folder::removeFromMsg()
{
    for(auto element: msgs_){
        element->folders_.erase(this);
    }
}
/** 在传入的Message类指针对应对象中添加/清除folder指针 **/
void Folder::addMsg(Message &ptr_msg)
{
    msgs_.insert(&ptr_msg);
}
void Folder::removeMsg(Message &ptr_msg)
{
    msgs_.erase(&ptr_msg);
}
/** 交换两个Folder类对象，注意更新Message类中所存放folder指针信息 **/
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    lhs.removeFromMsg();
    rhs.removeFromMsg();
    swap(lhs.msgs_, rhs.msgs_);
    lhs.addToMsg();
    rhs.addToMsg();
}
