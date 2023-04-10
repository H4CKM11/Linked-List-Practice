#include <iostream>
#include "linked-list.h"
using namespace std;

int main()
{
    linkedList list;
    int runToken = 1;
    int decision = 0;

    while(runToken == 1)
    {
        try
        {
            cout << "1-------->Press '1' to add new record." << endl;
            cout << "2-------->Press '2' to search a record." << endl;
            cout << "3-------->Press '3' to modify a record." << endl;
            cout << "4-------->Press '4' to delete a record." << endl;
            cout << "5-------->Press '5' to exit." << endl;

            cin >> decision;

            if(decision <= 0 || decision > 5)
            {
                string e = "Inavalid Input, please try again";
                throw(e);
            }

            switch(decision)
            {
                case 1:
                    list.addNewRecord();
                    break;
                case 2:
                    list.searchRecord();
                    break;
                case 3:
                    //ADD FUNCTION;
                    break;
                case 4:
                    //ADD FUNCTION;
                    break;
                case 5:
                    runToken = 0;
                    break;
            }
        }

        catch(string& e)
        {
            cout << e << endl;
        }
    }

    cout << "Thank you for using our system, see you later" << endl;


    return 0;
}