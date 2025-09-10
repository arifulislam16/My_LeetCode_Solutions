class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<s.size();i++){
            if(mp.find(s[i])==mp.end()){mp[s[i]]={i,1};}
            else{mp[s[i]].second+=1;}
        }
        
        for(char ch:s){
            if(mp[ch].second==1){return mp[ch].first;}
        }
        return -1;
    }
};