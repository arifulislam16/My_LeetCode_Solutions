class Solution {
public:
bool ok(string &s1, string &s2){
    int m1=0,m2=0;
    for(char ch:s1){
        m1|=(1<<(ch-'a'));
    }
    for(char ch:s2){
        m2|=(1<<ch-'a');
    }
    return m1==m2;
}
    int similarPairs(vector<string>& words) {
        int res=0;
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                if(ok(words[i],words[j])){res+=1;}
            }
        }
        return res;
    }
};