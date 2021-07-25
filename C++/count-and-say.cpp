// The count-and-say sequence is a sequence of digit strings defined by the recursive formula:

// countAndSay(1) = "1"
// countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
// To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.


class Solution {
public:
    string countAndSay(int n) {
        
        string numbers = "1";
        string say = "";
        int counter = 1;
        
        for(int k = 1; k < n; k++){
            for(int i = 1; i < numbers.size(); i++){
                if(numbers[i] == numbers[i-1])
                    counter++;
                else{
                    say += '0'+counter;
                    say += numbers[i-1];
                    counter = 1;
                }
            }
            if(counter){
                say += '0'+counter;
                say += numbers[numbers.size()-1];
                counter = 1;
            }
            numbers = say;
            say = "";
        }
        
        return numbers;
    }
};
