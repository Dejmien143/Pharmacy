#include <iostream>
#include <string>
#include <cstring>
#include "employee.h"

using namespace std;


    Employee::Employee(int id, const char * name , const char * surname){
        this->id = id;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->surname = new char[strlen(surname)+1];
        strcpy(this->surname,surname);
        next=nullptr;
    }

    Employee::~Employee(){
        delete [] name;
        delete [] surname;
    }        
    int &Employee::rID(){
        return this->id;
    }        
    char* &Employee::rname(){
        return this->name;
    }  
    char* &Employee::rsurname(){
        return this->surname;
    }  
    Employee * &Employee::refNext(){
        return this->next;
    }

    void Employee::set_next(Employee * t){
        this->next= t;
    }

    void Employee::printE(){
        cout<<"Employee's name "<<name<<" "<<surname<<endl;
    }     