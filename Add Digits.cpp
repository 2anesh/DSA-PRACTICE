class Solution {
public:
    int addDigits(int num) {
    int sum = 0;
    while(true){
        int res = num%10;
        sum = sum + res;
        num/=10;
        if(num==0){
            if(sum>=0 && sum<=9){
                break;
            }
            else{
                num=sum;
                sum=0;
            }
        }
    }
        return sum;
    }
};
