/*

Problem F : Maze Traversal

A common problem in artificial intelligence is negotiation of a maze. A maze has corridors and walls. The robot can proceed along corridors,
 but cannot go through walls.

Input
 The input begins with a single positive integer on a line by itself indicating the number of the cases following, each of them as described below.
 This line is followed by a blank line, and there is also a blank line between two consecutive inputs.




For this problem, you will input the dimensions of a maze, as two integer values on the first line. Of the two numbers,
the first is the number of rows and the second is the number of columns. Neither the number of rows nor columns will exceed 60.

Following these numbers will be a number of rows, as specified previously. In each row there will be a character for each column,
 with the row terminated by the end of line. Blank spaces are corridors, asterisks are walls. There needn't be any exits from the maze.

Following the maze, will be an initial row and column specified as two integers on one line. This gives the initial position of the robot.
 Initially the robot will be facing North (toward the first row).

The remaining input will consist of commands to the robot, with any amount of interspersed white-space. The valid commands are:
Rrotate the robot 90 degrees clockwise (to the right) Lrotate the robot 90 degrees counter-clockwise (to the left) Fmove the robot forward,
unless a wall prevents this, in which case do nothing Qquit the program, printing out the current robot row, column and orientation
Output
  For each test case, the output must follow the description below. The outputs of two consecutive cases will be separated by a blank line.




The final row and column must be integers separated by a space. The orientation must be one of N,W,S,E and separated from the column by a space.

Sample Input
1

7 8
********
* * * **
* *    *
* * ** *
* * *  *
*   * **
********
2 4
RRFLFF FFR
FF
RFFQ


Sample Output
5 6 W


*/
#include <iostream>
using namespace std;
int main()
{
    char c;
    char d[4]={'N','E','S','W'};
    int n,row,col,x,y,direction;
    int i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
        bool b[100][100]={false};
        cin>>row>>col;
        for(j=0;j<row;j++)
        {
            cin.get(c);
            for(k=0;k<col;k++)
            {
                cin.get(c);
                if(c==' ')
                    b[j][k]=true;
            }
        }
        cin>>x>>y;
        x--;
        y--;
        direction=0;
        while(cin>>c&&c!='Q')
        {
            switch(c)
            {
                case 'R':
                    direction++;
                    break;
                case 'L':
                    direction--;
                    if(direction<0)
                        direction+=4;
                    break;
                case 'F':
                    switch(direction%4)
                    {
                        case 0:
                            if(x-1>-1&&b[x-1][y])
                                x--;
                            break;
                        case 1:
                            if(y+1<col&&b[x][y+1])
                                y++;
                            break;
                        case 2:
                            if(x+1<row&&b[x+1][y])
                                x++;
                            break;
                        case 3:
                            if(y-1>-1&&b[x][y-1])
                                y--;
                            break;
                    }
                    break;
            }
        }
        x++;
        y++;
        cout<<x<<" "<<y<<" "<<d[direction%4]<<endl;
        if(i<n-1)
            cout<<endl;
    }
    return 0;
}
