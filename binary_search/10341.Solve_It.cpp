/*
Problem F
Solve It
Input: standard input
Output: standard output
Time Limit: 1 second
Memory Limit: 32 MB
Solve the equation:
        p*e-x + q*sin(x) + r*cos(x) + s*tan(x) + t*x2 + u = 0
        where 0 <= x <= 1.

Input

Input consists of multiple test cases and terminated by an EOF. Each test case consists of 6 integers in a single line: p, q, r, s, t and u (where 0 <= p,r <= 20 and -20 <= q,s,t <= 0). There will be maximum 2100 lines in the input file.

Output

For each set of input, there should be a line containing the value of x, correct upto 4 decimal places, or the string "No solution", whichever is applicable.

Sample Input

0 0 0 0 -2 1
1 0 0 0 -1 2
1 -1 1 -1 -1 1
Sample Output

0.7071
No solution
0.7554
Mustaq Ahmed
*/
#include <iostream>
#include <fstream>
#include <cmath>
#define f(x) (p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u)
using namespace std;
int main(){
	ifstream fin("10341.txt");
	istream& ins(cin);
	int p,q,r,s,t,u;
	double high,low,half;
	while(ins>>p>>q>>r>>s>>t>>u){
		high=1;
		low=0;
		if(f(high)*f(low)>0)
			cout<<"No solution"<<endl;
		else{
			while(high-low>1e-7){
				half=(high+low)/2;
				if(f(half)<0)
					high=half;
				else
					low=half;
			}
			cout.setf(ios::fixed);
			cout.precision(4);
			cout<<half<<endl;			
		}			
	}
	return 0;
}
