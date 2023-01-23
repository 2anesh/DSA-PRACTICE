class Solution {
  public:

    string removePair(string s) {

        // code here

        stack<char> q;

        for(auto i : s){

            q.push(i);

            if(q.size() > 1){

                char w = q.top();

                q.pop();

                if(q.top() == w)

                    q.pop();

                else

                    q.push(w);

            }

        }

        string ans = "";

        while(!q.empty()){

            ans += q.top();

            q.pop();

        }

        if(ans.size() == 0)

            return "-1";

        reverse(ans.begin(),ans.end());

        return ans;

    }

 

};
