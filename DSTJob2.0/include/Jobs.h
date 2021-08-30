#ifndef JOBS_H
#define JOBS_H
#include "Node.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <ctime>
#include <exception>
class Jobs
{
    public:
        Jobs();
        ~Jobs();
        bool isEmpty();
        void print();
        void _swap(Node* lhs, Node* rhs);
        Node change(Node* head);
        void Sort(Node* head);
        void runServer();
        Node *head, *tail;
    private:
        Record temp;
};

#endif // JOBS_H
