class Solution {
public:
    int countGoodSubstrings(string s) {
        int cnt=0;
        if(s.size()<3){return 0;}
        // 0 1 2 3 4 5 6 7
        for(int i=0;i<=s.size()-3;i++){
            if(s[i]!=s[i+1]&&s[i+1]!=s[i+2]&&s[i]!=s[i+2]){cnt+=1;}
        }
        return cnt;
    }
};