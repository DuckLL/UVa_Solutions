/*
Arithmetic Operations With Large Integers 

This problem is about calculations with large numbers. Large means numbers with at most one thousand digits. The operations are limited to addition, substraction, multiplication and raising to a higher power.

There are no limitations to the operants of addition, substraction and multiplication. The base in raising to higher powers is positive and smaller than ten. The exponent is positive.

The inputfile consists of a valid expression with any number of operations. There are no parentheses, but the normal arithmetic priority rules are still valid.

An example of a valid expression is: 12345678 * 129876 + 2**1993. An invalid expression is: 12345678 * 129876 + 12**1993 because the base is greater than nine.

Input

The input contains several test cases, each one on a different line. Each test case contains numbers and operands in the following way: n op n { op n } . n is a positive decimal number with at most one thousand digits, stored as an ASCII-text. op is one of the following: +, -, *, ** (** means ``raising to higher powers''). There can be at most one hundred operations per test case. There are no spaces or other illegal characters in the input.

Output

The output contains the exact result of the evaluated expressions given in the input. Print each test case in a different line. Each test case won't have more than three thousand characters.

Sample Input

12345678*129876+2**1993
Sample Output

896977105683011347056900938420064050017435704756793125373158388145129891712\\
789307700515223684770523373785909874208955291755561688174261977676508872005\\
197801086953040197752187505381087095625350558038492109870986287356370809737\\
409093338414265941143390397695285610643740694879918793932122262001282984143\\
224073001319601441082075018589725061828585163552941409601583724270514300953\\
188533095947591884905338415676554651534516617357655143781579373852994152663\\
198702360093129335607684294312805938140290754926427776409574872859496315224\\
893901812925850900592061583009183090068756428459147015355107518672556877720
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
class big{
	public:
		big();
		friend istream& operator >> (istream& ins,big& b);
		friend ostream& operator << (ostream& outs,big& b);
		friend big operator + (big a,big b);
		friend big operator + (big a,int x);
		friend big operator - (big a,big b);
		friend big operator * (big a,big b);
		friend big operator * (big a,int x);
		friend big operator / (big a,int x);
		friend int operator % (big a,int x);
		friend bool operator > (big a,big b);
		friend big operator ~ (big b);
		friend bool operator == (big a,big b);
		friend string tostr(big b);
		void operator = (string str);
		void operator = (big b);
		vector<int> num;
		int len;
		bool sign;
		void adj();
		int toint();
	private:
		
		
};
int main(){
	ifstream fin("288.txt");
	istream& ins(fin);
	int sum;
	int i,j;
	string str,tmp;
	big a,b,c;
	string num[1000];
	while(ins>>str){
		sum=0;
		tmp="";
		for(i=0;i<str.size();i++){
			if(isdigit(str[i]))
				tmp+=str[i];
			else{
				num[sum]=tmp;
				sum++;
				if(str[i+1]=='*'){
					num[sum]=str[i];
					num[sum]+=str[i+1];
					i++;
				}
				else
					num[sum]=str[i];
				sum++;
				tmp="";	
			}
		}
		num[sum]=tmp;
		sum++;
		//**
		for(i=sum-1;i>=0;i--){
			if(num[i]=="**"){
				a=num[i-1];
				b=num[i+1];
				c="1";
				while(b.len>0){
					b.num[0]--;
					b.adj();
					c=c*a;
					
				}
				num[i-1]=tostr(c);
				for(j=i;j<sum-2;j++)
					num[j]=num[j+2];
				sum-=2;
			}
		}
		//*
		for(i=0;i<sum;i++){
			if(num[i]=="*"){
				a=num[i-1];
				b=num[i+1];
				c=a*b;
				num[i-1]=tostr(c);
				for(j=i;j<sum-2;j++)
					num[j]=num[j+2];
				sum-=2;
			}
		}
		//+
		for(i=0;i<sum;i++){
			if(num[i]=="+"){
				a=num[i-1];
				b=num[i+1];
				c=a+b;
				num[i-1]=tostr(c);
				for(j=i;j<sum-2;j++)
					num[j]=num[j+2];
				sum-=2;
			}
		}
		//-
		for(i=0;i<sum;i++){
			if(num[i]=="-"){
				a=num[i-1];
				b=num[i+1];
				c=a-b;
				num[i-1]=tostr(c);
				for(j=i;j<sum-2;j++)
					num[j]=num[j+2];
				sum-=2;
			}
		}
		cout<<num[0]<<endl;
	}
	return 0;
}
string tostr(big b){
	int i;
	string str;
	if(b.sign)
		str="-";
	else
		str="";
	for(i=b.len-1;i>=0;i--)
		str+='0'+b.num[i];
	return str;
}
big::big()
{
	num.clear();
	len=0;
    sign=0;
}
istream& operator >> (istream& ins,big& b)
{
    int i;
    string str;
    ins>>str;
    b.len=str.size();
    if(str[0]=='-'){
    	b.sign=1;
    	i=1;
    }
    else
    	i=0;
    for(;i<b.len;i++)
        b.num.push_back(str[b.len-i-1]-48);
    return ins;
}
ostream& operator << (ostream& outs,big& b)
{
	int i;
    if(b.sign)
    	cout<<"-"<<endl;
    for(i=b.len-1;i>=0;i--)
    	outs<<b.num[i];
    return outs;
}
big operator + (big a,big b){
	if(a.sign)
		if(b.sign)
			return ~(~a+~b);
		else
			return b-(~a);
	else{
		if(b.sign)
			return a-~b;
		else{
			int i;
			if(a.len>b.len){
				for(i=0;i<b.len;i++)
					a.num[i]+=b.num[i];
				a.adj();
				return a;
			}
			else{
				for(i=0;i<a.len;i++)
					b.num[i]+=a.num[i];
				b.adj();
				return b;
			}
		}
	}
}
big operator + (big a,int x){
	if(a.len==0){
		a.num.push_back(x);
		a.len++;
	}
	else
		a.num[0]+=x;
	a.adj();
	return a;
}
big operator - (big a,big b){
	int i;
	if(a>b){
		if(a.sign)
			if(b.sign)
				return ~b-~a;
			else
				return ~(~a+b);
		else
			if(b.sign)
				return a+b;
			else{
				for(i=0;i<a.len;i++)
					a.num[i]-=b.num[i];
				a.adj();
				return a;
			}
	}
	else if(a==b){
		big tmp;
		return tmp;
	}
	else
		return ~(b-a);
}
big operator * (big a,big b){
	int i,j;
	for(i=0;i<a.len;i++)
		for(j=0;j<b.len;j++)
			a.num[i]*=b.num[j];
	a.adj();
	return a;
}
big operator * (big a,int x){
	int i;
    for(i=0;i<a.len;i++)
        a.num[i]*=x;
    a.adj();
    return a;
}
big operator / (big a,int x){
	int i,j,tmp=x,xlen=0,sum;
	big ans;
	while(tmp>0){
		tmp/=10;
		xlen++;
	}
	a.num.push_back(0);
	a.len++;
	for(i=a.len-xlen-1;i>=0;i--){
		sum=0;
		for(j=i;j<i+xlen+1;j++){
			sum+=a.num[j]*pow(10,j-i);
			a.num[j]=0;
		}
		a.num[i]+=sum%x;
		ans.num.push_back(sum/x);
		ans.len++;
	}	
	a.adj();
	ans.adj();
	reverse(ans.num.begin(),ans.num.end());
	return ans;
}
int operator % (big a,int x){
	int i,j,tmp=x,xlen=0,sum;
	while(tmp>0){
		tmp/=10;
		xlen++;
	}
	a.num.push_back(0);
	a.len++;
	for(i=a.len-xlen-1;i>=0;i--){
		sum=0;
		for(j=i;j<i+xlen+1;j++){
			sum+=a.num[j]*pow(10,j-i);
			a.num[j]=0;
		}
		a.num[i]+=sum%x;	
	}
	a.adj();
	return a.toint();
}
void big::operator = (big b){
	num=b.num;
	len=b.len;
	sign=b.sign;
}
void big::operator = (string str){
	int i;
	num.clear();
	len=str.size();
    if(str[0]=='-'){
    	sign=1;
    	i=1;
    }
    else
    	i=0;
    for(;i<len;i++)
        num.push_back(str[len-i-1]-48);
}
bool operator > (big a,big b){
	int i;
	if(a.sign==b.sign)
		if(a.len>b.len)
			return !a.sign;
		else if(a.len<b.len)
			return a.sign;
		else{
			for(i=a.len-1;i>=0;i--){
				if(a.num[i]>b.num[i])
					return !a.sign;
			}
			return a.sign;
		}
	else
		return !a.sign;
}
big operator ~ (big b){
	b.sign=!b.sign;
	return b;
}
bool operator == (big a,big b){
	int i;
	if(a.sign==b.sign&&a.len==b.len){
		for(i=0;i<a.len;i++)
			if(a.num[i]!=b.num[i])
				return 0;
		return 1;
	}
	return 0;
}
void big::adj(){
	int i;
	for(i=0;i<len;i++)
    {
        if(num[i]>9){
            if(i+1==len){
            	len++;
            	num.push_back(num[i]/10);
            }
            else
            	num[i+1]+=num[i]/10;
            num[i]%=10;
        }
        while(num[i]<0){
        	num[i+1]--;
        	num[i]+=10;
        }
    }
	while(len>0&&num[len-1]==0){
	    num.pop_back();
	    len--;
	}
}
int big::toint(){
	int i,sum=0;
	for(i=0;i<len;i++)
		sum+=num[i]*pow(10,i);
	return sum;
}
