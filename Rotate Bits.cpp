class Solution
{
  public:
        vector <int> rotate (int n, int d)
        {
            //code here.
            d = d % 16;
            
            int addLeft = 0;
            int left = n << d;
            for(int i = 31;i>=(16-d);i--){
                if(left & (1<<i)){
                    addLeft = addLeft | (1<<i);
                    if(i > 15) left = left & ~(1 << i);
                }
            }
            addLeft = addLeft >> (16);
            left = left | addLeft;
            
            
            int addRight = 0;
            int right = n >> d;
            for(int i = 0;i<d;i++){
                if((1 << i) & n){
                    addRight = addRight | (1 << i);
                }
            }
            addRight = addRight<<(16-d);
            right = right | addRight;
            
            
            return {left,right};
        }
};
