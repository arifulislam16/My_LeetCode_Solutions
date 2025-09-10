class Solution {
public:
    int balancedStringSplit(string s) {
        int ans=0;
        int tmp=0;
        for(char ch:s){
            if(ch=='R'){tmp+=1;}
            else{tmp-=1;}
            if(tmp==0){ans+=1;}
        }
        return ans;
    }
};