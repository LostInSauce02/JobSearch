#ifndef NODE_H
#define NODE_H
#include "Record.h"

class Node
{
    public:
        Node();
        Node(Record tmp);
//        ~Node();
        Node *next;
        Record info;

};

#endif // NODE_H
