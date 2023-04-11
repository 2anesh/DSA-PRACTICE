class Solution {
    int solve(int a, int b, int c) {
       if(a==b && b==c) return a*b;
       
       int x=(c+b+1)*2;
       if(a>x) return -1;
       int y=(a+c+1)*2;
       if(b>y) return -1;
       int z=(a+b+1)*2;
       if(c>z) return -1;
       
       return a+b+c;
    }
};
