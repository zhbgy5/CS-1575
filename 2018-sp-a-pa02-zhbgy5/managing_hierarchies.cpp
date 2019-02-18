/**
.cpp
====

This is the .cpp you should define and implement the functions and classes that are declared in the .h file.
Add any non-required functions here.
**/

#include "managing_hierarchies.h"
#include "Android.h"
#include <iostream>
#include <exception>
#include <string> // optional with modern GCC installs
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::exception;

Android::Android(){purpose = "Uploading your converstations to google";pretend_encryption = 0;}
void Android::set_pretend_encryption(){
    if(pretend_encryption == 0)
    {
        cout<<"\nYour device is now securely encrypted";
        pretend_encryption = 1;
        return;
    }
    if(pretend_encryption == 1)
    {
        cout<<"\nEncryption is now off";
        pretend_encryption = 0;
        return;
    }
}

void get_identity(string my_id[])
{
    my_id[0]="zhbgy5";
    my_id[1]="12350273";
}

const char* MyException::what() const throw(){cout<<"Custom error has occured";}

// This is provided as an example of scoping and defining a class function
string Machine::get_function()
{
    cout << my_function;

    return my_function;
}

X86::X86(){my_function = "Backward compatibile";num_cores = new bool [2];}
X86::X86(string init_function,int init_cores)
{
    if(init_cores % 2 != 0){throw MyException();}
    my_function = init_function;
    num_cores = new bool [init_cores];
    return;
}
X86::~X86(){delete[] num_cores;num_cores = nullptr;}
void X86::set_core_pos(int position, bool value)
{
    num_cores[position] = value;
    return;
}
bool X86::get_core_pos(int index)
{
    return num_cores[index];
}

ARM::ARM(){my_function = "Reduced Instruction Set";num_bits = 64;}
ARM::ARM(string init_function,short init_bits)
{
    if(init_bits !=64 && init_bits !=32){throw MyException();}
    my_function = init_function;
    num_bits = init_bits;
    return;
}
void ARM::set_num_bits(short set_bits)
{
    num_bits = set_bits;
    return;
}
short ARM::get_num_bits()
{
    cout<<num_bits;
    return num_bits;
}

string Operating_system::get_purpose()
{
    cout<<purpose;
    return purpose;
}

Linux::Linux(){purpose= "Anything you want";}
Linux::Linux(string init_purpose)
{
    purpose = init_purpose;
    return;
}

string Cluster::get_func_purpose()
{
    string funpurp;
    string str1 = "\nYour cluster architecture is ";
    string str2 = ", its purpose is ";
    string str3 = ", and lots of it!";

    auto length = str1.length()+my_function.length()+str2.length()+purpose.length()+str3.length();
    funpurp.reserve(funpurp.length()+length);
    funpurp.append(str1).append(Cluster::my_function).append(str2).append(Cluster::purpose).append(str3);
    cout<<funpurp;
    return funpurp;
}
void Cluster::set_version_number(int set_ver_num)
{
    version_number = set_ver_num;
    return;
}
int Cluster::get_version_number()
{
    cout<<"\nYour OS version number is: "<<version_number;
    return version_number;
}

Personal_surveillance_device::Personal_surveillance_device(){my_IMEI = 0000;}
Personal_surveillance_device::Personal_surveillance_device(long input_my_IMEI)
{
    my_IMEI = &input_my_IMEI;
    return;
}
Personal_surveillance_device::Personal_surveillance_device(const Personal_surveillance_device& copyP){my_IMEI = new long(*copyP.my_IMEI);}
Personal_surveillance_device& Personal_surveillance_device::operator=(const Personal_surveillance_device& copyP){if(this == &copyP){return *this;}this->my_IMEI = new long(*copyP.my_IMEI);return *this;}
Personal_surveillance_device::~Personal_surveillance_device(){}
 string Personal_surveillance_device::get_func_purpose()
{
    string funpurp;
    string str1 = "\nYour phone architecture is ";
    string str2 = ", its purpose is ";
    string str3 = ", and it follows you around!";

    auto length = str1.length()+my_function.length()+str2.length()+purpose.length()+str3.length();
    funpurp.reserve(funpurp.length()+length);
    funpurp.append(str1).append(Personal_surveillance_device::my_function).append(str2).append(Personal_surveillance_device::purpose).append(str3);
    cout<<funpurp;
    return funpurp;
}
void Personal_surveillance_device::set_phone_number(string init_phone)
{
    //init_phone=removeSpaces(init_phone)
    int L=init_phone.length();
    if (L> 16){throw MyException();}
    int q=0;
    char p;
    for (int i=0;i<L;i++){
        p=init_phone.at(i);
        if(isdigit(p)){q++;}}
    if (q>11){throw MyException();}
    string s1,s2;
    s1 = init_phone.substr(0,3);
    s2 = init_phone.substr(6,2);
    if(s1 != "+1(" || s2 != ")-" || init_phone.at(11) != '-'){throw MyException();}
    my_phone_number = init_phone;
    return;
}
string Personal_surveillance_device::get_phone_number()
{
    cout<<"\nYour phone number is "<<my_phone_number;
    return my_phone_number;
}
void Personal_surveillance_device::set_version_number(int set_ver_number)
{
    version_number = set_ver_number;
    return;
}
int Personal_surveillance_device::get_version_number()
{
    cout<<"\nYour OS version number is: "<<version_number;
    return version_number;
}











