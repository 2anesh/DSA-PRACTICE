class Solution {
public:
string FirstNonRepeating(string A){
    // Code here
            int n=A.length();
            string s1="";
            vector<int> v1(26,0);
            queue<char> q1;
            for(int i=0;i<n;i++){
                int ind=A[i]-'a';
                // cout<<ind<<" ";
                v1[ind]++;
                if(v1[ind]==1){
                    q1.push(A[i]);
                    // cout<<q1.front()<<" ";
                }
 
                if(!q1.empty()){
                    // cout<<q1.front();
                    while(!q1.empty()&&v1[q1.front()-'a']>1){
                        q1.pop();
                    }
                    if(q1.empty()){
                        s1+='#';
                    }
                    else
                    s1+=q1.front();
                }
                else{
                    s1+='#';
                }
            }
            return s1;
}
};
 
