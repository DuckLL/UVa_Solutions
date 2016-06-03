/*
Problem F
Min-Max Cake
Input: standard input
Output: standard output
Time Limit: 2 seconds
Memory Limit: 64 MB
Motashota is a very fat boy. His younger brother Sumit, is very thin (Quite understandable as Motashota eats all the food at home). Sumit does not complain much but he wants equal share of only one thing. I guess you have seen the big Birthday Cakes which have a big round flower positioned within the cake. Sumit always wants equal share of this creamy flower and Motashota likes everything but this creamy flower of a cake so he does not hesitate to share this creamy flower. Given the description of a cake and the position of the center of the creamy flower you will have to determine the minimum amount (volume) of cake (Except the flower) that Sumit must have to get his equal share of flower. You should assume that

a)      A knife is used to cut the Cake

b)      The cutting path is always a straight line.

c)      Cakes are either circular or square shaped.

d)      The Cutting plain is always vertical.

e)      The flower is always strictly inside the Cake.

f)        The height of the cake is same everywhere.

g)      The side walls of the cake are vertical.

h)      All the surfaces of the cake are plain except the position of the flower.

i)        The flower is symmetric in all direction and placed on the top plain surface of the cake.

Input

The first line of the input file is an integer N which indicates how many sets of inputs are there. Each of the next N lines contains three (if the Cake is circular) or four (if the Cake is square shaped) integers.

If the cake is circular then the first integer L denotes the radius of the cake, the second integer H denotes the height of the cake and the third integer D (D<L) denotes the distance of the center of the flower from the center of the Cake.

If the cake is square shaped then the first integer L denotes the length of one side of the cake, the second integer H denotes the height of the cake and the third integer DX (DX<L/2.0) denotes the horizontal distance of the center of the flower from the center of the cake and DY (DY<L/2.0) denotes the vertical distance of the center of the flower from the center of the cake. The center of a square is the intersection point of its two diagonals. You may assume that the square shaped cake is placed on a graph paper and its sides are parallel to x-axis or y-axis, horizontal and vertical distance between two points means the difference of their x-coordinate and y-coordinate respectively. If the coordinates of two points is (1, 6) and (4, 2), their horizontal distance is (4-1) =3 and vertical distance is (6-2) =4.

Output

For each line of input print in a single the minimum volume of cake that Sumit must get to get his equal share of creamy flower. This value should have three digits after the decimal point.

Sample Input

3
10 3 8
10 3 0 0
20 1 0 0
Sample Input

49.050
150.000
200.000
(World Final Warm-up Contest, Problem Setter: Shahriar Manzoor)
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    bool square;
    char c;
    double num[4],sum;
    int n;
    int i;
    cin>>n;
    while(n>0)
    {
        square=false;
        for(i=0;i<3;i++)
            cin>>num[i];
        cin.get(c);
        if(c==' ')
        {
            cin>>num[3];
            square=true;
        }
        if(square)
            sum=num[1]*(num[0]/2-num[2])*(num[0]/2-num[3])*2;
        else
            sum=num[1]*(num[0]*num[0]*acos(num[2]/num[0])-num[2]*sqrt(num[0]*num[0]-num[2]*num[2]));
        cout.setf(ios::fixed);
        cout.precision(3);
        cout<<sum<<endl;
        n--;
    }
    return 0;
}
