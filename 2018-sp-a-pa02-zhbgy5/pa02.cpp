/**
main
====

Solve the main input and output here.
Within the main loop of your program, you must use the same polymorphic pointer to an Operating_system to manage multiple objects of type Cluster and Personal_surveillance_device.
Do not reference the objects directly.
Note: only a small fraction of your cpp implementations are tested in main.
**/

#include "managing_hierarchies.h"
#include "Android.h"
#include <iostream>
#include <exception>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::exception;
int main()
{
    string choice = "1";
    int i;
    long j;
    while(choice != "0"){
    cout<<"\nWhat devices do you need to manage (choose one or enter 0 to exit): phone, cluster";
    cin>>choice;
    if(choice == "cluster")
    {
        Operating_system *p = new Cluster;
        Cluster* p2 = dynamic_cast<Cluster*>(p);
        p2->get_func_purpose();
        cout<<"\nWhat is the version number of your operating system?";
        cin>>i;
        p2->set_version_number(i);
        p2->get_version_number();
        delete p2;
    }
    if(choice == "phone")
    {
        Operating_system *p = new Personal_surveillance_device;
        Personal_surveillance_device* p2 = dynamic_cast<Personal_surveillance_device*>(p);
        cout<<"\nWhat is your IMEI?";
        cin>>j;
        Personal_surveillance_device A(j);
        p2->get_func_purpose();
        cout<<"\nWhat is the version number of your operating system?";
        cin>> i;
        p2->set_version_number(i);
        p2->get_version_number();
        cout<<"\nWhat is your phone number?";
        i=0;
        cin.ignore();
        while(i==0){
        try{
        getline(cin,choice);

        p2->set_phone_number(choice);
        i=1;
        }
        catch(const MyException &e){cout<<"\nThat was not a valid phone number, please try again.";}
        }
        p2->get_phone_number();
        cout<<"\nWould you like to encrypt your phone (type yes or no)?";
        cin>>choice;
        if (choice == "yes"){p2->set_pretend_encryption();}
        delete p2;
    }
    cout<<"\n";
    }
    cout<<"Exiting now"<<endl;;
    return 0;
}
