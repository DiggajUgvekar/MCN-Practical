#include<iostream> 
#include<string.h> 
using namespace std;
int main()
{
string str,temp;
cout<<"Enter the string"<<endl; 
cin>>str;
int n=str.length(),cnt=0,l=0; 
string flag="01111110";
str.insert(0,flag);
str.append("01111110"); 
for(int i=8;i<n+8+l;i++)
{
if(str[i]=='1')
{
cnt++;
if(cnt==6)
{
l++;
str.insert(i,"0"); cnt=0;
}
}
else{
    cnt=0;
}
}

cout<<"Output:"<<endl<<str;
}
