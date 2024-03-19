//Created By Diggaj
#include <iostream> 
using namespace std; 

int main() 
{ 
    char a[200];
    cout << "Enter the String: ";
    cin >> a;
    int pos=0; //0 = low and 1 ==high
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"     "<<currentChar<<"     ";
    }
    cout<<endl;

    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        if(currentChar == '0'){
            if(i == 0){
                cout<<" HIGH LOW  ";
                pos=0;
            }
            else{
                if(pos==0){
                    cout<<" HIGH LOW  ";
                    pos=0;
                }
                else{
                    cout<<" LOW HIGH  ";
                    pos=1;
                }
            }
        }
        else{
            if(i == 0){
                cout<<" LOW HIGH  ";
                pos=1;
            }
            else{
                if(pos==0){
                    cout<<" LOW HIGH  ";
                    pos=1;
                }
                else{
                    cout<<" HIGH LOW  ";
                    pos=0;
                }
            }
        }
    }
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"          |";
    }
    cout<<endl;

    // if 0 the low and 1 then high
    pos=0;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        if(currentChar == '0'){
            if(i == 0){
                cout<<"|‾‾‾‾|____|";
                pos=0;
            }
            else{
                if(pos==0){
                    cout<<"‾‾‾‾‾|____|";
                    pos=0;
                }
                else{
                    cout<<"_____|‾‾‾‾|";
                    pos=1;
                }
            }
        }
        else{
            if(i == 0){
                cout<<"|____|‾‾‾‾|";
                pos=1;
            }
            else{
                if(pos==0){
                    cout<<"_____|‾‾‾‾|";
                    pos=1;
                }
                else{
                    cout<<"‾‾‾‾‾|____|";
                    pos=0;
                }
            }
        }
    }
    cout<<endl;
    for (int i = 0; a[i] != '\0'; ++i) {
        char currentChar = a[i];
        cout<<"          |";
    }

    return 0; 
}
