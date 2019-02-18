/* Sample tester
 * We've included std::list below to show you how your types should behave.
 * You can use that for debugging.
 * As in the assignment description, if you use the std::list for your submitted code,
 * you will get a 0.
 * Compile with g++ pa05.cpp BigInteger.cpp -std=c++11
 * Add the -g flag if you want to use GDB like we learned in lab this week.
 */

// USE THIS TO TEST, BUT REMOVE LATER
#include <list>

#include "BigInteger.h"
#include "MyList.h"

int main()
{
    // Make your hpp file with empty definitions other than your constructor
    // Build one function at a time, and only add one "test" line at a time to this file.
    MyList<int> l;
    //std::list<int> l;

    // Uncommend and add lines below here 1 at a time!
    // Test all your MyList functions here:
 //   cout << l.size() << endl;
    l.clear();
        l.clear();

    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);
    l.push_back(4000);
    l.push_back(200);
    l.push_back(100);

 //   cout << l.size() << endl;
 //   cout << l.front() << endl;
 //   cout << l.back() << endl;

    l.push_front(423);

 //   cout << l.front() << endl;
 //   cout << l.size() << endl;

    MyList<int> sink;
    sink = l;
 //   cout << sink.front() << endl;
  //  cout << sink.back() << endl;
  //  cout << sink.size() << endl;


    l.insert(l.begin(), 3);
    l.insert(l.end(), 20);
   // cout << l.front() << endl;
    //cout << l.back() << endl;
    //cout << l.size() << endl;
    l.pop_back();
    //cout << l.front() << endl;
    //cout << l.back() << endl;
    //cout << l.size() << endl;

    l.reverse();
    l.clear();
    //l.assign(5,4);
    cout<<"who"<<endl;
    l.push_front(6);
    l.push_front(6);
    l.push_front(6);
    l.push_front(6);
    l.push_front(6);
    l.push_front(6);l.push_front(6);
    l.push_front(6);
    l.push_front(6);
    //l.push_front(6);
    //l.push_back(6);
    //l.push_back(6);
    cout <<"why?"<<l.size() << endl;
    //l.remove(4);
    cout << l.size() << endl;
    /*for(auto i = 0; i < 5; i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }
    l.remove(5);
    int j = 0;
    cout<<l.size()<<endl;
    /*for(auto i = 0; i < 5; i++)
    {
        cout << l.back() << endl;
        l.pop_back();
        j++;
    }
    /*
    // Test all your BigInteger functions here:

    std::string init_string("2342323492423");

    BigInteger my_big_int(init_string);

    */

    return 0;
}

