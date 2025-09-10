class Solution {
public:
    int maxPower(string s) {
        int ans=1,mx=0;
        if(s.size()==1){return 1;}
        for(int i=0;i<s.size()-1;i++){
            if(s[i]==s[i+1]){ans+=1;}
            else{mx=max(ans,mx);ans=1;}
        }
        return max(mx,ans);
    }
};