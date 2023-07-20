class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int>s;

        for(int asteroid : asteroids)
        {
             int flag = 1;
             while(!s.empty() && s.top() > 0 && asteroid < 0)
             {
                 if( abs(asteroid) > s.top())
                 {
                     s.pop();
                     continue;
                 }

                 if( abs(asteroid) == s.top())
                 {
                     s.pop();
                 }

                 flag = 0;
                 break;
             }

             if(flag)
             {
                 s.push( asteroid );
             } 
        }

        vector<int>ans;
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
