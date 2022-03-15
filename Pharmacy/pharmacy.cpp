#include <iostream>
#include <string>
#include <cstring>
#include "pharmacy.h"
using namespace std;


    Pharmacy::Pharmacy(int id, const char * name , const char * town){
        this->id = id;
        this->name = new char[strlen(name)+1];
        strcpy(this->name,name); 
        this->town = new char[strlen(town)+1];
        strcpy(this->town,town);
        this->headM=nullptr;
        this->headE=nullptr;
        next= nullptr;
    }

    Pharmacy::~Pharmacy(){
        delete [] name;
        delete [] town;
    }
    
    int &Pharmacy::rID(){
        return this->id = id;
    }

    char* &Pharmacy::rname(){
        return this->name;
    }

    char* &Pharmacy::rtown(){
        return this->town;
    }

    Pharmacy * &Pharmacy::refNext(){
        return this->next;
    }

    void Pharmacy::set_next(Pharmacy * t){
        this->next=t;
    }

    bool Pharmacy::add_Medicine(int id, const char * name , const char * type,int amount,int precond){
        Medicine* NewMedicine=headM;

        if(NewMedicine==nullptr)
        {

            Medicine * New = new Medicine(id,name,type,amount,precond);
            this->headM= New;
            return true;  
        }

        while (NewMedicine)
        {
            if(id==NewMedicine->rID())
            {
                return false;
            }
        
        
        if(NewMedicine->refNext()==nullptr)
        {
            Medicine * New = new Medicine(id,name,type,amount,precond);
            NewMedicine->refNext()= New;
            return true;
        }
        NewMedicine= NewMedicine->refNext();


        }

        return false;
    }

    bool Pharmacy::add_Employee(int id, const char * name , const char * surname){
        Employee* NewEmployee=headE;

        if(NewEmployee==nullptr)
        {

            Employee * New = new Employee(id,name,surname);
            this->headE= New;
            return true;  
        }

        while (NewEmployee)
        {
            if(id==NewEmployee->rID())
            {
                return false;
            }
        
        
        if(NewEmployee->refNext()==nullptr)
        {
            Employee * New = new Employee(id,name,surname);
            NewEmployee->refNext()= New;
            return true;
        }
        NewEmployee= NewEmployee->refNext();


        }

        return false;
    }

    int Pharmacy::amount_of_Medicines(){
        int sum=0;
        Medicine *Medicine =this->headM;


        if(Medicine==nullptr)
        {
            return 0;
        }
        
        while(Medicine)
        {
            sum++;
            Medicine= Medicine->refNext();
        }
        return sum;
    } 
    
    int Pharmacy::amount_of_1Medicine(const char * name){
        int sum=0;
        Medicine *Medicine =this->headM;


        if(Medicine==nullptr)
        {
            return 0;
        }
        
        while(Medicine)
        {
            if(strcmp( Medicine->rname(), name ) == 0 )
            sum++;
            Medicine= Medicine->refNext();
        }
        return sum;
    }

    bool Pharmacy::changeprescription_Medicine(int idmedicine){
        Medicine *Medicine =this->headM;

         while(Medicine)
        {
            if(Medicine->rID()==idmedicine)
            {
                Medicine->rprecond()=0;
                return true;
            }
        }
        return false;
    } 
    

    bool Pharmacy::changeamount_Medicine(int amount,int id){
        Medicine *Medicine =this->headM;

         while(Medicine)
        {
            if(Medicine->rID()==id)
            {
                Medicine->ramount()=amount;
                return true;
            }
        }
        return false;
    } 
    
    void Pharmacy::remove_Medicine(const char * name){
        int n=amount_of_1Medicine(name);
        
        while(n!=0){
        Medicine* prev =nullptr;
        Medicine* cur= this->headM;
        while (cur != nullptr && strcmp (name, cur->rname())!=0)
        {
            prev = cur;
            cur = cur->refNext();
        }

        if(cur!=nullptr)
        {
            if(prev!=nullptr)
            {
                prev->refNext()=cur->refNext();
                delete cur;

            }
            else
            {
                if (cur->refNext())
                {
                    this->headM = cur->refNext();
                }
                else
                {
                    this->headM = nullptr;
                }
                delete cur;
            }
        }

        n--;
        }
        
    } 

    void Pharmacy::remove_Employee(int id){
        int n=1;
        
        while(n!=0){
        Employee* prev =nullptr;
        Employee* cur= this->headE;
        while (cur != nullptr && strcmp (name, cur->rname())!=0)
        {
            prev = cur;
            cur = cur->refNext();
        }

        if(cur!=nullptr)
        {
            if(prev!=nullptr)
            {
                prev->refNext()=cur->refNext();
                delete cur;

            }
            else
            {
                if (cur->refNext())
                {
                    this->headE = cur->refNext();
                }
                else
                {
                    this->headE = nullptr;
                }
                delete cur;
            }
        }

        n--;
        }
        
    }

    int Pharmacy::amount_of_Employees(){
        int sum=0;
        Employee *Employee =this->headE;


        if(Employee==nullptr)
        {
            return 0;
        }
        
        while(Employee)
        {
            sum++;
            Employee= Employee->refNext();
        }
        return sum;

    }

    void Pharmacy::printP(){
        
        cout<<this->rname()<<" pharmacy:"<<endl;
        cout<<"Number of employees in this pharmacy "<<amount_of_Employees()<<endl;
        cout<<"Number of medicines in this pharmacy "<<amount_of_Medicines()<<endl;
        cout<<"Information about employees"<<endl;
        Employee* Cur=headE;
        while(Cur!=nullptr)
        {
            Cur->printE();
            Cur= Cur->refNext();
        }
        cout<<"Information about medicines"<<endl;
        Medicine* Curr=headM;
        while(Curr!=nullptr)
        {
            Curr->printM();
            Curr= Curr->refNext();
        }
    }

    int Pharmacy::give_alternative(int customerprescription){
        Medicine* medicine= this->headM;
        int pre=0;
        const char* typ;
        while(medicine)
        {
            if(customerprescription==medicine->rprecond())
            {
                typ=medicine->rtype();
                break;
            }
            medicine=medicine->refNext();

        }
        Medicine* medicine2= this->headM;
        while(medicine2)
        {
            if(strcmp(typ,medicine2->rtype())!=0)
            {
                pre=medicine2->rID();
                break;
            }
            medicine=medicine->refNext();

        }
        return pre;
    }

    bool Pharmacy::check_med(int idmedicine){
        Medicine* medicine= this->headM;
        while(medicine)
        {
            if(medicine->rID()==idmedicine)
            {
                return true;
                break;
            }
            medicine=medicine->refNext();
        }
        return false;
    }

    bool Pharmacy::medicinepresent(int id, const char * name , const char * type,int amount,int precond){
        Medicine* Medicine=this->headM;
        while(Medicine)
        {
            if((id==Medicine->rID())&&(strcmp (name, Medicine->rname())==0)&&(strcmp (type, Medicine->rtype())==0)&&(amount==Medicine->ramount())&&(precond==Medicine->rprecond()))
            return true;
            else{
                Medicine= Medicine->refNext();
            }
        }
        return false;
    }
    bool Pharmacy::employeepresent(int id,const char * name , const char * surname){
        Employee* Employee=this->headE;
        while(Employee)
        {
            if((id==Employee->rID())&&(strcmp (name, Employee->rname())==0)&&(strcmp (surname, Employee->rsurname())==0))
            return true;
            else{
                Employee= Employee->refNext();
            }
        }
        return false;
    }