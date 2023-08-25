class Solution
{
public:
    int isPalindrome(string s)
    {
        string t = s;
        reverse(s.begin(), s.end());
        return s == t;
    }
};
