class Solution {
public:
    /*
        Implement atoi which converts a string to an integer.
        The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
        The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
        If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
        If no valid conversion could be performed, a zero value is returned.
    */
    
    // NOTE: Yeah, i need to make this code look more pretty
    
    int myAtoi(string str) {
        if(str.length() == 0)
            return 0;
        
        int currChar = 0,
            prevDigit = 0,
            currDigit = 0,
            numOfDigits = 0,
            sign = 1;
        
             // A letter in ascii is between 48 and 57
        while(currChar < str.length()){
                 // check if str[currChar] is a letter
            if((int)str[currChar] >= 48 && (int)str[currChar] <= 57){
                break;
            }   // check if str[currChar] is '-' and str[currChar+1] is a letter
            else if((int)str[currChar] == 45 && ((int)str[currChar+1] >= 48 && (int)str[currChar+1] <= 57)){
                sign = -1;
                currChar++;
                break;
            }    // check if str[currChar] is '+' and str[currChar+1] is a letter
            else if((int)str[currChar] == 43 && ((int)str[currChar+1] >= 48 && (int)str[currChar+1] <= 57)){    
                 currChar++;
                 break;
            }   // check if str[currChar] is whitespace
            else if((int)str[currChar] == 32){                                      
                currChar++;
                if(currChar == str.length())
                    return 0;
            }
            else
                return 0;
        }
        
        currDigit = sign*((int)str[currChar]-48);
        currChar++;
        prevDigit = abs(currDigit);
        
        while((int)str[currChar] >= 48 && (int)str[currChar] <= 57){
                currDigit = (int)str[currChar]-48;
             currChar++;
                if(sign == 1){
                    // 214748364*10+7 is 2147483647, so if currDigit is more than 7 then return sign*pow(2,31)-1
                    if((prevDigit == 214748364 && currDigit > 7) || (prevDigit > 214748364))
                        return sign*pow(2,31)-1;
                }
                else{
                    // 214748364*10+8 is 2147483648, so if currDigit is more than 8 then return sign*pow(2,31)
                    if((prevDigit == 214748364 && currDigit > 7) || (prevDigit > 214748364))
                        return sign*pow(2,31);
                }
                cout << prevDigit << endl;
                prevDigit *= 10;
                currDigit = sign*(currDigit + prevDigit);
                prevDigit = abs(currDigit);
        }

            
        return  currDigit;
    }
};
