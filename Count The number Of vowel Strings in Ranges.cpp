class Solution {
public:

bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||
    ch=='o'||ch=='u';
}
bool ok(string &s){
    if(isvowel(s[0])&&isvowel(s[s.size()-1])){
        return true;
    }
    return false;
}
    int vowelStrings(vector<string>& words, int left, int right) {
        int res=0;

        for(int i=left;i<=right;i++){
            if(ok(words[i])){res+=1;}
        }
        return res;
    }
};