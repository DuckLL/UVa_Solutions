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
#define max 100000001
using namespace std;
bool prime[max]={0};
int main(){
	ifstream fin("10311.txt");
	istream& ins(fin);
	int i,j;
	for(i=2;i<max;i++)
		if(prime[i]==0)
			for(j=i*2;j<max;j+=i)
				prime[j]=1;
	int x;
	while(ins>>x){
		cout<<x;
		if(x%2==1)
			cout<<" is not the sum of two primes!"<<endl;
		for(i=2;i<x/2;i++)
			if(!prime[i]&&!prime[x-i]){
				cout<<" is the sum of "<<i<<" and "<<x-i<<"."<<endl;
				break;
			}
	}
	return 0;
}
