/*
The Problem
 The "reverse and add" method is simple: choose a number, reverse its digits and add it to the original. If the sum is not a palindrome (which means, it is not the same number from left to right and right to left), repeat this procedure.
 For example:
195 Initial number
591
-----
786
687
-----
1473
3741
-----
5214
4125
-----
9339 Resulting palindrome

In this particular case the palindrome 9339 appeared after the 4th addition. This method leads to palindromes in a few step for almost all of the integers. But there are interesting exceptions. 196 is the first number for which no palindrome has been found. It is not proven though, that there is no such a palindrome.

Task :
You must write a program that give the resulting palindrome and the number of iterations (additions) to compute the palindrome.

You might assume that all tests data on this problem:
- will have an answer ,
- will be computable with less than 1000 iterations (additions),
- will yield a palindrome that is not greater than 4,294,967,295.


The Input
 The first line will have a number N with the number of test cases, the next N lines will have a number P to compute its palindrome.
 The Output
 For each of the N tests you will have to write a line with the following data : minimum number of iterations (additions) to get to the palindrome and the resulting palindrome itself separated by one space.
 Sample Input
3
195
265
750

 Sample Output
 4 9339
5 45254
3 6666
*/
#include <iostream>
using namespace std;
int main()
{
    bool b,tmp;
    int n,dig,ll,count;
    int i,j;
    string x;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>x;
        count=0;
        b=true;
        while(b)
        {
            count++;
            ll=x.size();
            int org[100]={0},rvs[100]={0},sum[100]={0};
            for(j=0;j<ll;j++)
            {
                org[j]=x[j]-48;
                rvs[j]=x[ll-j-1]-48;
            }
            for(j=0;j<ll;j++)
            {
                sum[j]+=org[j]+rvs[j];
                if(sum[j]>9)
                {
                    sum[j]%=10;
                    sum[j+1]++;
                    if(j==ll-1)
                        ll++;
                }
            }
            tmp=true;
            for(j=0;j<ll/2;j++)
                if(sum[j]!=sum[ll-1-j])
                    tmp=false;
            if(tmp)
                b=false;
            x="";
            for(j=0;j<ll;j++)
                x+=sum[j]+48;
        }
        cout<<count<<" "<<x<<endl;
    }
    return 0;
}
