#include <iostream>
#include <string>
#include <cstring>
#include "medicine.h"

using namespace std;

    Medicine::Medicine(int id, const char * name , const char * type,int amount,int precond){
        this->id = id;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name);
        this->type = new char[strlen(type)+1];
        strcpy(this->type,type);
        this->amount= amount;
        this->precond=precond;
        next= nullptr;
    } 

    Medicine::Medicine(const Medicine & Med){
        this->id = Med.id;
        this->name = new char[strlen(Med.name)+1];
        strcpy(this->name,Med.name);
        this->type = new char[strlen(Med.type)+1];
        strcpy(this->type,Med.type);
        this->amount= Med.amount;
        this->precond=Med.precond;
    }

    Medicine::~Medicine(){
        delete[] name;
        delete[] type;
    }   

    int &Medicine::rID(){
        return this->id;
    }   

    char* &Medicine::rname(){
        return this->name;
    }

    char* &Medicine::rtype(){
        return this->type;
    } 

    int &Medicine::ramount(){
        return this->amount;
    }

    int &Medicine::rprecond(){
        return this->precond;
    } 

    Medicine * &Medicine::refNext(){
        return this->next;
    }

    void Medicine::set_next(Medicine * t){
        this->next=t;
    }

    void Medicine::printM(){
        cout<<"Medicine name:"<<name<<endl;
        cout<<"This medicine is ";
        if (precond==0)
        {
            cout<<"not";
        }
        cout<<" prescripted"<<endl;
        cout<<amount<<" in stock"<<endl;
    }      