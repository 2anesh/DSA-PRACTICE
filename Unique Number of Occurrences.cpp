class Solution
{
    public:
   bool isFrequencyUnique(int n, int arr[])
    {
        map<int,int> m;
        for (int i=0; i<n; i++)
            m[arr[i]]++;
        set<int> s;
        for (auto i: m)
            if (s.find(i.second)!=s.end())
                return false;
            else s.insert(i.second);
        return true;
    }
};
