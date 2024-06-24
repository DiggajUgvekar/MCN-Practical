#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bitstuffing(char* input) {
    string str(input); // Convert char* to string
    int n = str.length(), cnt = 0, l = 0;
    string flag = "01111110";

    str.insert(0, flag);
    str.append(flag);

    for (int i = 8; i < n + 8 + l; i++) {
        if (str[i] == '1') {
            cnt++;
            if (cnt == 5) {
                l++;
                str.insert(i + 1, "0");
                cnt = 0;
            }
        } else {
            cnt = 0;
        }
    }

    // Convert the manipulated string back to char*
    strcpy(input, str.c_str());
}

int main() {
    char str[256]; 
    cout << "Enter the string:" << endl;
    cin >> str;

    bitstuffing(str);

    cout << "Output:" << endl << str << endl;

    return 0;
}
