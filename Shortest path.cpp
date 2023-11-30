class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        int edge=0;
        while(n!=1)
        {
            if(n%3==0)
            {
                n=n/3;
                edge++;
            }
            else
            {
                n--;
                edge++;
            }
        }
        return edge;
    }
};
