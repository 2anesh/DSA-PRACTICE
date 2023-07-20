class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string S)
    {
       //Your code here
       unordered_map<char,int>mpp;
       for(auto it:S){
           mpp[it]++;
       }
       for(auto it:S){
           if(mpp[it]==1){
               return it;
           }
       }
       return '$';
       
    }

};
