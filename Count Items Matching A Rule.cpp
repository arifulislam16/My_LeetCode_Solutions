class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        // type color name
        int res=0;
        for(vector<string>v:items){
            if(ruleKey=="type"){
                if(v[0]==ruleValue){res+=1;}

            }
            else if(ruleKey=="color"){
                if(v[1]==ruleValue){
                    res+=1;
                }
            }
            else if(ruleKey=="name"){
                if(v[2]==ruleValue){
                    res+=1;
                }
            }
        }
        return res;
    }
};