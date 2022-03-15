#include <iostream>
#include <string>
#include <cstring>
using namespace std;



class Medicine
{ 
    int id;  
    char * name; 
    char * type; 
    int amount;
    int precond;
    Medicine * next;
public: 
    Medicine(int id, const char * name , const char * type,int amount,int precond); //Constructor
    Medicine(const Medicine & Med);
    ~Medicine();        //Destructor
    int &rID();         //Reference to private attribute of ID
    char* &rname();     //Reference to private attribute of name
    char* &rtype();     //Reference to private attribute of type
    int &ramount();     //Reference to private attribute of amount of medicine in stock 0 means nonprescripted
    int &rprecond();    //Reference to private attribute of prescription status
    Medicine * &refNext();
    void set_next(Medicine * t);
    void printM();      //Print Medicine data
}; 