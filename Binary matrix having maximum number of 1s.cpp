class Solution {
public:
    vector<int> findMaxRow(vector<vector<int>> arr, int n) 

    {

        int pos = 0, c = 0, i = 0, j = n-1;

        

        while(i < n && j >= 0)

        {

            if(arr[i][j]) pos = i;

            

            while(j >= 0 && arr[i][j])

            {

                j--;

            }

            

            c = n-j-1;

            i += 1;

        }

        

        return {pos, c};

    }


};
