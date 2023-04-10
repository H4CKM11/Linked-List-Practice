#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class linkedList;

class Node
{
private:
    string name;
    string department;
    int gradeLevel;
    long personalID;
    Node* next;

public:
    Node();
    Node(string, string, int, long);
    ~Node();

    friend linkedList;
};




#endif