#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Customer
{ 
    int id;  
    char * name; 
    char * surname;
    int prescription;
    Customer * next;
public: 
    Customer(int id, const char * name , const char * surname, int prescription); //Constructor
    ~Customer();         //Destructor
    int &rID();          //Reference to private attribute of ID
    char* &rname();      //Reference to private attribute of name
    char* &rsurname();   //Reference to private attribute of surname
    int &rprescription();//Reference to private attribute of prescription
    Customer * &refNext();
    void set_next(Customer * t);
    void printC();       //Print Customer data
}; 
