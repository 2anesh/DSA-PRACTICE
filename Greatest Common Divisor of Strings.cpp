class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        string a=str1,b=str2;
        return (a+b == b+a)  ? a.substr(0, gcd(a.length(), b.length())): "";
    }
};
