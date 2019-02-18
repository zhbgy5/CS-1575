#include "maze.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;


void get_identity(string my_id[])
{
    my_id[0]="zhbgy5";
    my_id[1]="12350273";
}


string * build_matrix(int rows)
{
    string* matrix = new string[rows];
    return matrix;
}


void fill_matrix(string *matrix, int rows)
{
    cin.ignore(256,'\n');
    for(int i=0;i<rows;i++)
    {
        getline(cin,matrix[i]);
    }
}


void print_matrix(string *matrix, int rows)
{
    for (int i=0;i<rows;i++)
        {
            cout<<matrix[i]<<endl;
        }
        cout<<endl;
}


void delete_matrix(string *matrix, int rows)
{
    delete[] matrix;
    matrix = NULL;
}


void find_start(string *matrix, int rows, int &x, int &y)
{
    for(int i=0;i<rows;i++)
    {
        string s1=matrix[i];
        int l= int (s1.length());
        for(int j=0;j<l;j++)
        {
            if(s1.at(j)=='N')
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}

bool find_exit(string *matrix, int x, int y)
{
    if(at_end(matrix,x,y))
    {
        return true;
    }
    if(valid_move(matrix,x,y,SOUTH))
    {
    if(matrix[x][y] != 'N'){matrix[x][y]='@';}
     if(find_exit(matrix,x+1,y))
     {
         return true;
     }
     if(matrix[x][y] != 'N'){matrix[x][y]=' ';}
    }
    if(valid_move(matrix,x,y,NORTH))
    {
    if(matrix[x][y] != 'N'){matrix[x][y]='@';}
     if(find_exit(matrix,x-1,y))
     {
         return true;
     }
     if(matrix[x][y] != 'N'){matrix[x][y]=' ';}
    }
    if(valid_move(matrix,x,y,WEST))
    {
     if(matrix[x][y] != 'N'){matrix[x][y]='@';}
     if(find_exit(matrix,x,y-1))
     {
         return true;
     }
     if(matrix[x][y] != 'N'){matrix[x][y]=' ';}
    }
    if(valid_move(matrix,x,y,EAST))
    {
     if(matrix[x][y] != 'N'){matrix[x][y]='@';}
     if(find_exit(matrix,x,y+1))
     {
         return true;
     }
     if(matrix[x][y] != 'N'){matrix[x][y]=' ';}
    }
    return false;
}


bool at_end(string *matrix, int x, int y)
{
    if(matrix[x][y]=='E')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool valid_move(string *matrix, int x, int y, direction d)
{
    if(d == NORTH)
    {
        if(matrix[x-1][y]=='E' || matrix[x-1][y]==' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(d == SOUTH)
    {
        if(matrix[x+1][y]=='E' || matrix[x+1][y]==' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(d == EAST)
    {
        if(matrix[x][y+1]=='E' || matrix[x][y+1]==' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if(d == WEST)
    {
        if(matrix[x][y-1]=='E' || matrix[x][y-1]==' ')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else return false;

}

