class Solution {
public:
    bool check(map<char,int>& tt, map<char,int>& ss){
        for(auto el: tt){
            if(el.second > ss[el.first]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        map<char,int> tt, ss;
        int nt=t.length(), ns=s.length();
        for(int i=0; i<nt; i++) tt[t[i]]++;
        int l=0, r=0, x=0, len=ns;
        bool ok=false;
        
        while(r<ns){
            if(!check(tt,ss)){
                ss[s[r]]++;
                r++;
            }

            while(check(tt,ss)){
                ok = true;
                if(r-l < len){
                    len = r-l;
                    x = l;
                }
                ss[s[l]]--;
                l++;
            }
        }

        if(ok) return s.substr(x, len);
        else return "";
    }
};
