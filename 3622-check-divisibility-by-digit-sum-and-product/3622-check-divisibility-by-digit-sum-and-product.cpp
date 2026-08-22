class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product=1;
        int real=n;
        while(n!=0){
            int rem=n%10;
            sum=sum+rem;
            product=product*rem;
            n=n/10;
        }
        if(real%(sum+product)==0){
            return true;

        }
        return false;
    }
   
};