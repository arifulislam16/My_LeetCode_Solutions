class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=0;
        int cnt[26]={0};
        for(char ch:chars){cnt[ch-'a']+=1;}
        for(string str:words){
            int cnt1[26]={0};
            bool ok=true;
            for(char ch:str){
                cnt1[ch-'a']+=1;
            }
            for(int i=0;i<26;i++){
                if(cnt1[i]>cnt[i]){ok=false;break;}
            }
            if(ok){res+=str.size();}
        }
        return res;
    }
};