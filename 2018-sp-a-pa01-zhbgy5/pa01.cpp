//Programmer: Zachary Bible
//Class: CS 1575
//Instructor: Taylor
//File: PA01
#include <iostream>
#include "matrix_search.h"
using namespace std;
int main()
{
    char **pArray;
    int iter,rows,cols,sol[4];
    string word;

    cin>>iter;
        for(int i=0;i<iter;i++){
            if(i>0){cout<<endl;}
            sol[0] = -1;
            sol[1] = -1;
            sol[2] = -1;
            sol[3] = -1;
            cin>>rows;
            cin>>cols;
            pArray = build_matrix(rows,cols);
            fill_matrix(rows,cols,pArray);
            cin.clear();
            cin.ignore();
            cin >> word;
            matrix_search(sol,word,rows,cols,pArray);
            //print_matrix(rows,cols,pArray);
            cout<<"Searching for \""<<word<<"\" in matrix "<<(i+1)<<" yields:"<<endl;
            if (sol[0]<0){
                cout<<"The pattern was not found."<<endl;
            }
            else
            cout<<"Start pos:("<<sol[0]<<", "<<sol[1]<<") to End pos:("<<sol[2]<<", "<<sol[3]<<")"<<endl;
            delete_matrix(rows,pArray);
        }
  return 0;
}
