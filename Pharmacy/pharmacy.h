#include <iostream>
#include <string>
#include <cstring>
#include "employee.h"
#include "medicine.h"

using namespace std;

class Pharmacy
{
    int id;  
    char * name; 
    char * town; 
    Medicine * headM;
    Employee * headE;
    Pharmacy * next;
public:
    Pharmacy(int id, const char * name , const char * town); //Constructor
    ~Pharmacy();   //Destructor
    int &rID();    //Reference to private attribute of ID
    char* &rname();//Reference to private attribute of name
    char* &rtown();//Reference to private attribute of town
    Pharmacy * &refNext();
    void set_next(Pharmacy * t);
    void printP();   //
    //Prints pharmacy data 
    bool add_Medicine(int id, const char * name , const char * type,int amount,int precond); ////
    //Adds medicine to a list
    void remove_Medicine(const char * name); //
    //Deletes medicine from a list
    bool changeamount_Medicine(int amount,int id); ////
    //Change amount of medicine of a given id
    bool changeprescription_Medicine(int idmedicine);  // //
    //Change status of medicine to non prescripted
    bool add_Employee(int id, const char * name , const char * surname); ////
    //Adds employee to a list
    void remove_Employee(int id); //
    //Deletes employee from a list
    int amount_of_Medicines(); //
    //Return number of all medicines in stock
    int amount_of_Employees(); //
    //Return number of all employees
    int amount_of_1Medicine(const char * name); //
    //Return number of all medicines of given name
    int give_alternative(int customerprescription);
    bool check_med(int idmedicine);
    bool medicinepresent(int id, const char * name , const char * type,int amount,int precond);
    bool employeepresent(int id,const char * name , const char * surname);//
    /*int get_id(int id);
    char* get_name(int id);
    char* get_type(int id);
    int get_amount(int id);
    int get_precond(int id);*/

};