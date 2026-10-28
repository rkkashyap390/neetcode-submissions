class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums) s.insert(num);
        int ans = 0;
        for(int num: nums){
            int n1 = num, curr = 0;
            if(s.contains(n1-1)) continue;
            while(s.contains(n1)){
                curr++;
                n1++;
            }
            ans = max(ans, curr);
        }
        return ans;
    }
};
