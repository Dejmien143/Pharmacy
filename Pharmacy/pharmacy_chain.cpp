#include <iostream>
#include <string>
#include <cstring>
#include "pharmacy_chain.h"

using namespace std;

    Pharmacy_Chain::Pharmacy_Chain(){
        this->headP=nullptr;
        this->headC=nullptr;
    }

    Pharmacy_Chain::~Pharmacy_Chain(){
        ///
    }


    bool Pharmacy_Chain::add_Customer(int id, const char * name , const char * surname, int prescription){
        Customer* NewCustomer=headC;

        if(NewCustomer==nullptr)
        {

            Customer * New = new Customer(id,name,surname,prescription);
            this->headC= New;
            return true;  
        }

        while (NewCustomer)
        {
            if(id==NewCustomer->rID())
            {
                return false;
            }
        
        
        if(NewCustomer->refNext()==nullptr)
        {
            Customer * New = new Customer(id,name,surname,prescription);
            NewCustomer->refNext()= New;
            return true;
        }
        NewCustomer= NewCustomer->refNext();


        }

        return false;
    }
    
    bool Pharmacy_Chain::add_Pharmacy(int id, const char * name , const char * town){
        Pharmacy* NewPharmacy=headP;

        if(NewPharmacy==nullptr)
        {
            Pharmacy * New = new Pharmacy(id,name,town);
            this->headP= New;
            return true;   
        }

        while (NewPharmacy)
        {
            if(id==NewPharmacy->rID())
            {
                return false;
            }
        
        
        if(NewPharmacy->refNext()==nullptr)
        {
            Pharmacy * New = new Pharmacy(id,name,town);
            NewPharmacy->refNext()= New;
            return true;
        }
        NewPharmacy= NewPharmacy->refNext();


        }
        return false;
    }
    
    int Pharmacy_Chain::number_of_Customers(){
        int sum=0;
        Customer *customer =this->headC;


        if(customer==nullptr)
        {
            return 0;
        }
        
        while(customer)
        {
            sum++;
            customer= customer->refNext();
        }
        return sum;
    }  
    
    int Pharmacy_Chain::number_of_Pharmacies(){
        int sum=0;
        Pharmacy *Pharmacy =this->headP;


        if(Pharmacy==nullptr)
        {
            return 0;
        }
        
        while(Pharmacy)
        {
            sum++;
            Pharmacy= Pharmacy->refNext();
        }
        return sum;
    } 
    int Pharmacy_Chain::number_of_Pharmacies_in_same_town(const char * name){
        int sum=0;
        Pharmacy *Pharmacy =this->headP;


        if(Pharmacy==nullptr)
        {
            return 0;
        }
        
        while(Pharmacy)
        {
            if(strcmp( Pharmacy->rtown(), name ) == 0 )
            {
                sum++;
                Pharmacy= Pharmacy->refNext();
            }
            
        }
        return sum;
    }
    
    int Pharmacy_Chain::amount_of_1Customer(const char * name){
        int sum=0;
        Customer *Customer =this->headC;


        if(Customer==nullptr)
        {
            return 0;
        }
        
        while(Customer)
        {
            if(strcmp( Customer->rname(), name ) == 0 )
            sum++;
            Customer= Customer->refNext();
        }
        return sum;
    }

    int Pharmacy_Chain::amount_of_1Pharmacy(const char * name){
        int sum=0;
        Pharmacy *Pharmacy =this->headP;


        if(Pharmacy==nullptr)
        {
            return 0;
        }
        
        while(Pharmacy)
        {
            if(strcmp( Pharmacy->rname(), name ) == 0 )
            sum++;
            Pharmacy= Pharmacy->refNext();
        }
        return sum;
    }

    void Pharmacy_Chain::remove_Customer(const char * name){
        int n=amount_of_1Customer(name);
        
        while(n!=0){
        Customer* prev =nullptr;
        Customer* cur= this->headC;
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
                    this->headC = cur->refNext();
                }
                else
                {
                    this->headC = nullptr;
                }
                delete cur;
            }
        }

        n--;
        }
        
    }
    
    void Pharmacy_Chain::remove_Pharmacy(const char * name){
        int n=amount_of_1Pharmacy(name);
        
        while(n!=0){
        Pharmacy* prev =nullptr;
        Pharmacy* cur= this->headP;
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
                    this->headP = cur->refNext();
                }
                else
                {
                    this->headP = nullptr;
                }
                delete cur;
            }
        }

        n--;
        }
        
    }

    int Pharmacy_Chain::give_alternative_to_prescripted_medicine(int customerID,int pharmacyID){
        
        Pharmacy* pharmacy=this->headP;
        while(pharmacy)
        {
            if(pharmacyID==pharmacy->rID())
            {
                break;
            }
            pharmacy=pharmacy->refNext();

        }
        Customer* customer= this->headC;
        while(customer)
        {
            if(customerID==customer->rID())
            {
                break;
            }
            customer=customer->refNext();

        }

        return pharmacy->give_alternative(customer->rprescription());
    }
    /*
    bool Pharmacy_Chain::transfer_medicine_to_another_pharmacy(int idmedicine, int idpharmacyto,int pharmacyfrom){
        Pharmacy* pharmacy=this->headP;
        
        while(pharmacy)
        {
            if(pharmacyfrom==pharmacy->rID())
            {
               if(pharmacy->check_med(idmedicine)) 

                break;
            }
            pharmacy=pharmacy->refNext();

        }
        Pharmacy* pharmacy2=this->headP;
        while(pharmacy2)
        {
            if(idpharmacyto==pharmacy2->rID())
            {
                pharmacy2->add_Medicine(pharmacy->get_id(idmedicine),pharmacy->get_name(idmedicine),pharmacy->get_type(idmedicine),pharmacy->get_amount(idmedicine),pharmacy->get_precond(idmedicine));
                //pharmacy->remove_Medicine()
                return true;
                break;
            }
            pharmacy2=pharmacy2->refNext();
            
        }
        return false;
    }
    */
    bool Pharmacy_Chain::add_Medicine(int idpharmacy,int id, const char * name , const char * type,int amount,int precond){
        Pharmacy* pharmacy=this->headP;

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                break;
            }
            pharmacy= pharmacy->refNext();
        }

        if(id>0&&name!="" &&type!="" &&amount>=0 &&precond>=0 )
        {
            pharmacy->add_Medicine(id,name,type,amount,precond);
            return true;
        }
    return false;
    }

    bool Pharmacy_Chain::add_Employee(int idpharmacy,int id, const char * name , const char * surname){
        Pharmacy* pharmacy=this->headP;

        if(idpharmacy<0)
        {
            return false;
        }

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                break;
            }
            pharmacy= pharmacy->refNext();
        }

        if(id>0&&name!=""&&surname!="")
        {
            pharmacy->add_Employee(id,name,surname);
            return true;
        }
        return false;
    }

    bool Pharmacy_Chain::changeamount_Medicine(int idpharmacy,int amount,int id){
        Pharmacy* pharmacy=this->headP;

        if(idpharmacy<0)
        {
            return false;
        }

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                break;
            }
            pharmacy= pharmacy->refNext();
        }

        if(id>0&&amount>=0)
        {
            pharmacy->changeamount_Medicine(amount,id);
            return true;
        }
        return false;
    }

    bool Pharmacy_Chain::changeprescription_Medicine(int idpharmacy,int idmedicine){
        Pharmacy* pharmacy=this->headP;
        if(idpharmacy<0)
        {
            return false;
        }

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                break;
            }
            pharmacy= pharmacy->refNext();
        }

        if(idmedicine>=0)
        {
            pharmacy->changeprescription_Medicine(idmedicine);
            return true;
        }
        return false;
    }

    void Pharmacy_Chain::printPC(){
        Pharmacy* pharmacy=this->headP;
        Customer* customer=this->headC;
        cout<<"Informations about pharmacies"<<endl;
        while(pharmacy)
        {
            pharmacy->printP();
            pharmacy= pharmacy->refNext();
        }
        cout<<"Informations about customers"<<endl;
        while(customer)
        {
            customer->printC();
            customer= customer->refNext();
        }
    }

    bool Pharmacy_Chain::customerpresent(int id,const char * name , const char * surname){
        Customer* customer=this->headC;
        while(customer)
        {
            if((id==customer->rID())&&(strcmp (name, customer->rname())==0)&&(strcmp (surname, customer->rsurname())==0))
            return true;
            else{
                customer= customer->refNext();
            }
        }
        return false;
    }

    bool Pharmacy_Chain::pharmacypresent(int id,const char * name , const char * town){
        Pharmacy* Pharmacy=this->headP;
        while(Pharmacy)
        {
            if((id==Pharmacy->rID())&&(strcmp (name, Pharmacy->rname())==0)&&(strcmp (town, Pharmacy->rtown())==0))
            return true;
            else{
                Pharmacy= Pharmacy->refNext();
            }
        }
        return false;
    }

    bool Pharmacy_Chain::medicinepresent(int idpharmacy, int id, const char * name , const char * type,int amount,int precond){
        Pharmacy* pharmacy=this->headP;
        if(idpharmacy<0)
        {
            return false;
        }

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                if(pharmacy->medicinepresent(id,name,type,amount,precond)==1)
                return true;
                break;
            }
            pharmacy= pharmacy->refNext();
        }
        return false;
    }
    bool Pharmacy_Chain::employeepresent(int idpharmacy, int id, const char * name , const char * surname){
        Pharmacy* pharmacy=this->headP;
        if(idpharmacy<0)
        {
            return false;
        }

        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                if(pharmacy->employeepresent(id,name,surname))
                return true;
                break;
            }
            pharmacy= pharmacy->refNext();
        }

    return false;
    }

    int Pharmacy_Chain::number_of_Medicines(int idpharmacy){
        Pharmacy* pharmacy=this->headP;
        if(idpharmacy<0)
        {
            return 0;
        }
        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                
                return pharmacy->amount_of_Medicines();
                break;
            }
            pharmacy= pharmacy->refNext();
        }

    return 0;
    }
    int Pharmacy_Chain::number_of_Employees(int idpharmacy){
        Pharmacy* pharmacy=this->headP;
        if(idpharmacy<0)
        {
            return 0;
        }
        while(pharmacy)
        {
            if(idpharmacy==pharmacy->rID())
            {
                
                return pharmacy->amount_of_Employees();
                
            }
            pharmacy= pharmacy->refNext();
        }

    return 0;
    }