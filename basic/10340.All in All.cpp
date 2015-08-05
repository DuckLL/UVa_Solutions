/*
You have devised a new encryption technique which encodes a message by inserting between its characters randomly generated strings in a clever way. Because of pending patent issues we will not discuss in detail how the strings are generated and inserted into the original message. To validate your method, however, it is necessary to write a program that checks if the message is really encoded in the final string.

Given two strings s and t, you have to decide whether s is a subsequence of t, i.e. if you can remove characters from t such that the concatenation of the remaining characters is s.

Input Specification

The input contains several testcases. Each is specified by two strings s, t of alphanumeric ASCII characters separated by whitespace. Input is terminated by EOF.

Output Specification

For each test case output, if s is a subsequence of t.

Sample Input

sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
Sample Output

Yes
No
Yes
No
*/
#include <iostream>
using namespace std;
int main()
{
    int s1n,now,num;
    int i,j;
    string str1,str2;
    while(cin>>str1)
    {
        cin>>str2;
        now=0;
        num=0;
        s1n=str1.size();
        for(i=0;i<s1n;i++)
            for(j=now;j<str2.size();j++)
                if(str1[i]==str2[j])
                {
                    now=j+1;
                    num++;
                    break;
                }
        if(num==s1n)
            cout<<"Yes";
        else
            cout<<"No";
        cout<<endl;
    }
    return 0;
}
