#include <iostream>
#include <algorithm>
#include<thread>
#include<mutex>

using namespace std;
/*
to print the odd and even numbers between the range 1 to 20 using threads
the thread t1 prints the even numbers
the thread t2 prints the odd numbers
creating mutex to provide synchronization for two threads
the critical section is printing the numbers so locking that section and unlocking it after printing
*/
mutex m;
void display_num(int odd_even)
{
    //critical section
    //locking the section
    m.lock();
    cout<<"Printing the numbers in the given range: "<<endl;
    int i;
    if(odd_even == 0)
    {
        cout<<"Even Numbers: (in the range 1 to 20)"<<endl;
        for(i=1;i<=20;i++)
        {
            if(i % 2 == 0)
                cout<<i<<endl;
        }
    }
    else if(odd_even == 1)
    {
        cout<<"Odd Numbers: (in the range 1 to 20)"<<endl;
        for(i=1;i<=20;i++)
        {
            if(i % 2 != 0)
                cout<<i<<endl;
        }
    }
    m.unlock();
    //unlocking the section
}


int main()
{
    //create two threads
    // if the value sent in thread is 0 then it prints the even numbers
    // and if it is 1 then it prints odd numbers in the range

    thread t1(display_num,0);
    thread t2(display_num,1);


    t1.join();
    t2.join();

    return 0;
}
