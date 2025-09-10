class Solution {
public:
    bool areOccurrencesEqual(string s) {
        unordered_map<char,int>mp;
        int count=0;
        for(char ch:s){
            mp[ch]+=1;
            count=mp[ch];
        }
        for(pair<char,int>p:mp){
            if(p.second!=count){
                return false;
            }
        }
        return true;
    }
};