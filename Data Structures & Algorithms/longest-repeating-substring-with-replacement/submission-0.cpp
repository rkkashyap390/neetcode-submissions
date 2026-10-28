class Solution {
public:
    // return min replacements needed for mid length of continuous string
    int bs(string &s, int mid) {
        vector<int> cs(26,0);
        for(int i=0; i<mid; i++) cs[s[i]-'A']++;
        int n = s.length();
        int minrep = mid-*max_element(cs.begin(), cs.end());
        for(int i=mid; i<n; i++){
            cs[s[i-mid]-'A']--;
            cs[s[i]-'A']++;
            minrep = min(minrep, mid-*max_element(cs.begin(), cs.end()));
        }
        return minrep;
    }

    int characterReplacement(string s, int k) {
        int n = s.length();
        if(n==0) return 0;
        int l=1, r=n, ans=0;
        while(l<=r){
            int mid = (l+r)/2;
            int minreplacements = bs(s, mid);
            // cout<<mid<<" "<<minreplacements; 
            if(minreplacements <= k){
                ans = mid;
                l = mid+1;
            }else if(minreplacements > k){
                r = mid-1;
            }
            // cout<<" "<<ans<<endl;
        }
        return ans;
    }
};
