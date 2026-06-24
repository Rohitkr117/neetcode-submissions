class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums){
            freq[i]++;
        }
        vector<vector<int>> v(nums.size() + 1);
        for(auto &[num, count]: freq){
            v[count].push_back(num);
        }
        vector<int> ans;
        for(int j = v.size()-1; j > 0; j--){
            auto num = v[j];
            for(int i: num){
                ans.push_back(i);
            if(ans.size() == k){
                return ans;
            }
            }
        }
        return ans;
    }
};
