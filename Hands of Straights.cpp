bool isStraightHand(int n, int g, vector<int> &hand) 
    {
        // code here
        
       //checking is it possible or not at intial change
        if( n%g != 0 ) return false;
        
        //taking a map for storing in frequency
        map<int,int>mp;
        
        for(auto it:hand)
        {
            mp[it]++;
        }
        
        //Caluclating how many sets are there
        int total_sets = n/g;
        
        int ans = 0;

        for(int i = 0; i<total_sets; i++ )
        {
            int start_ele = (mp.begin())->first;
            int flag = 0;
            int k =g;
            
            while(k--)
            {
                if(mp[start_ele]>0)
                {
                    mp[start_ele]--;
                    if(mp[start_ele]==0)
                    {
                        mp.erase(start_ele);
                    }
                }
                else
                {
                    flag = 1;
                    break;
                }
                start_ele++;
            }
            
            if(flag==1)
            {
                return false;
            }
            else
            {
                ans++;
            }
        }
        
        if(ans==total_sets)
        {
            return true;
        }
        return false;
    }
