/*
You are given a string consisting of parentheses () and []. A string of this type is said to be correct:

(a)
if it is the empty string
(b)
if A and B are correct, AB is correct,
(c)
if A is correct, (A) and [A] is correct.
Write a program that takes a sequence of strings of this type and check their correctness. Your program can assume that the maximum string length is 128.

Input

The file contains a positive integer n and a sequence of n strings of parentheses () and [], one string a line.
Output

A sequence of Yes or No on the output file.
Sample Input

3
([])
(([()])))
([()[]()])()
Sample Output

Yes
No
Yes
*/
#include <iostream>
using namespace std;
int main()
{
    bool b;
    char c;
    int n,index;
    int i;
    cin>>n;
    cin.get(c);
    for(i=0;i<n;i++)
    {
        b=true;
        char str[1000]={' '};
        index=0;
        while(cin.get(c)&&c!=10)
        {
            if(c=='(')
            {
                str[index]='(';
                index++;
            }
            else if(c=='[')
            {
                str[index]='[';
                index++;
            }
            else if(c==')')
                if(index-1>-1&&str[index-1]=='(')
                   index--;
                else
                    b=false;
            else if(c==']')
                if(index-1>-1&&str[index-1]=='[')
                   index--;
                else
                    b=false;
            else
                b=false;
        }
        if(index!=0)
            b=false;
        if(b)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }
    return 0;
}
