#include <iostream> 
using namespace std; 

int main() 
{ 
    char a[200];
    cout << "Enter the String: ";
    cin >> a;

    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"   "<<currentChar<<"   ";
    }
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        if(currentChar == '0'){
            cout<<"  LOW  ";
        }
        else{
            cout<<"  HIGH ";
        }
    }
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"      |";
    }
    cout<<endl;

    // if 0 then low and 1 then high
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        if(currentChar == '0'){
            cout<<"______|";
        }
        else{
            cout<<"‾‾‾‾‾‾|";
        }
    }
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"      |";
    }

    return 0; 
}
