class Solution {
  public:
    int findMoves(int n, vector<int> c, vector<int> p) {
        vector<int>v ; 
        sort(c.begin(),c.end()) ; // 2 2 6 6 
        sort(p.begin(),p.end()) ; // 1 2 3 6
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum=sum+abs(c[i]-p[i]) ; 
        }
        return sum ;
    }
};
