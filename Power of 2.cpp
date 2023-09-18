class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        // Your code here  
        if(n == 1)
            return true;
        if(n==0||n%2 != 0)
            return false;
        long long prod=1;
        int i = 0;
        while(prod < n){
            prod = pow(2, i);
            if(prod == n)
                return true;
            i++;
        }
        if(prod > n)
            return false;
        
    }
};
