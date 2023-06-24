class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){   
        int c=0;
        if(k>str.length())
        return 0;
        for(int i=0; i<n; i++)
        {
            if(str.substr(0,k)==arr[i].substr(0,k))
            c++;
        }
        
        return c;
        
    }
};
