#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
bool isprime(int x);
int main(){
    ifstream fin("3399.txt");
    istream &ins(fin);
    //prime table
    prime.push_back(2);
    for(int i=3;i<10000;i++)
        if(isprime(i))
            prime.push_back(i);
    int x;
    while(ins>>x&&x){
        int ans=0;
        for(int i=0;i<prime.size();i++){
            int sum=0;
            for(int j=i;sum<x;j++)
                sum+=prime[j];
            if(sum==x)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
bool isprime(int x){
    if(x<2)
        return 0;
    for(int i=0;sqrt(x)>=prime[i];i++)
        if(x%prime[i]==0)
            return 0;
    return 1;
}
