/*
500! 
In these days you can more and more often happen to see programs which perform some useful calculations being executed rather then trivial screen savers. Some of them check the system message queue and in case of finding it empty (for examples somebody is editing a file and stays idle for some time) execute its own algorithm.

As an examples we can give programs which calculate primary numbers.


One can also imagine a program which calculates a factorial of given numbers. In this case it is the time complexity of order O(n) which makes troubles, but the memory requirements. Considering the fact that 500! gives 1135-digit number no standard, neither integer nor floating, data type is applicable here.


Your task is to write a programs which calculates a factorial of a given number.

Assumptions: Value of a number ``n" which factorial should be calculated of does not exceed 1000 (although 500! is the name of the problem, 500! is a small limit).

Input 

Any number of lines, each containing value ``n" for which you should provide value of n!
Output 

2 lines for each input case. First should contain value ``n" followed by character `!'. The second should contain calculated value n!.
Sample Input 

10
30
50
100
Sample Output 

10!
3628800
30!
265252859812191058636308480000000
50!
30414093201713378043612608166064768844377641568960512000000000000
100!
93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
class big{
	public:
		big();
		friend ostream& operator<< (ostream& outs,big& b);
		void operator = (big b);
		void addint(int x);
		void mulint(int x);
	private:
		vector<int> num;
		int len;
		bool sign;
		void adj();
};
int main(){
	ifstream fin("623.txt");
	istream& ins(cin);
	int i,n;
	big x[1000];
	x[0].addint(1);
	for(i=1;i<1000;i++){
		x[i]=x[i-1];
		x[i].mulint(i+1);
	}		
	while(ins>>n){
		cout<<n<<"!"<<endl;
		if(n==0)
			cout<<1<<endl;
		else
			cout<<x[n-1]<<endl;
	}
	return 0;
}
big::big()
{
	num.clear();
	len=0;
    sign=0;
}
ostream& operator<< (ostream& outs,big& b)
{
	int i;
    if(b.sign)
    	cout<<"-"<<endl;
    for(i=b.len-1;i>=0;i--)
    	outs<<b.num[i];
    return outs;
}
void big::operator = (big b){
	num=b.num;
	len=b.len;
	sign=b.sign;
}
void big::addint(int x)
{
    if(len==0){
    	num.push_back(x);
    	len++;
    }    	
    else
    	num[0]+=x;
    adj();
}
void big::mulint(int x)
{
    int i;
    for(i=0;i<len;i++)
        num[i]*=x;
    adj();
}
void big::adj(){
	int i;
	for(i=0;i<len;i++)
    {
        if(num[i]>9)
        {
            if(i+1==len){
            	len++;
            	num.push_back(num[i]/10);
            }
            else
            	num[i+1]+=num[i]/10;
            num[i]%=10;
        }
    }
}

