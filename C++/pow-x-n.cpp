//Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0)
            return 1;
        if(abs(x) == 1){
            printf("%d\n", n % 2);
            if(abs(n) % 2 == 1)
                return x;
            else
                return abs(x);
        }
        
        
        double product;
        double multiple;
        
        if(n < 0)
            multiple = 1/x;
        else
            multiple = x;
        
        //printf("%f\n", multiple*multiple);
        product = multiple;
        for(int i = 1; i < abs((long)n); i++){
            product *= multiple;
            if(abs(product) <= 0.000001)
                return 0;
            //printf("%f\n", product);
        }
            
        
        return product;
    }
};
