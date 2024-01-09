class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            vector<int>p;
            int found=-1;
            while ((found = txt.find(pat, found + 1)) != std::string::npos){p.push_back(found + 1);}
            if (p.empty()){return {-1};}
            return p;
        }
};
