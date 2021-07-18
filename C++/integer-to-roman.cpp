class Solution {
public:
    string intToRoman(int num) {
        string number = to_string(num);
        int maxBase10 = number.length();
        string roman = "";
        
        for(int i = maxBase10; i > 0; i--){
            int currNum = num%(int)pow(10, i) - num%(int)pow(10, i-1);
            
            while(currNum != 0){
                if(currNum >= 1000){
                    currNum -= 1000;
                    roman+= "M";
                    continue;
                }
                if(currNum == 900){
                    currNum -= 900;
                    roman+= "CM";
                    continue;
                }
                if(currNum >= 600){
                    currNum -= 600;
                    roman += "DC";
                    continue;
                }
                if(currNum >= 500){
                    currNum -= 500;
                    roman += "D";
                    continue;
                }
                if(currNum == 400){
                    currNum -= 400;
                    roman += "CD";
                    continue;
                }
                if(currNum >= 100){
                    currNum -= 100;
                    roman += "C";
                    continue;
                }
                if(currNum == 90){
                    currNum -= 90;
                    roman += "XC";
                    continue;
                }
                if(currNum >= 60){
                    currNum -= 60;
                    roman += "LX";
                    continue;
                }
                if(currNum == 50){
                    currNum -= 50;
                    roman += "L";
                    continue;
                }
                if(currNum == 40){
                    currNum -= 40;
                    roman += "XL";
                    continue;
                }
                if(currNum >= 10){
                    currNum -= 10;
                    roman += "X";
                    continue;
                }
                if(currNum == 9){
                    currNum -= 9;
                    roman += "IX";
                    continue;
                }
                if(currNum >= 6){
                    currNum -= 6;
                    roman += "VI";
                    continue;
                }
                if(currNum == 5){
                    currNum -= 5;
                    roman += "V";
                    continue;
                }
                if(currNum == 4){
                    currNum -= 4;
                    roman += "IV";
                    continue;
                }
                currNum--;
                roman += "I";
                
            }
        }
        
        return roman;
    }
};