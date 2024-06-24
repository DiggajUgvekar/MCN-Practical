#include<iostream> 
#include<string.h>
using namespace std; 

int main()
{
    string str,temp;
    cout<<"Enter the string"<<endl; 
    cin>>str;
    int n=str.length();

    string flag="01111110",esc="11100000"; 
    str.insert(0,flag);
    str.append("01111110");
    cout<<"The Byte Stuffed String : "; 

    //if less than 8 then directly print
    if(n<8)
    {
        cout<<str;
    }
    else{
        for(int i = 8 ; i <= n+8; i = i+8)
        {
            temp=str.substr(i,8);
            // if temp(sub string) is equal to flag or esc then insert a esc before the temp
            if(flag==temp || temp==esc)
            {
                str.insert(i,esc); 
                i=i+8;
            }
        }
        cout<<endl<<str;
    }
}
