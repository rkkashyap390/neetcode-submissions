class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if(nums[0] < nums[n-1]) return nums[0];
        int l=0, r=n-1, mid, ans=nums[0];
        while(l<=r){
            mid = (l+r)/2;
            if(nums[mid]>=nums[0]) l=mid+1;
            else if(nums[mid]<=nums[n-1]){
                ans = min(ans, nums[mid]);
                r = mid-1;
            }
        }
        return ans;
    }
};
