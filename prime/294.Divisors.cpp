/*
Divisors 

Mathematicians love all sorts of odd properties of numbers. For instance, they consider 945 to be an interesting number, since it is the first odd number for which the sum of its divisors is larger than the number itself.

To help them search for interesting numbers, you are to write a program that scans a range of numbers and determines the number that has the largest number of divisors in the range. Unfortunately, the size of the numbers, and the size of the range is such that a too simple-minded approach may take too much time to run. So make sure that your algorithm is clever enough to cope with the largest possible range in just a few seconds.

Input Specification

The first line of input specifies the number N of ranges, and each of the N following lines contains a range, consisting of a lower bound L and an upper bound U, where L and U are included in the range. L and U are chosen such that tex2html_wrap_inline42 and  tex2html_wrap_inline44 .

Output Specification

For each range, find the number P which has the largest number of divisors (if several numbers tie for first place, select the lowest), and the number of positive divisors D of P (where P is included as a divisor). Print the text 'Between L and H, P has a maximum of D divisors.', where L, H, P, and D are the numbers as defined above.

Example input

3
1 10
1000 1000
999999900 1000000000
Example output

Between 1 and 10, 6 has a maximum of 4 divisors.
Between 1000 and 1000, 1000 has a maximum of 16 divisors.
Between 999999900 and 1000000000, 999999924 has a maximum of 192 divisors.
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> prime;
int divi(int x);
int main(){
	ifstream fin("294.txt");
	istream& ins(cin);
	int max,n,x,y,maxi,sqrti;
	int i,j;
	//bulid prime table	
	prime.push_back(2);
	prime.push_back(3);
	prime.push_back(5);
	max=sqrt(1000000000)+1;
	for(i=7;i<max;i++)
		if(i%6==1||i%6==5){
			sqrti=sqrt(i);
			for(j=2;sqrti>=prime[j];j++)
				if(i%prime[j]==0)
					break;
			if(sqrti<prime[j])
				prime.push_back(i);
		}
	ins>>n;
	while(n--){
		ins>>x>>y;
		y++;
		max=0;
		maxi=x;
		for(i=x;i<y;i++)
			if(divi(i)>max){
				max=divi(i);
				maxi=i;
		}			
		cout<<"Between "<<x<<" and "<<--y<<", "<<maxi<<" has a maximum of "<<max<<" divisors."<<endl;
	}
	return 0;
}
int divi(int x){
	int i=0,sum=1,tmp,sqrtx=sqrt(x);
	while(x>1&&i<prime.size()){
		tmp=1;
		while(x%prime[i]==0){
			tmp++;
			x/=prime[i];
		}
		sum*=tmp;
		i++;
	}
	return sum;
}
