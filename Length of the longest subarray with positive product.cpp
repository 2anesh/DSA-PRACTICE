class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
            //code here
            int mx_len = 0;
            int neg_count = 0;
            int first_neg_pos=0, last_neg_pos=0;
            int check = 0;
            int siz = 0;
            for(int i=0; i<n; i++){
                if(arr[i] == 0){
                    if(neg_count%2==0){
                        mx_len = max(siz, mx_len);
                    }
                    else{
                        int mp = max((siz-first_neg_pos), (siz-(siz+1-last_neg_pos)));
                        mx_len = max(mp, mx_len);
                    }
                    first_neg_pos = 0;
                    last_neg_pos = 0;
                    check = 0;
                    siz = 0;
                    neg_count = 0;
                }
                else{
                    siz++;
                    if(arr[i]<0){
                        if(check == 0){
                            first_neg_pos = siz;
                            check = 1;
                        }
                        last_neg_pos = siz;
                        neg_count++;
                    }
                }
            }
            if(neg_count%2==0 && arr[n-1]!=0){
                mx_len = max(siz, mx_len);
            }
            else{
                int mp = max((siz-first_neg_pos), (siz-(siz+1-last_neg_pos)));
                mx_len = max(mp, mx_len);
            }
            return mx_len;
        }
};
