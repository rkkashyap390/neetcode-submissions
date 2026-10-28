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
        int l=0, r=0, x=-1, len=ns;

        while(r<ns){
            if(!check(tt,ss)){
                for(auto el: tt){
                    while(el.second > ss[el.first] && r<ns){
                        ss[s[r]]++;
                        r++;
                    }
                }
            }

            while((tt[s[l]]+1<ss[s[l]]) && l<r) {
                ss[s[l]]--;
                l++;
            }

            while(check(tt,ss)){
                if(r-l <= len){
                    len = r-l;
                    x = l;
                }
                ss[s[l]]--;
                l++;
            }
        }
        if(x>-1) return s.substr(x, len);
        else return "";
    }
};
