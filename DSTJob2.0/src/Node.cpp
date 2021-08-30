#include "Node.h"

Node::Node()
{
    next = nullptr;
}

Node::Node(Record tmp)
{
   next = nullptr;
   info = tmp;
}
