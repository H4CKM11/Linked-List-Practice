#ifndef FUNCTION_LIST_H
#define FUNCTION_LIST_H

#include "node.h"

class linkedList
{
private:
    Node* head;
    Node* tail;

public:
    linkedList();

    void addNewRecord();
    void searchRecord();
    void printNode(Node* current);
};




#endif