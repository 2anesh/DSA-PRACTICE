class Solution {
public:
    struct job{
        int start, finish, balance;
    };
    static bool myfunction(job j1, job j2){
        return (j1.finish < j2.finish);
    }
    int binarySeach(job jobs[], int index){
        int m = 0, p = index - 1;
        while(m <= p){
            int mid = (m+p) / 2;
            if(jobs[mid].finish <= jobs[index].start){
                if(jobs[mid+1].finish <= jobs[index].start){
                    m = mid + 1;
                }
                else{
                    return mid;
                }
            }
            else{
                p = mid - 1;
            }
        }
        return -1;
    }
    int maxProfit(job v[], int n){
        sort(v, v+n, myfunction);
        int *table = new int[n];
        table[0] = v[0].balance;
        for(int i=1;i<n;i++){
            int temp = v[i].balance;
            int m = binarySeach(v, i);
            if(m != -1){
                temp += table[m];
            }
            table[i]  = max(temp, table[i-1]);
        }
        int answer = table[n-1];
        delete[] table;
        return answer;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        job v[n];
        for(int i=0;i<n;i++){
            v[i] = {startTime[i], endTime[i], profit[i]};
        }
        int total = maxProfit(v, n);
        return total ;
    }
};
