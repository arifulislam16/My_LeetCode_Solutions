class Solution {
public:
    char repeatedCharacter(string s) {
        int c[26]={0};
        for(char ch:s){
            c[ch-'a']+=1;
            if(c[ch-'a']>1){return ch;}
        }
        return 'a';
    }
};