/*
Problem B
Rare Easy Problem
Input: Standard Input
Output: Standard Output
Time Limit: 1 Second

N is a random number, which for some reason, is at least two digits.  John Doe, a nondescript man, performs an operation on N: he chops off the last digit to form a new number M, and then finds N-M.  This excites him in a hard-to-justify way.  He then tells you N-M.  Thrilled by the fascinating back-story behind this number, you make it your life goal to figure out what N was.

By the way, John was later eaten by a tiger.

Input
Input consists of multiple lines, one line per case.  Each line contains a single positive integer between 10 and 10^18 inclusive, giving the value of N-M.  Input is terminated by a line containing 0.

Output
For each case, print one line containing the possible values of N in sorted order.  Separate consecutive numbers with a single space.

Sample Input                             Output for Sample Input
18                                         19 20
0

*/
#include <iostream>
using namespace std;
int main()
{
    int x,count;
    int i,j;
    while(cin>>x&&x!=0)
    {
        count=0;
        for(i=9;i>-1;i--)
            if((x-i)%9==0)
            {
                if(count>0)
                    cout<<" ";
                cout<<(x-i)/9<<i;
                count++;
            }
        cout<<endl;
    }
    return 0;
}
