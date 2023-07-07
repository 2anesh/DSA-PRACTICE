class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int gap = (n+m) / 2 + (n+m) % 2;

        while (gap > 0)
        {
            int st = 0;
            int end = st + gap;
    
            while (end < n+m)
            {
                // st in arr1 and end in arr2
                if (st < n && end >= n)
                {
                    if(arr1[st]> arr2[end - n])
                    swap(arr1[st], arr2[end - n]);
                }
                // st in arr2 and end in arr2
                else if (st >= n)
                {
                    if(arr2[st-n] > arr2[end-n])
                    swap(arr2[st - n], arr2[end - n]);
                }
                // st in arr1 and end in arr1
                else
                {
                    if(arr1[st] >  arr1[end])
                    swap(arr1[st], arr1[end]);
                }
    
                st++;
                end++;
            }
    
            if (gap == 1)
            {
                break;
            }
    
            gap = (gap / 2) + (gap % 2);
            } 
        }
};
