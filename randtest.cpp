#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
float x;
int b;
while(cin>>b)
{
x=rand()%5 +1;
cout<<x<<endl;
if(b==9)
break;
}
return 0;
}
