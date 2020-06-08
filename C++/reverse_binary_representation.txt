#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int BinaryReversal(char *str) {
  string binaryRep = "0000000000000000";
  int integerStr = atoi(str);
  int remainder = 0;
  int reverseBinaryInt = 0;
  int maxBit = 7;

  
   for(int i = maxBit; i >= 0; i--){
    
    if (i != 0)
      remainder = (integerStr %(2 << (i-1))); // 2 shifted i to left is 2^i
    else{
      binaryRep[i] = (char)integerStr+48;
      reverseBinaryInt += integerStr * (2 << maxBit-(i+1));
      break;
    }

    if(remainder != integerStr){
      integerStr = remainder;
      binaryRep[i] = '1';
      if(i == maxBit)
        reverseBinaryInt += 1;
      else
        reverseBinaryInt += (2 << maxBit-(i+1));

    }
    
   }
  cout << binaryRep << endl;
  return reverseBinaryInt;

}

int main(void) { 
   
  // keep this function call here
  cout << BinaryReversal(gets(stdin));
  return 0;
    
}