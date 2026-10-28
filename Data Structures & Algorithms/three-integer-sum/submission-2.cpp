class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        // set<vector<int>> ans;
        for(int i=0; i<n-2; i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j=i+1, k=n-1;
            while(j<k){
                int x=nums[i], y=nums[j], z=nums[k];
                if(x+y+z<0) j++;
                else if(x+y+z>0) k--;
                else {
                    // ans.insert({x, y, z});
                    res.push_back({x, y, z});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                }
            }
        }

        // for(auto x: ans) res.push_back(x);
        return res;
    }
};
