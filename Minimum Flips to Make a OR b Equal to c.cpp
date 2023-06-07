class Solution {
public:
    int minFlips(int a, int b, int c) {
        string A = bitset<32>(a).to_string();
        string B = bitset<32>(b).to_string();
        string C = bitset<32>(c).to_string();
    
        int i=A.size()-1,j=B.size()-1,k=C.size()-1,count=0;
        while(i>=0 && j>=0)
        {
            if(k>=0)
            {
                if(!(A[i]==B[j] && B[j]==C[k]))
                count += abs(A[i]+B[j]-C[k]-'0');
            }
            else
            count += A[i]-'0'+B[j]-'0'; 
            i--;
            j--;
            k--;
        }
        while(i>=0)
        {
            if(k>=0)
            count += abs(A[i]-C[k]);
            else
            count += A[i]-'0'; 
            i--;
            k--;
        }
        while(j>=0)
        {
            if(k>=0)
            count += abs(B[j]-C[k]);
            else
            count += B[j]-'0'; 
            j--;
            k--;
        }
        return count;
    }
};
