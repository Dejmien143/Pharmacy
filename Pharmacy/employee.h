#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Employee
{ 
    int id;  
    char * name; 
    char * surname;
    Employee * next;
public: 
    Employee(int id, const char * name , const char * surname); //Constructor
    ~Employee();        //Destructor
    int &rID();         //Reference to private attribute of ID
    char* &rname();     //Reference to private attribute of name
    char* &rsurname();  //Reference to private attribute of surname
    Employee * &refNext();
    void set_next(Employee * t);
    void printE();      //Print Employee data
}; 