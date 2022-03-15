#include <iostream>
#include <string>
#include <cstring>
#include "customer.h"

using namespace std;


Customer::Customer(int id, const char* name,const char* surname,int prescription) {
    this->id = id;
    this->prescription = prescription;
    this->name = new char[strlen(name)+1];
    strcpy(this->name,name);
    this->surname = new char[strlen(surname)+1];
    strcpy(this->surname,surname);
    next= nullptr;
}
Customer::~Customer() {
    delete [] name;
    delete [] surname;
}

int &Customer:: rID() {
    return this->id;
}

int &Customer:: rprescription() {
    return this->prescription;
}

char *&Customer:: rname() {
    return this->name;
}

char *&Customer:: rsurname() {
    return this->surname;
}

Customer * &Customer::refNext() {
    return this->next;
}

void Customer::set_next(Customer * t){
    this->next= t;
}
  
  
void Customer::printC(){
    cout<<"Customer's name "<<name<<" "<<surname;
    cout<<" Prescription number: "<<prescription<<endl;
}