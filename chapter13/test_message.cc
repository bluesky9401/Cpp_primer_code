#include "Message.h"
#include "Folder.h"
#include <string>

int main()
{
    std::string str = "chentongjie";
    Message message1(str);
    Folder folder1;
    message1.save(folder1);
    Message message2;
    message2 = std::move(message1);   
    return 0; 
}
