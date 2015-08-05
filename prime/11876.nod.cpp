#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
bool isprime(int x);
int nod(int x);
int main(){
    ifstream fin("11876.txt");
    istream &ins(fin);
    int i;
    //prime table
    prime.push_back(2);
    for(i=3;i<sqrt(1000000)+1;i++)
        if(isprime(i))
            prime.push_back(i);
    //list table
    vector<int> list;
    list.push_back(1);
    for(i=1;list[i-1]<1000001;i++)
        list.push_back(list[i-1]+nod(list[i-1]));
    int n;
    int a,b;
    int start,end;
    ins>>n;
    for(i=0;i<n;i++){
        ins>>a>>b;
        start=0;
        while(a>list[start])
            start++;
        end=list.size()-1;
        while(b<list[end])
            end--;
        cout<<"Case "<<i+1<<": "<<end-start+1<<endl;
    }
    return 0;
}
bool isprime(int x){
    if(x<2)
        return 0;
    for(int i=0;i<prime.size()&&sqrt(x)>=prime[i];i++)
        if(x%prime[i]==0)
            return 0;
    return 1;
}
int nod(int x){
    if(x<2)
        return 1;
    if(isprime(x))
        return 2;
    int sum=1;
    int i=0;
    while(x>1){
        int tmp=0;
        while(x%prime[i]==0){
            tmp++;
            x/=prime[i];
        }
        sum*=tmp+1;
        if(isprime(x))
            return sum*2;
        i++;
    }
    return sum;
}
