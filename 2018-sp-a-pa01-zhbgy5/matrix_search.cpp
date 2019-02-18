//Programmer: Zachary Bible
//Class: CS 1575
//Instructor: Taylor
//File: PA01
#include "matrix_search.h"


void get_identity(string my_id[])
{
    my_id[0] = "zhbgy5";
    my_id[1] = "12350273";
}

char ** build_matrix(int rows, int cols)
{
    char **pArray = new char*[rows];
    for (int i=0;i<rows;i++){
        pArray[i] = new char[cols];
    }
    return pArray;
}


void fill_matrix(int rows, int cols, char **matrix)
{
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
        cin>>matrix[i][j];
        }
    }
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
    int check = 1;
    int l = int (word.length());
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            if(matrix[i][j] == word.at(0)){
                if(l==1){
                        sol[0] = i;
                        sol[1] = j;
                        sol[2] = i;
                        sol[3] = j;
                        return;
                }
                if((i-l+1)>-1 && (j-l+1)>-1 && i>0 && j>0){
                if(matrix[i-1][j-1] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i-q][j-q] == word.at(q)){
                        check++;
                        if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i-q;
                            sol[3] = j-q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((i-l+1)>-1 && i>0){
                if(matrix[i-1][j] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i-q][j] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i-q;
                            sol[3] = j;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((i-l+1)>-1 && (j+l)<(cols+1) && i>0){
                if(matrix[i-1][j+1] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i-q][j+q] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i-q;
                            sol[3] = j+q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((j-l+1)>-1 && j>0){
                if(matrix[i][j-1] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i][j-q] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i;
                            sol[3] = j-q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((j+l)<(cols+1)){
                if(matrix[i][j+1] == word.at(1)){
                        for(int q=1;q<l;q++){
                        if(matrix[i][j+q] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i;
                            sol[3] = j+q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((i+l)<(rows+1) && (j-l+1)>-1 && j>0){
                if(matrix[i+1][j-1] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i+q][j-q] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i+q;
                            sol[3] = j-q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((i+l)<(rows+1)){
                if(matrix[i+1][j] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i+q][j] == word.at(q)){
                        check++;
                        if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i+q;
                            sol[3] = j;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }}
                if((i+l)<(rows+1) && (j+l)<(cols+1)){
                if(matrix[i+1][j+1] == word.at(1)){
                    for(int q=1;q<l;q++){
                        if(matrix[i+q][j+q] == word.at(q)){
                            check++;
                            if(check == l){
                            sol[0] = i;
                            sol[1] = j;
                            sol[2] = i+q;
                            sol[3] = j+q;
                            return;
                            }
                        }
                        else{check=1;break;}
                    }
                }
            }}
        }
    }
}


void print_matrix(int rows, int cols, char **matrix)
{
    for (int i=0;i<rows;i++){
        for (int j=0;j<cols;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


void delete_matrix(int rows, char **matrix)
{
    for (int i=0;i<rows;i++){
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = NULL;
}
