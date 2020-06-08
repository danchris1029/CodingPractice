#include <iostream>
#include <string>
using namespace std;

string FirstReverse(string str) {
  string newStr = "";
  for (int i = 0; i < str.length(); i++)
    newStr += str[str.length()-(i+1)];
  return newStr;

}

int main(void) { 
   
  // keep this function call here
  cout << FirstReverse(gets(stdin));
  return 0;
    
}