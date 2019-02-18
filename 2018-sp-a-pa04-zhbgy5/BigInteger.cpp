#include <iostream>
#include <exception>
#include <string>
#include "BigInteger.h"
using std::exception;
using std::cout;
using std::endl;
using std::cin;

BigInteger::BigInteger()
{
    isNegative = false;
}
BigInteger::BigInteger(std::string really_big_number)
{
    int j;
    if (really_big_number[0] == '-')
    {
        really_big_number.erase(0,1);
        isNegative = true;
    }
    else
    {
        isNegative = false;
    }
    for(int i = 0; i<really_big_number.size();i++)
    {
        j = (really_big_number[i]-'0');
        if(j<0 || j>9)
        {
            throw BigIntException();
        }
        digit_vector.push_back(j);
    }
}
std::string BigInteger::to_string()
{
    char c;
    std::string s;
    for(int i=0;i<digit_vector.size();i++)
    {
        c=digit_vector[i]+'0';
        s=s+c;
    }
    if(isNegative == true)
    {
        c= '-';
        s=c+s;
    }
    return s;
}

BigInteger operator+(BigInteger &bi1, BigInteger &bi2)
{
    std::string s1 =bi1.to_string(),s2= bi2.to_string(),s3;
    char c;
    if(s1[0] == '-' && s2[0] == '-')
    {
        s1.erase(0,1);
        s2.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T1 + T2;
        s1=T3.to_string();
        c = '-';
        s1 = c+s1;
        BigInteger T4(s1);
        return T4;
    }
    if(s2[0] == '-')
    {
        s2.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T1 - T2;
        s1=T3.to_string();
        BigInteger T4(s1);
        return T4;
    }
    if(s1[0] == '-')
    {
        s1.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T2 - T1;
        s1=T3.to_string();
        BigInteger T4(s1);
        return T4;
    }
    int j,k,q = 0;
    s3.clear();
    if(s1.size()>=s2.size())
    {
        for(int i=1;i<s2.size()+1;i++)
        {
            j = s1[s1.size()-i] - '0';
            k = s2[s2.size()-i] - '0';
            j = j + k + q;
            if(j>9)
            {
                j = j - 10;
                q = 1;
            }
            else
            {
                q = 0;
            }
            c = j + '0';
            s3=c+s3;
        }
        k = s2.size()+1;
        while(q == 1)
        {
            if(k>s1.size())
            {
                c= 1 + '0';
                s3=c+s3;
                BigInteger T(s3);
                return T;
            }
            j = s1[s1.size()-k] - '0';
            j = j + q;
            if(j>9)
            {
                j = j - 10;
                q = 1;
            }
            else
            {
                q = 0;
            }
            c = j + '0';
            s3=c+s3;
            k++;
        }
        BigInteger T(s3);
        return T;
    }
    else
    {
        for(int i=1;i<s1.size()+1;i++)
        {
            j = s1[s1.size()-i] - '0';
            k = s2[s2.size()-i] - '0';
            j = j + k + q;
            if(j>9)
            {
                j = j - 10;
                q = 1;
            }
            else
            {
                q = 0;
            }
            c = j + '0';
            s3=c+s3;
        }
        k = s1.size()+1;
        while(q == 1)
        {
            if(k>s2.size())
            {
                c= 1 + '0';
                s3=c+s3;
                BigInteger T(s3);
                return T;
            }
            j = s2[s2.size()-k] - '0';
            j = j + q;
            if(j>9)
            {
                j = j - 10;
                q = 1;
            }
            else
            {
                q = 0;
            }
            c = j + '0';
            s3=c+s3;
            k++;
        }
        BigInteger T(s3);
        return T;
    }
}

BigInteger operator-(BigInteger &bi1, BigInteger &bi2)
{
    std::string s1 = bi1.to_string();
    std::string s2 = bi2.to_string();
    std::string s3;
    char tempAscii;
    if(s1[0] == '-' && s2[0] == '-')
    {
        s2.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T1 + T2;
        s1=T3.to_string();
        BigInteger T4(s1);
        return T4;
    }
    if(s2[0] == '-')
    {
        s2.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T1 + T2;
        s1=T3.to_string();
        BigInteger T4(s1);
        return T4;
    }
    if(s1[0] == '-')
    {
        s1.erase(0,1);
        BigInteger T1(s1), T2(s2);
        BigInteger T3 = T2 + T1;
        s1=T3.to_string();
        tempAscii = '-';
        s1 = tempAscii+s1;
        BigInteger T4(s1);
        return T4;
    }
    int top, bottom, carry = 0;
    s3.clear();
    if(s1.size()>=s2.size())
    {
        for(int i=1;i<s2.size()+1;i++)
        {
            top = s1[s1.size()-i] - '0';
            bottom = s2[s2.size()-i] - '0';
            top = top - bottom - carry;
            if(top<0)
            {
                if(i==s1.size())
                {
                     top = top * -1;
                     tempAscii = top + '0';
                     s3 = tempAscii+s3;
                     tempAscii = '-';
                     s3 = tempAscii+s3;
                     BigInteger T(s3);
                     return T;
                }
                top = top + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            tempAscii = top + '0';
            s3=tempAscii+s3;
        }
        bottom = s2.size()+1;
        while(carry == 1)
        {
            if(bottom>s1.size())
            {
                bottom = 0;
                do
                {
                top = s3[0] - '0';
                if(top == 0)
                {
                    s3.erase(0,1);
                }
                }while(top==0);
                BigInteger T(s3);
                return T;
            }
            top = s1[s1.size()-bottom] - '0';
            top = top - carry;
            if(top<0)
            {
                top = top + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            tempAscii = top + '0';
            s3=tempAscii+s3;
            bottom++;
        }
        do
        {
        top = s3[0] - '0';
        if(top == 0 && s3.size() != 1)
        {
            s3.erase(0,1);
        }
        }while(top==0 && s3.size() != 1);
        BigInteger T(s3);
        return T;
    }
    else
    {
        s3=s1;
        s1=s2;
        s2=s3;
        s3.clear();
        for(int i=1;i<s2.size()+1;i++)
        {
            top = s1[s1.size()-i] - '0';
            bottom = s2[s2.size()-i] - '0';
            top = top - bottom - carry;
            if(top<0)
            {
                top = top + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            tempAscii = top + '0';
            s3=tempAscii+s3;
        }
        bottom = s2.size()+1;
        while(carry == 1)
        {
            if(bottom>s1.size())
            {
                bottom = 0;
                do
                {
                top = s3[0] - '0';
                if(top == 0)
                {
                    s3.erase(0,1);
                }
                }while(top==0);
                tempAscii = '-';
                s3=tempAscii + s3;
                BigInteger T(s3);
                return T;
            }
            top = s1[s1.size()-bottom] - '0';
            top = top - carry;
            if(top<0)
            {
                top = top + 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            tempAscii = top + '0';
            s3=tempAscii+s3;
            bottom++;
        }
        do
        {
        top = s3[0] - '0';
        if(top == 0)
        {
            s3.erase(0,1);
        }
        }while(top==0);
        tempAscii = '-';
        s3=tempAscii + s3;
        BigInteger T(s3);
        return T;
    }
}
