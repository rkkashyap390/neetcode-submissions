class Solution {
public:

    string encode(vector<string>& strs) {
        string x;
        for(auto str: strs){
            int l = str.length();
            x += to_string(l) + "#" + str;
        }
        return x;
    }

    vector<string> decode(string s) {
        vector<string> x;
        for(int i=0; i<s.size();){
            string cnt;
            while(s[i]!='#') cnt+=s[i++];
            i++;
            int cc = stoi(cnt);
            x.push_back(s.substr(i, cc));
            i += cc;
        }
        return x;
    }
};
