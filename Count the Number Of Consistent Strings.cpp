class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char,int>mp;
        for(char ch:allowed){
            mp[ch]+=1;
        }
        int res=0;
        for(string str:words){
            bool ok=true;
            for(char ch:str){
                if(mp[ch]==0){
                    ok=false;break;
                }
            }
            if(ok){res+=1;}
        }
        return res;
    }
};