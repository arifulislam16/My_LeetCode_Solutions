class Solution {
public:
struct comp{
bool operator()(const pair<int,string>&p1,
const pair<int,string>&p2)const{
    return p1.first>p2.first;
}
};
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=names.size();
        pair<int,string>p[n];
        for(int i=0;i<n;i++){
            p[i]={heights[i],names[i]};
        }
        sort(p,p+n,comp());
        vector<string>res;
        for(pair<int,string>tmp:p){
            res.push_back(tmp.second);
        }
        return res;
    }
};