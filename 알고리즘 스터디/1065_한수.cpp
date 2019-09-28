// 1065번 한수

#include <iostream>
using namespace std;

int numOfHan(int num)
{
    //99이하면
    if(num<=99)
        return num;
    if(num==1000)
        return numOfHan(num-1);

    int hundreds = num/100;
    int tens = (num - hundreds*100)/10;
    int ones = num - hundreds*100 - tens*10;

    if(tens-hundreds == ones-tens)
        return 1 + numOfHan(num-1);
    else
        return numOfHan(num-1);
}

int main()
{
    int num;
    cin >> num;
    cout << numOfHan(num); 
    
}