class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int res=0;
        for(string str:sentences){
            int ans=0;
            for(char ch:str){
                if(isspace(ch)){ans+=1;}
            }
            res=max(res,ans+1);
        }
        return res;
    }
};