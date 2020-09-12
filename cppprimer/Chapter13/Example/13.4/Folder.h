#ifndef FOLDER_H
#define FOLDER_H

#include "Message.h"
#include <set>

class Folder{

public:
    void addMsg(Message *m);
    void remMsg(Message *m);

private:
    std::set<Message*> messages;

};

#endif