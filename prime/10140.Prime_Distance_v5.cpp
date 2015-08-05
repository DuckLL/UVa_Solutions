#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
long int prime[4793];
int primen=0;
bool isprime(long long int x);
bool islive(long int x);
int main(){
	ifstream fin("10140.txt");
	istream& ins(fin);
	bool bb;
	int ansn;
	long int a,b,min,max,mina,minb,maxa,maxb,tmp;
	long long int i;
	long int ans[100000];
	prime[0]=2;
	for(i=3;i<46338;i++)
		if(isprime(i))
			prime[++primen]=i;
	while(ins>>a>>b){		
		ansn=0;
		for(i=a;i<=b;i++){
			if(i<46338)
				bb=islive(i);
			else
				bb=isprime(i);
			if(bb)
				ans[ansn++]=i;
		}			
		if(ansn<2)
			cout<<"There are no adjacent primes."<<endl;
		else{
			max=0;
			min=2e9;
			for(i=0;i<ansn-1;i++){
				tmp=ans[i+1]-ans[i];
				if(tmp>max){
					max=tmp;
					maxa=ans[i];
					maxb=ans[i+1];
				}
				if(min!=2&&tmp<min){
					min=tmp;
					mina=ans[i];
					minb=ans[i+1];
				}
			}
			cout<<mina<<","<<minb<<" are closest, "<<maxa<<","<<maxb<<" are most distant."<<endl;
		}			
	}
	return 0;
}
bool isprime(long long int x){
	int i,sqrtx;
	sqrtx=sqrt(x)+1;
	for(i=0;i<4793&&sqrtx>prime[i];i++)
		if(x%prime[i]==0)
			return 0;
	return 1;
}
bool islive(long int x){
	int i;
	for(i=0;i<4793;i++)
		if(prime[i]==x)
			return 1;
	return 0;
}
