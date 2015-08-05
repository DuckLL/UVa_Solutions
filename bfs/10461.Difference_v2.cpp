/*
Problem I
Difference
Input: standard input
Output: standard output
Time Limit: 6 seconds
 
You are given a list of jobs with associated time to complete them. Also are given a list of job dependencies. Your job is to calculate the maximum possible difference among all possible completion time of a particular job. For this problem, job dependency is a bit simpler. When a job depends on several other jobs to be completed, finishing of all of them will allow it to execute. Furthermore, jobs cannot be executed in parallel and there will be no idle moment.

In the above example job-B cannot be started before A and D. So it can be started after 5 days and it must be started after 7 days. Here for job-B, the difference is 2 days.
 
Input
Input starts with a pair of integers v(1<=v<=500) and e(0<=e<=500) where v represents the number of jobs and e represents the number of dependencies in the dependency list. Following is a line with v integers each indicating the time in days to complete the jobs where the i'th integer denotes the completion time of the i'th job. The jobs are numbered by integers from 1 to v. Next e lines has the form "x y" which means that job x should be completed prior to job y(1 <= x, y <= v). Next line has an integer q which denotes the number of queries to answer which is followed by q integers x (1 <= x <= v). A line with v = e = 0 ends the input session. Every block will be followed by a blank line. There will be no impractical situation (Each job can be completed) in input.

Output
For each query in a block output the result according to the problem description in a separate line. A blank line is essential after every block of data. See the sample output.
 
Sample Input
 
4 4
4 3 2 1
2 1
2 4
3 1 
3 4
2
1 2 

4 4
4 3 2 1
2 1
2 4
3 1 
3 4
2
3 4

0 0
Sample Output
 
Case #1:
1
2

Case #2:
3
4
*/
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
struct v{
	int day;
	vector<int> in;
	vector<int> out; 
};
bool isexist(vector<int> vec,int x);
int main(){
	ifstream fin("10461.txt");
	istream& ins(cin);
	int v_num,e_num,q;
	int sum,flag,total;
	int mini,maxx,now;
	vector<int> query;
	bool qb[501];
	int x,y;
	int i,j;
	int n=0;
	while(ins>>v_num>>e_num&&v_num){
		v job[v_num+1];
		total=0;
		for(i=1;i<v_num+1;i++){
			ins>>job[i].day;
			total+=job[i].day;
		}			
		for(i=0;i<e_num;i++){
			ins>>x>>y;
			job[x].in.push_back(y);
			job[y].out.push_back(x);
		}
		cout<<"Case #"<<++n<<":"<<endl;
		ins>>q;
		while(q--){
			ins>>x;
			sum=0;
			flag=0;
			query.clear();
			query.push_back(x);
			fill(qb,qb+501,0);
			qb[x]=1;
			while(flag<query.size()){
                now=query[flag];
                sum+=job[now].day;
                for(j=0;j<job[now].in.size();j++)
                    if(!qb[job[now].in[j]]){
                    	query.push_back(job[now].in[j]);
                    	qb[job[now].in[j]]=1;
                    }                        
                flag++;
            }
            mini=sum-job[x].day;
            sum=0;
			flag=0;
			query.clear();
			query.push_back(x);
			fill(qb,qb+501,0);
			qb[x]=1;
			while(flag<query.size()){
                now=query[flag];
                sum+=job[now].day;
                for(j=0;j<job[now].out.size();j++)
                    if(!qb[job[now].out[j]]){
                    	query.push_back(job[now].out[j]);
                    	qb[job[now].out[j]]=1;
                    }                        
                flag++;
            }
            maxx=total-sum;
            cout<<maxx-mini<<endl;
		}
		cout<<endl;
	}
	return 0;
}
