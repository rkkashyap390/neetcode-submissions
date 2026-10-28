class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        set<vector<int>> ans;
        for(int i=0; i<n-2; i++){
            int j=i+1, k=n-1, tar=-nums[i];
            while(j<k){
                int x=nums[j], y=nums[k];
                if(x+y<tar) j++;
                else if(x+y>tar) k--;
                else {
                    ans.insert({-tar, x, y});
                    j++;
                    k--;
                }
            }
        }

        vector<vector<int>> res;
        for(auto x: ans) res.push_back(x);
        return res;
    }
};
