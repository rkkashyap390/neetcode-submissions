class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0, r=n-1, mid;
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]>nums[n-1]) l=mid+1;
            else r=mid;
        }
        if(target<=nums[n-1]) r=n-1;
        else {r=l-1; l=0;}
        
        while(l<r){
            mid = (l+r)/2;
            if(nums[mid]<target) l=mid+1;
            else r=mid;
        }
        if(nums[l]==target) return l;
        return -1;
    }
};
