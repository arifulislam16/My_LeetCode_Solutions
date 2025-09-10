class Solution {
public:
unordered_map<char,int>mp;
    bool checkIfPangram(string sentence) {
        for(char ch:sentence){
            mp[ch]+=1;
        }
        if(mp.size()==26){return true;}
        return false;
    }
};