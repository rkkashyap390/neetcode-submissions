class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string x;
        for(int i=0; i<n; i++){
            if((s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9') || (s[i]>='A'&&s[i]<='Z')){
                if(s[i]>='A'&&s[i]<='Z') s[i] = s[i]-'A'+'a';
                x += s[i];
            }
        }
        cout<<x<<endl;
        n = x.length();
        for(int i=0; i<n/2; i++){
            if(x[i]!=x[n-1-i]) return false;
        }
        return true;
    }
};
