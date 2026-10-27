class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<int>> ans;
        int n = strs.size();
        for(int j=0; j<n; j++){
            vector<int> hash(26, 0);
            for(int i=0; i<strs[j].size(); i++) hash[strs[j][i]-'a']++;
            ans[hash].push_back(j);
        }
        vector<vector<string>> res;
        for(auto a: ans){
            vector<string> curr;
            for(int x: a.second) curr.push_back(strs[x]);
            res.push_back(curr);
        }
        return res;
    }
};
