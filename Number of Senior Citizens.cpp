class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res=0;
        for(string str:details){
            int val=str[11]-'0';
            val=(val*10)+(str[12]-'0');
            if(val>60){res+=1;}
        }
        return res;
    }
};