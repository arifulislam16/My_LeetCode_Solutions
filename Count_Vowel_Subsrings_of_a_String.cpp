class Solution {
public:
char vowel[5]={'a','e','i','o','u'};
bool isvowel(char ch){
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}
bool ok(string &s){
    unordered_map<char,int>mp;
    for(char ch:s){mp[ch]+=1;}
    for(char ch:vowel){if(mp[ch]==0){return false;}}
    for(char ch:s){
        if(!isvowel(ch)){return false;}
    }
    return true;

}
    int countVowelSubstrings(string word) {
        int res=0;
        for(int i=0;i<word.size();i++){
            for(int j=i+1;j<word.size();j++){
                string tmp=word.substr(i,j-i+1);
                if(ok(tmp)){res+=1;}
            }

        }
        return res;
    }
};