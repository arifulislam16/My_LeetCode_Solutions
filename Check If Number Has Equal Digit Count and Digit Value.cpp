class Solution {
public:
    bool digitCount(string num) {
        int cnt[10]={0};
        for(int i=0;i<num.size();i++){
            cnt[num[i]-'0']+=1;
        }
        for(int i=0;i<num.size();i++){
            int occur=cnt[i];
            if(num[i]-'0'!=occur){return false;}
        }
        return true;
    }
};