#include <iostream>
#include <string>
#include <cstring>
#include "pharmacy.h"
#include "customer.h"
using namespace std;

class Pharmacy_Chain
{
    Pharmacy * headP;
    Customer * headC;
public:
    Pharmacy_Chain();  //Constructor
    ~Pharmacy_Chain(); //Destructor
    bool add_Customer(int id, const char * name , const char * surname, int prescription); //
    //Adds customer to a list
    void remove_Customer(const char * name); //
    //Deletes customer from a list
    bool add_Pharmacy(int id, const char * name , const char * town); //
    //Adds pharmacy to a list
    void remove_Pharmacy(const char * name); //
    //Deletes pharmacy from a list
    int number_of_Customers();  //
    //Return number of all customers 
    int number_of_Pharmacies(); //
    //Return number of all pharmacies
    int number_of_Pharmacies_in_same_town(const char * name); //
    //Return number of all pharmacies located in the same town
    int give_alternative_to_prescripted_medicine(int customerID,int pharmacyID);//
    //Give non prescripted alternative 
    bool transfer_medicine_to_another_pharmacy(int idmedicine, int idpharmacyto,int pharmacyfrom);
    //Move medicine from one pharmacy to another
    int amount_of_1Customer(const char * name); //
    //Return number of all customers of given name
    int amount_of_1Pharmacy(const char * name); //
    //Return number of all pharmacies of given name
    bool add_Medicine(int idpharmacy,int id, const char * name , const char * type,int amount,int precond);//
    bool add_Employee(int idpharmacy,int id, const char * name , const char * surname); //
    void printPC();
    bool changeamount_Medicine(int idpharmacy,int amount,int id); //
    bool changeprescription_Medicine(int idpharmacy,int idmedicine);  //
    bool customerpresent(int id,const char * name , const char * surname);//
    bool pharmacypresent(int id,const char * name , const char * town);//
    bool medicinepresent(int idpharmacy, int id, const char * name , const char * type,int amount,int precond);//
    bool employeepresent(int idpharmacy, int id, const char * name , const char * surname);//
    int number_of_Medicines(int idpharmacy); //
    int number_of_Employees(int idpharmacy); //

};
