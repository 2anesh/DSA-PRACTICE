class Solution{
public:
    bool isLucky(int n) {
        int whichPlaceNumbersDeleted = 2; // (n=5) => 1,2,3,4,5
        int totalNumberRemains = n;
        while(totalNumberRemains>=whichPlaceNumbersDeleted)
        {
            if(totalNumberRemains%whichPlaceNumbersDeleted==0)return 0; // last Number will be removed i.e given number
            
            totalNumberRemains = totalNumberRemains - totalNumberRemains/whichPlaceNumbersDeleted;
            
            whichPlaceNumbersDeleted++;
        }
        return 1;
    }
};
