class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> p;
        int n=s.length(), ans=0, l=0, r=0;
        while(r<n){
            if(p.find(s[r]) == p.end()){
                p.insert(s[r]);
                r++;
            } else{
                while(s[l]!=s[r]){
                    p.erase(s[l]);
                    l++;
                }
                l++;
                r++;
            }
            // cout<<s.substr(l, r-l)<<endl;
            ans = max(ans, r-l);
        }
        return ans;
    }
};
