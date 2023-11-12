class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        if(str1.length()!=str2.length()) {
            return false;
        }
        if(str1.length()<=2 || str2.length()<=2) {
            return false;
        }
        int n = str1.length();
        string first = "";
        string last = "";
        first += str1.substr(2) + str1.substr(0,2);
        last  += str1.substr(n-2) + str1.substr(0,n-2);
        if(first== str2 || last == str2) {
            return true;
        }
        return false;
    }

};
