#include "maze.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main()
{
    int x =1,y=1,j,k,i=0;
    string* pMaze;
    while(x >0 || y>0)
    {
        cin>>x>>y;
        if(x <=0 || y<=0)
            break;
        pMaze = build_matrix(x);
        fill_matrix(pMaze,x);
        find_start(pMaze,x,j,k);
        cout<<"Map "<<i<<" -- ";
        if(find_exit(pMaze,j,k))
        {
            cout<<"Solution found:"<<endl;
        }
        else
        {
            cout<<"No solution found:"<<endl;
        }
        print_matrix(pMaze,x);
        delete_matrix(pMaze,x);
        i++;
    }
    return 0;
}

