/*
Problem L
Goldbach and Euler
Input: standard input
Output: standard output
Time Limit: 40 seconds
Memory Limit: 40 MB
 
¡§That every number which is resolvable into two prime numbers can be resolved into as many prime numbers as you like, can be illustrated and confirmed by an observation which you have formerly communicated to me, namely that every even number is a sum of two primes, and since (n-2) is also a sum of two prime numbers, n must be a sum of three, and also four prime numbers, and so on. If, however, n is an odd number, then it is certainly a sum of three prime numbers, since (n-1) is a sum of two prime numbers, and can therefore be resolved into as many prime numbers as you like. However, that every number is a sum of two primes, I consider a theorem which is quite true, although I cannot demonstrate it.¡¨
 
-- Euler to Goldbach, 1742
The above conjecture about all numbers being the sum of two primes (where 1 counts as a prime) is not always true, but it is more true for even numbers. Your task is to test the conjecture for specified integers, considering that prime numbers are the numbers which are positive and divisible by exactly two positive integers. Your program must be very efficient.

Input
The input file contains 100000 lines of input. Each line contains a single integer n (0<n<=100000000). Input is terminated by end of file.
 
Output
For each line of input produce one line of output. This line should be of one of the following types:

n is not the sum of two primes!
n is the sum of p1 and p2.
 
For the second case, always make sure that (p2-p1) is positive and minimized.
 
Sample Input
11
12
 
Sample Output
11 is not the sum of two primes!
12 is the sum of 5 and 7.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
bool isprime(int x);
int main(){
	ifstream fin("10311.txt");
	istream& ins(cin);
	int sqrti,max,primesize;
	int i,j;
	//bulid prime table	
	prime.push_back(2);
	max=sqrt(1000000000)+1;
	for(i=3;i<max;i++)
		if(isprime(i))
			prime.push_back(i);
	bool b;
	int x;
	while(ins>>x){
		if(x%2==1){
			if(isprime(x-2))
				cout<<x<<" is the sum of "<<2<<" and "<<x-2<<"."<<endl;
			else
				cout<<x<<" is not the sum of two primes!"<<endl;
		}
		else{
			b=1;
			for(i=x/2+1;i<x-2;i++)
				if(isprime(i)&&isprime(x-i)){
					cout<<x<<" is the sum of "<<x-i<<" and "<<i<<"."<<endl;
					b=0;
					break;
				}
			if(b)
				cout<<x<<" is not the sum of two primes!"<<endl;
		}						
	}
	return 0;
}
bool isprime(int x){
	if(x<2)
		return 0;
	int i,sqrtx;
	sqrtx=sqrt(x);
	for(i=0;sqrtx>=prime[i];i++)
		if(x%prime[i]==0)
			return 0;
	return 1;
}
