class Solution{
public:
   
    long long findNumber(long long N){
      
      long long a = 2*N-1;
      //cout<<a<<endl;
      string s = to_string(a);
      string ans = s;
      long long  i = s.length()-1;
      int j=1;
      while(i != 0)
      {
          string part = s.substr(0,i);
          string next = s.substr(i);
          long long sum=0;
          sum=stoll(part);
          sum+=(sum-1);
          part = to_string(sum);
          s = part+next;
        ++j;
            i=s.length()-j;
      }
      return stoll(s);
      
    }
};
