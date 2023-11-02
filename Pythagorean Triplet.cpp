class Solution{
public:
    // Function to check if the
    // Pythagorean triplet exists or not
bool checkTriplet(int a[], int n) {
        // code here
        for(int i = 0; i < n ; i ++){a[i] *= a[i];}
        sort(a,a+n);
        for(int i = n-1 ; i >= 2 ; i--)
        { int l = 0 ; int h = i-1;
            while(l < h) 
            {  if(a[i] = a[h] + a[l]){ return true;}
                (a[i] > a[h] + a[l])? l++ : h-- ;
            }
        }
        return false ; 
    }
};
