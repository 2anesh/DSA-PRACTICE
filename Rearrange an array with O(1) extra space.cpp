class Solution

{

public:

    void arrange_cycle(long long arr[], int n, int curr_ind)

    {

        int want_ind,ele;

        int start_ind = curr_ind;

        int start = arr[start_ind];

        //  start is the element from where we enter the cycle

        while (true)

        {

            // our curr element at the position

            ele = arr[curr_ind];

            

            want_ind = arr[curr_ind];

            

            // this condition checks the end of cycle and if the arr requires no change for this ind;

            if (want_ind == start_ind)

            {

    

                arr[curr_ind] = start + n;

                return;

            }

            //  now do the op

            arr[curr_ind] = arr[want_ind] + n;

            

        

            curr_ind = ele;

        }

    }

    void arrange(long long arr[], int n)

    {

        // Your code here

        

        for(int i=0; i<n;i++){

            if(arr[i] < n){

                arrange_cycle(arr,n,i);

            }

        }

        for(int i=0; i<n;i++){

            arr[i] -=n;

        }

        

    }

};

