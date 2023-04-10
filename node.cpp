#include "node.h"

Node::Node()
{
    name = "";
    department = "";
    gradeLevel = 0;
    next = nullptr;
}

Node::Node(string name, string depart, int grade, long personalID)
{
    this->name = name;
    department = depart;
    gradeLevel = grade;
    this->personalID = personalID;
    next = nullptr;
}

Node::~Node()
{
    
}