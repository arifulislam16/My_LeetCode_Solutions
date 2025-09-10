class Solution {
public:
bool ok(string&word,string&s){
    // 0 1 2 3 4 5 
    if(s.size()>word.size()){
        return false;
    }
    for(int i=0;i<=word.size()-s.size();i++){
        string tmp=word.substr(i,s.size());
        if(tmp==s){return true;}
    }
    return false;
}
    int numOfStrings(vector<string>& patterns, string word) {
        
        int res=0;
        for(string str:patterns){
            if(ok(word,str)){
                res+=1;
            }
        }
        return res;
    }
};