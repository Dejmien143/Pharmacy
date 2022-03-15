#include <iostream>
#include <string>
#include <cstring>
#include "pharmacy_chain.h"
using namespace std;

int main(){
    ///Test 1 include testing on customers
{//Test1.1 Adding customer to an empty list
Pharmacy_Chain first;
first.add_Customer(2,"Damian","Kowalczyk",0);
if(first.number_of_Customers()==1)
cout<<"Test 1.1 success"<<endl;
else
cout<<"Test 1.1 failed"<<endl;
}

{//Test1.2 Not adding a customer if he have the same ID
Pharmacy_Chain first;
first.add_Customer(2,"Damian","Kowalczyk",0);
first.add_Customer(2,"Jan","Kowalski",0);
if(first.number_of_Customers()==1)
cout<<"Test 1.2 success"<<endl;
else
cout<<"Test 1.2 failed"<<endl;
}

{//Test1.3 adding many customers 
Pharmacy_Chain first;
first.add_Customer(2,"Damian","Kowalczyk",0);
first.add_Customer(5,"Jan","Kowalski",0);
first.add_Customer(7,"Janek","Kowalskiw",1);
if(first.number_of_Customers()==3)
cout<<"Test 1.3 success"<<endl;
else
cout<<"Test 1.3 failed"<<endl;
}

{//Test1.4 A customer exist 
Pharmacy_Chain first;
first.add_Customer(7,"Janek","Kowalskiw",1);
if(first.customerpresent(7,"Janek","Kowalskiw")==1)
cout<<"Test 1.4 success"<<endl;
else
cout<<"Test 1.4 failed"<<endl;
}
{//Test1.5 A customer does not exist if was NOT added to the list
Pharmacy_Chain first;
first.add_Customer(2,"Damian","Kowalczyk",0);
first.add_Customer(5,"Jan","Kowalski",0);
if(first.customerpresent(7,"Janek","Kowalskiw")==0)
cout<<"Test 1.5 success"<<endl;
else
cout<<"Test 1.5 failed"<<endl;
}

{//Test1.6 A customer does not belong to an empty list
Pharmacy_Chain first;
if(first.customerpresent(7,"Janek","Kowalskiw")==0)
cout<<"Test 1.6 success"<<endl;
else
cout<<"Test 1.6 failed"<<endl;
}

////////////Test 2 include testing on pharmacies

{//Test2.1 Adding pharmacy to an empty list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
if(first.number_of_Pharmacies()==1)
cout<<"Test 2.1 success"<<endl;
else
cout<<"Test 2.1 failed"<<endl;
}

{//Test2.2 Not adding a pharmacy if it has the same ID
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Pharmacy(2,"Herkules","Boat");
if(first.number_of_Pharmacies()==1)
cout<<"Test 2.2 success"<<endl;
else
cout<<"Test 2.2 failed"<<endl;
}

{//Test2.3 adding many pharmacies
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Pharmacy(5,"Herkules","Boat");
first.add_Pharmacy(4,"Zeus","Warsaw");
first.add_Pharmacy(3,"Medusa","Boat");
if(first.number_of_Pharmacies()==4)
cout<<"Test 2.3 success"<<endl;
else
cout<<"Test 2.3 failed"<<endl;
}

{//Test2.4 A pharmacy exist 
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
if(first.pharmacypresent(2,"Sokrates","Warsaw")==1)
cout<<"Test 2.4 success"<<endl;
else
cout<<"Test 2.4 failed"<<endl;
}
{//Test2.5 A pharmacy does not exist if was NOT added to the list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Pharmacy(5,"Herkules","Boat");
first.add_Pharmacy(4,"Zeus","Warsaw");
if(first.pharmacypresent(3,"Medusa","Boat")==0)
cout<<"Test 2.5 success"<<endl;
else
cout<<"Test 2.5 failed"<<endl;
}

{//Test2.6 A pharmacy does not belong to an empty list
Pharmacy_Chain first;
if(first.pharmacypresent(3,"Medusa","Boat")==0)
cout<<"Test 2.6 success"<<endl;
else
cout<<"Test 2.6 failed"<<endl;
}

///////////Test 3 include testing on medicines

{//Test3.1 Adding medicine to an empty list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
if(first.medicinepresent(2,1,"Apap","Painkiller",1000,0)==1)
{cout<<"Test 3.1 success"<<endl;}
else{cout<<"Test 3.1 failed"<<endl;}

}

{//Test3.2 Not adding a medicine if he have the same ID
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
first.add_Medicine(2,1,"Ibuprom","Painkiller",500,0);
if(first.number_of_Medicines(2)==1)
cout<<"Test 3.2 success"<<endl;
else
cout<<"Test 3.2 failed"<<endl;
}

{//Test3.3 adding many medicines
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
first.add_Medicine(2,2,"Ibuprom","Painkiller",500,0);
first.add_Medicine(2,3,"Nurofen","Painkiller",1000,0);
first.add_Medicine(2,4,"Ibum","Painkiller",500,0);
if(first.number_of_Medicines(2)==4)
cout<<"Test 3.3 success"<<endl;
else
cout<<"Test 3.3 failed"<<endl;
}

{//Test3.4 A medicine exist 
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
first.add_Medicine(2,2,"Ibuprom","Painkiller",500,0);
first.add_Medicine(2,3,"Nurofen","Painkiller",1000,0);
first.add_Medicine(2,4,"Ibum","Painkiller",500,0);
if(first.medicinepresent(2,4,"Ibum","Painkiller",500,0)==1)
cout<<"Test 3.4 success"<<endl;
else
cout<<"Test 3.4 failed"<<endl;
}
{//Test3.5 A medicine does not exist if was NOT added to the list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
first.add_Medicine(2,2,"Ibuprom","Painkiller",500,0);
first.add_Medicine(2,3,"Nurofen","Painkiller",1000,0);
if(first.medicinepresent(2,4,"Ibum","Painkiller",500,0)==0)
cout<<"Test 3.5 success"<<endl;
else
cout<<"Test 3.5 failed"<<endl;
}

{//Test3.6 A medicine does not belong to an empty list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
if(first.medicinepresent(2,4,"Ibum","Painkiller",500,0)==0)
cout<<"Test 3.6 success"<<endl;
else
cout<<"Test 3.6 failed"<<endl;
}

///////////Test 4 include testing on employees

{//Test4.1 Adding Employee to an empty list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
if(first.employeepresent(2,1,"Damian","Kowalczyk")==1)
{cout<<"Test 4.1 success"<<endl;}
else{cout<<"Test 4.1 failed"<<endl;}

}

{//Test4.2 Not adding a Employee if he have the same ID
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
first.add_Employee(2,1,"Jan","Kowal");
if(first.number_of_Employees(2)==1)
cout<<"Test 4.2 success"<<endl;
else
cout<<"Test 4.2 failed"<<endl;
}

{//Test4.3 adding many Employees
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
first.add_Employee(2,2,"Jan","Kowal");
first.add_Employee(2,3,"John","Smith");
first.add_Employee(2,4,"Agnieszka","Niemieszka");
if(first.number_of_Employees(2)==4)
cout<<"Test 4.3 success"<<endl;
else
cout<<"Test 4.3 failed"<<endl;
}

{//Test4.4 A Employee exist 
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
first.add_Employee(2,2,"Jan","Kowal");
first.add_Employee(2,3,"John","Smith");
first.add_Employee(2,4,"Agnieszka","Niemieszka");
if(first.employeepresent(2,4,"Agnieszka","Niemieszka")==1)
cout<<"Test 4.4 success"<<endl;
else
cout<<"Test 4.4 failed"<<endl;
}
{//Test4.5 A Employee does not exist if was NOT added to the list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
first.add_Employee(2,2,"Jan","Kowal");
first.add_Employee(2,3,"John","Smith");
if(first.employeepresent(2,4,"Agnieszka","Niemieszka")==0)
cout<<"Test 4.5 success"<<endl;
else
cout<<"Test 4.5 failed"<<endl;
}

{//Test4.6 A Employee does not belong to an empty list
Pharmacy_Chain first;
first.add_Pharmacy(2,"Sokrates","Warsaw");
if(first.medicinepresent(2,4,"Ibum","Painkiller",500,0)==0)
cout<<"Test 4.6 success"<<endl;
else
cout<<"Test 4.6 failed"<<endl;
}

/////Test 5 Printing all data
{//Test5.1 Adding customer to an empty list
Pharmacy_Chain first;

first.add_Customer(2,"Damian","Kowalczyk",0);
first.add_Pharmacy(2,"Sokrates","Warsaw");
first.add_Employee(2,1,"Damian","Kowalczyk");
first.add_Medicine(2,1,"Apap","Painkiller",1000,0);
first.printPC();
}
}
