class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,vector<string>>mp;
        vector<string>city;
        for(vector<string>&p:paths){
            string u=p[0];
            string v=p[1];
            mp[u].push_back(v);
            city.push_back(u);
            city.push_back(v);
        }
        string res;
        for(string str:city){
            if(mp[str].size()==0){
                res=str;break;
            }
        }
        return res;
    }
};