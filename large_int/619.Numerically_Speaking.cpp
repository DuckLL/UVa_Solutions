/*
 Numerically Speaking 

A developer of crossword puzzles (and other similar word games) has decided to develop a mapping between every possible word with from one to twenty characters and unique integers. The mapping is very simple, with the ordering being done first by the length of the word, and then alphabetically. Part of the list is shown below.

    a          1

    b          2

    ...

    z          26

    aa         27

    ab         28

    ...

    snowfall   157,118,051,752

    ...

 
Your job in this problem is to develop a program which can translate, bidirectionally, between the unique word numbers and the corresponding words.

Input 

Input to the program is a list of words and numbers, one per line starting in column one, followed by a line containing a single asterisk in column one. A number will consist only of decimal digits (0 through 9) followed immediately by the end of line (that is, there will be no commas in input numbers). A word will consist of between one and twenty lowercase alphabetic characters (a through z).
Output 

The output is to contain a single line for each word or number in the input data. This line is to contain the word starting in column one, followed by an appropriate number of blanks, and the corresponding word number starting in column 23. Word numbers that have more than three digits must be separated by commas at thousands, millions, and so forth.
Sample Input 

29697684282993

transcendental

28011622636823854456520

computationally

zzzzzzzzzzzzzzzzzzzz

*

 
Sample Output 

elementary            29,697,684,282,993

transcendental        51,346,529,199,396,181,750

prestidigitation      28,011,622,636,823,854,456,520

computationally       232,049,592,627,851,629,097

zzzzzzzzzzzzzzzzzzzz  20,725,274,851,017,785,518,433,805,270

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
		friend ostream& operator << (ostream& outs,big& b);
		friend big operator + (big a,big b);
		friend big operator * (big a,int x);
		friend string tostr(big b);
		void operator = (string str);
		void operator = (big b);		
	private:
		vector<int> num;
		int len;
		bool sign;
		void adj();
		int toint();
};
int main(){
	ifstream fin("619.txt");
	istream& ins(fin);
	int i;
	int len;
	string str,str2;
	big x26[24];
	x26[0]="1";
	for(i=1;i<24;i++)
		x26[i]=x26[i-1]*26;
	while(ins>>str){
		big x;	
		if(str=="*")
			break;
		if(isdigit(str[0])){
			x=str;
			str2=tostr(x);
			cout<<left<<setw(22)<<str2<<x<<endl;
		}			
		else{
			big tmp;
			len=str.size();	
			for(i=0;i<len;i++){
				tmp=x26[len-i-1]*(str[i]-'a'+1);
				x=x+tmp;
			}
			cout<<left<<setw(22)<<str<<x<<endl;
		}
	}
	return 0;
}
big::big(){
	num.clear();
	len=0;
    sign=0;
}
ostream& operator << (ostream& outs,big& b){
	int i,j,pa;
    if(b.sign)
    	cout<<"-"<<endl;
    pa=b.len%3;
    pa=3-pa;
    j=0;
    for(i=b.len-1;i>=0;i--){
		if((pa+j)%3==0&&j!=0)
			cout<<",";   		
    	outs<<b.num[i];
    	j++;
    }    	
    return outs;
}
big operator + (big a,big b){
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
big operator * (big a,int x){
	int i;
    for(i=0;i<a.len;i++)
        a.num[i]*=x;
    a.adj();
    return a;
}
string tostr(big b){
	string str="";
	b.num[0]--;
	b.adj();
	int i,j,sum;
	while(b.len>0){
		big ans;
		b.num.push_back(0);
		b.len++;
		for(i=b.len-3;i>=0;i--){
			sum=0;
			for(j=i;j<i+3;j++){
				sum+=b.num[j]*pow(10,j-i);
				b.num[j]=0;
			}
			b.num[i]+=sum%26;
			ans.num.push_back(sum/26);
			ans.len++;
		}
		b.adj();
		str+=(char)('a'+b.toint()-1);
		reverse(ans.num.begin(),ans.num.end());
		ans.adj();
		b=ans;
	}
	if(str=="")
		str="a";
	else
		str[0]++;
	reverse(str.begin(),str.end());
	return str;
}
void big::operator = (big b){
	num=b.num;
	len=b.len;
	sign=b.sign;
}
void big::operator = (string str){
	int i;
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
