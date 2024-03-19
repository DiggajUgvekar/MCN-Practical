#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
    int flag = 01111110;
    vector<int> input;
    int a[100],n,c;
    cout<<"Enter the size :";
    cin>>n;
    cout<<"Enter bits :";
    for(int i = 0; i < n; i++){
        cin>>a[i];
        input.push_back(a[i]);
    }

    cout<<flag;
    for (int i = 0; i < n; i++)
    {
        // c = input.popleft();
    }
    
    return 0; 
}
