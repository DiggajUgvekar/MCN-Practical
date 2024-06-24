#include<iostream>
using namespace std;

string xor1(string a, string b) {
  string result = "";
  int n = b.length();
  // ignore the first digits and start from second
  for (int i = 1; i < n; i++) {
    if (a[i] == b[i])
      result += "0";
    else
      result += "1";}
  return result;
}

string mod2div(string dividend, string divisor) {
  int pick = divisor.length();
  //take a substring to divide
  string tmp = dividend.substr(0, pick);
  int n = dividend.length();
  
  while (pick < n) {
    if (tmp[0] == '1')
    // the xor value + the next digit
      tmp = xor1(divisor, tmp) + dividend[pick];
    else
    //if tmp[0] == 0 then add 0's of length pick
      tmp = xor1(string(pick, '0'), tmp) + dividend[pick];
    pick += 1;
  }

   // Final check after the loop completes
  if (tmp[0] == '1')
    tmp = xor1(divisor, tmp);
  else
    tmp = xor1(string(pick, '0'), tmp);
  return tmp;
  }

void encodeData(string data, string key) {
  int l_key = key.length();
  //add zeros of length = length_key -1
  //1001 then add 3 zeros
  string appended_data = (data + string(l_key - 1, '0'));
  string remainder = mod2div(appended_data, key);
  string codeword = data + remainder;
  cout << "Remainder : " << remainder << "\n";
  cout << "Encoded Data (Data + Remainder) :" << codeword <<"\n";
  }

void receiver(string data, string key) {
  int l_key = key.length();
  string remainder = mod2div(data, key);

  if (remainder.find('1') != string::npos) {
    cout << "There is some error in data" << endl;
  } 
  else {
    cout << "Correct message received" << endl;
  }}

int main() {
  string data, key;
  cout << "Sender side" << endl;
  cout << "Enter the Data" << endl;
  cin >> data;
  cout << "Enter the Generator" << endl;
  cin >> key;
  encodeData(data, key);
  cout << "\nReceiver side" << endl;
  cout << "Enter the Data Which is received" << endl;
  cin >> data;
  receiver(data, key);
  return 0;
}