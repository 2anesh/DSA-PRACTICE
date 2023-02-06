class Solution{

public:

 

    long long ans = 0, t;

 

    void dfs(Node *n, int h, bool f)

    {

        if(!n) return;

        

        int d = n->data;

        

        if(f and h==0) ans += d;

        f |= (d==t);

        

        if(f==0)

        {

            if(d>t) dfs(n->left,h,f);

            else dfs(n->right,h,f);

        }

        

        else

        {

            t = -1;

            dfs(n->left,h-1,f);

            dfs(n->right,h+1,f);

        }

    }

 

    long long int verticallyDownBST(Node *root,int target)

    {

        t = target;

        

        dfs(root,0,0);

        

        if(t+1) return -1;

        return ans;

    }

};

