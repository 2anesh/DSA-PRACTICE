class Solution {

  public:

    int solve(int n, int k, vector<int> &arr) {

        // code here

        int sum=0,t=0,ans=1;

        vector<int>v;

        for(int i=0;i<n;i++)

            sum+=arr[i];

         for(int i=2;i<=sqrt(sum);i++)

         if(sum%i==0){

         v.push_back(i);

         if(i!=(sum/i))

         v.push_back(sum/i);

         }

         v.push_back(sum);

         sum=0;

         for(int i=v.size()-1;i>=0;i--){

             t=0;

             for(int j=0;j<arr.size();){

                if(arr[j]%v[i]==0){

                t++;

                j++;

                }

                else{

                    sum=-1;

                    while(j<arr.size() && sum%v[i]!=0){

                        if(sum==-1)

                        sum=0;

                        sum+=arr[j];

                        j++;

                    }

                    if(sum%v[i]==0)

                    t++;

                    else break;

                }

             }

                if(t>=k && ans<v[i])

                ans=v[i];

             }

         return ans;

    }

};
