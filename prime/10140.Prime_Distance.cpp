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
	long int a,b,min,max,last,now,mina,minb,maxa,maxb;
	long long int i;
	//bulid prime table	
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	for(i=7;i<50001;i++)
		if(isprime(i))
			prime.push_back(i);
	while(ins>>a>>b){
		min=b-a;
		max=0;
		last=0;
		now=0;
		for(i=a;i<=b;i++){
			if(islive(i)||isprime(i)){
				if(last==0){
					last=i;
					continue;
				}
				else
					now=i;	
				if(now-last>max){
					max=i-last;
					maxa=last;
					maxb=now;
				}
				if(now-last<min){
					min=i-last;
					mina=last;
					minb=now;
				}
				last=now;
			}
		}
		if(last==0||now==0)
			cout<<"There are no adjacent primes."<<endl;
		else
			cout<<mina<<","<<minb<<" are closest, "<<maxa<<","<<maxb<<" are most distant."<<endl;
	}
	return 0;
}
bool isprime(long int x){
	if(x<2)
		return 0;
	if(x%6==1||x%6==5){
		int i,sqrtx;
		sqrtx=sqrt(x)+1;
		for(i=2;sqrtx>prime[i];i++)
			if(x%prime[i]==0)
				return 0;
		return 1;
	}
	return 0;
}
bool islive(long int x){
	if(x>50001)
		return 0;
	int head,tail,flag;
    head=0;
    tail=prime.size()-1;
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
