#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "linked-list.h"
using namespace std;

long personalGlobalID = 000000000;

linkedList::linkedList()
{
    head = nullptr;
    tail = nullptr;
}

void linkedList::addNewRecord()
{
    cin.clear();
    cin.ignore();
    Node* current = head;
    string name, deparment;
    int gradeLevel = 0;

    cout << "Please Enter Name: " << endl;
    getline(cin, name);
    transform(name.begin(), name.end(), name.begin(), ::toupper);

    cout << "Please Enter department: " << endl;
    getline(cin, deparment);
    transform(deparment.begin(), deparment.end(), deparment.begin(), ::toupper);

    try
    {
        cout << "Please Enter Grade Level: " << endl;
        cin >> gradeLevel;

        if(cin.fail())
        {
            string e = "Invalide Grade level please use numbers.";
            throw e;
        }

        if(head == nullptr)
        {
            personalGlobalID++;
            head = new Node(name, deparment, gradeLevel, personalGlobalID);
            return;
        }

        while(current->next != nullptr)
        {
            current = current->next;
        }

        personalGlobalID++;
        current->next = new Node(name, deparment, gradeLevel, personalGlobalID);
    }
    
    catch(string& e)
    {
        cout << e << endl;
        return;
    }
}

void linkedList::searchRecord()
{
    cin.ignore();
    Node* current = head;
    string nameBeingSearched = "";
    string departmentBeingSearched = "";
    int personalIDBeingSearched = 0;
    int matchesFound = 0;

    if(head == nullptr)
    {
        cout << "Database is empty, please add users" << endl;
        return;
    }

    try{
        int choice = 0;
        cout << "1-------->Press '1' to search by name" << endl;
        cout << "2-------->Press '2' to search by department" << endl;
        cout << "3-------->Press '3' to search by personal ID" << endl;
        cout << "4-------->Press '4' to go back." << endl;
        cin >> choice;

        if(choice <= 0 || choice > 4)
        {
            string e = "Invalid Option";
            throw e;
        }

        if(choice == 1)
        {
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, nameBeingSearched);
            transform(nameBeingSearched.begin(), nameBeingSearched.end(), nameBeingSearched.begin(), ::toupper);

            if(head->next == nullptr && head->name == nameBeingSearched)
            {
                printNode(head);
                matchesFound++;
            }

            while(current->next != nullptr)
            {
                if(nameBeingSearched == current->name)
                {
                    printNode(current);
                    matchesFound++;
                }

                current = current->next;
            }

            if(matchesFound == 0)
            {
                cout << "No Matches Found" << endl;
            }
            else
            {
                cout << "Total Matches Found: " << matchesFound << endl;
            }
        }
        else if(choice == 2)
        {
            cin.ignore();
            cout << "Enter Department: ";
            getline(cin, departmentBeingSearched);
            transform(departmentBeingSearched.begin(), departmentBeingSearched.end(), departmentBeingSearched.begin(), ::toupper);

            while(current->next != nullptr)
            {
                if(departmentBeingSearched == current->department)
                {
                    printNode(current);
                    matchesFound++;
                }

                current = current->next;
            }

            if(matchesFound == 0)
            {
                cout << "No Matches Found" << endl;
            }
            else
            {
                printNode(current);
                matchesFound++;
                cout << "Total Matches Found: " << matchesFound << endl;
            }
        }
        else if(choice == 3)
        {
            cin.ignore();
            cout << "Enter Personal ID: ";
            cin >> personalIDBeingSearched;

            while(current->next != nullptr)
            {
                if(personalIDBeingSearched == current->personalID)
                {
                    printNode(current);
                    matchesFound++;
                }

                current = current->next;
            }

            if(matchesFound == 0)
            {
                cout << "No Matches Found" << endl;
            }
            else
            {
                cout << "Total Matches Found: " << matchesFound << endl;
            }
        }
    }

    catch(string e)
    {
        cout << e << endl;
    }

}

void linkedList::printNode(Node* current)
{
    cout << "-------------Profile Details-------------" << endl;
    cout << setw(15) << "Name: " << current->name << endl;
    cout << setw(15) << "Department: " << current->department << endl;
    cout << setw(15) << "Grade: " << current->gradeLevel << endl;
    cout << setw(15) << "ID Number: " << current->personalID << endl;
    cout << "-----------------------------------------" << endl;
}

