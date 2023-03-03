class Solution{
public:
    vector<long long int> minimumSquares(long long int L, long long int B)

    {

        // code here

        vector<long long>ans;

        long long k=__gcd(L,B);

        long long n=(L*B)/(k*k);

        ans.push_back(n);

        ans.push_back(k);

        return ans;

    }
};
