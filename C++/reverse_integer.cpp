class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;              /* ez breezy cover zero */
        
        int sign = 0,
            absNum = abs(x),        /* remove sign and just keep track of absolute number */
            powOfTen = 1,
            currDigitBaseTen = 0,
            totalForward = 0,
            totalReversed = 0;
        
        if(x < 0) sign = -1;        /* keep track of sign */
        else sign = 1;     
        
        do{
            if(powOfTen != 10){
                currDigitBaseTen = (absNum % (int)pow(10, (powOfTen))- totalForward)/pow(10, powOfTen-1);        /* get specific digit to tenth power*/
                totalForward += absNum % (int)pow(10, (powOfTen++)) - totalForward % (int)pow(10, (powOfTen-1)); /* track digits in forward order*/
            }
            else{
                if(sign == 1 && ((pow(2, 31)-1)/10 < totalReversed))        /* if overflow will occur when multiplied by 10, then return 0 */
                    return 0;
                else if(sign == -1 && ((pow(2, 31))/10 < abs(totalReversed)))
                    return 0;
                
                currDigitBaseTen = (absNum - totalForward)/pow(10, 9);     /* get most significant digit / 10^9 */
                powOfTen++;
            }  
            
            totalReversed *= 10;                                    /* multiply previous reversed total by 10 */
            totalReversed += currDigitBaseTen;                      /* add current digit to total */
        }while(powOfTen != 11 && (absNum % (int)pow(10, powOfTen-1)) != absNum );
        return sign*totalReversed;
    }
};
