class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        if(s1.size()!=s2.size())
        return 0;
       int i=0;
       int j=0;
       int n=s1.size();
       int count=0;
       while(i<s1.size()&&j<s2.size()){
           int curri=i;
        //   cout<<i<<" "<<j<<"\n";
        count++;
           int currj=j;
           if(s1[i]==s2[j])
           while(s1[i]==s2[j]){
               
               i=(i+1)%n;
               j=(j+1)%n;
               if(i==curri&&j==currj)
               return true;
           }
          else {
               j=(j+1)%n;
            //   j;
           }
           if(count>2*n)
           return 0;
       }
       return false;
    }


};
