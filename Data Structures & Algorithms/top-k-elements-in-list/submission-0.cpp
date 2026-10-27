class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) mp[nums[i]]++;
        vector<pair<int,int>> q;
        for(auto p: mp){
            q.push_back({p.second, p.first});
        }
        vector<int> ans;
        sort(q.begin(), q.end(), greater<>());
        for(int i=0; i<k; i++) ans.push_back(q[i].second);
        return ans;
    }
};
