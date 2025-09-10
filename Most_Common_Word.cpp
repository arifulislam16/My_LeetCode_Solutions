class Solution {
public:
string get(string& s){
    string res="";
    for(char ch:s){
        res+=tolower(ch);
    }
    return res;
}
    string mostCommonWord(string s, vector<string>& ban) {
        unordered_map<string,int>mp,mp2;
        for(string s:ban){mp2[get(s)]++;}
        int i=0;
        string tmp="";
        while(i<s.size()){

            if(isspace(s[i])||ispunct(s[i])){
                if(tmp.size()){
                    if(mp2[get(tmp)]==0){mp[get(tmp)]++;}
                }
                tmp="";
            }
            else{
                tmp+=s[i];
            }
            i++;
        }
        if(tmp.size()){
            if(mp2[get(tmp)]==0){mp[get(tmp)]++;}
        }
        int mx=0;
        string res="";
        for(pair<string,int>p:mp){
            cout<<p.first<<" "<<p.second<<"\n";
            if(mx<p.second){
                mx=p.second;
                res=p.first;
            }
        }
        return res;
    }
};