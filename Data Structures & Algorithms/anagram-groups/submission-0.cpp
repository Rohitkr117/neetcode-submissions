class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for(string s : strs){
            string newstr = s;
            sort(s.begin(), s.end());
            hash[s].push_back(newstr);
        }
        vector<vector<string>> ans;
        for(auto &[a, anagram] : hash){
            ans.push_back(anagram);
        }
        return ans;
    }
};
