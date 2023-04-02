class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int> x;
        for(auto spell : spells){
            // spell*potion <= success
            // potion <= success/spell
            // potion = ceil(success/spell)
            // Both are equivalent
            // potion = (success+(spell-1))/spell
            long long potionRequired = (success+(spell-1))/spell;   
            auto it = lower_bound(potions.begin(),potions.end(),potionRequired);
            x.push_back((potions.end()-it));
        }
        return x;
    }
};
