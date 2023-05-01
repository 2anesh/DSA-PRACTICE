class Solution {
public:
    double average(vector<int>& salary) {
        
        double minElement=*min_element(salary.begin(),salary.end());
        double maxElement=*max_element(salary.begin(),salary.end());
        int sum=0;
       for(int i=0;i<salary.size();i++){
           sum+=salary[i];
       }

        return (sum-(minElement+maxElement))/(1.0 *(salary.size()-2));

    }
};
