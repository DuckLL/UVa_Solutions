/*
Problem A - Prime Distance

The branch of mathematics called number theory is about properties of numbers. One of the areas that has captured the interest of number theoreticians for thousands of years is the question of primality. A prime number is a number that is has no proper factors (it is only evenly divisible by 1 and itself). The first prime numbers are 2,3,5,7 but they quickly become less frequent. One of the interesting questions is how dense they are in various ranges. Adjacent primes are two numbers that are both primes, but there are no other prime numbers between the adjacent primes. For example, 2,3 are the only adjacent primes that are also adjacent numbers.
Your program is given 2 numbers: L and U (1<=L<U<=2,147,483,647), and you are to find the two adjacent primes C1 and C2 (L<=C1<C2<=U) that are closest (i.e. C2-C1 is the minimum). If there are other pairs that are the same distance apart, use the first pair. You are also to find the two adjacent primes D1 and D2 (L<=D1<D2<=U) where D1 and D2 are as distant from each other as possible (again choosing the first pair if there is a tie).

Input

Each line of input will contain two positive integers, L and U, with L < U. The difference between L and U will not exceed 1,000,000.
Output

For each L and U, the output will either be the statement that there are no adjacent primes (because there are less than two primes between the two given numbers) or a line giving the two pairs of adjacent primes.
Sample Input

2 17

14 17

 
Output for Sample Input

2,3 are closest, 7,11 are most distant.

There are no adjacent primes.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
vector<long int> prime;
bool isprime(long int x);
bool islive(long int x);
int main(){
	ifstream fin("10140.txt");
	istream& ins(fin);
	bool bb;
	long int a,b,min,max,mina,minb,maxa,maxb,tmp;
	long long int i;
	//bulid prime table	
	prime.push_back(2);
	for(i=3;i<46338;i++)
		if(isprime(i))
			prime.push_back(i);
	while(ins>>a>>b){
		vector<long int> ans;
		for(i=a;i<=b;i++){
			if(i<46338)
				bb=islive(i);
			else
				bb=isprime(i);
			if(bb)
				ans.push_back(i);
		}			
		if(ans.size()<2)
			cout<<"There are no adjacent primes."<<endl;
		else{
			max=0;
			min=2e9;
			for(i=0;i<ans.size()-1;i++){
				tmp=ans[i+1]-ans[i];
				if(tmp>max){
					max=tmp;
					maxa=ans[i];
					maxb=ans[i+1];
				}
				if(tmp<min){
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
bool isprime(long int x){
	int i,sqrtx;
	sqrtx=sqrt(x)+1;
	for(i=0;i<4792&&sqrtx>prime[i];i++)
		if(x%prime[i]==0)
			return 0;
	return 1;
}
bool islive(long int x){
	int head,tail,flag;
    head=0;
    tail=4791;
    flag=(head+tail)/2;
    while(prime[flag]!=x){
        if(flag==head||flag==tail)
            return 0;
        if(prime[flag]>x)
            tail=flag;
        else
            head=flag;
        flag=(head+tail)/2;
    }
	return 1;
}
