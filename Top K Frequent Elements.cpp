class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        // Step 2: Sort the elements based on their frequency
        vector<pair<int, int>> frequencyList(frequencyMap.begin(), frequencyMap.end());

        sort(frequencyList.begin(), frequencyList.end(), [](const auto& a, const auto& b) {
            return a.second > b.second; // Sort in descending order of frequency
        });

        // Step 3: Extract the top k frequent elements from the sorted list
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(frequencyList[i].first);
        }
        return result;
    }
};
