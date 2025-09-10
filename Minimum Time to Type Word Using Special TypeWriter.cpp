class Solution {
public:
    int minTimeToType(string word) {
        int res=0;
        char c='a';
        for(char ch:word){
           if(ch>c){
               int val1=abs(ch-c);
               int val2=abs(c-'a')+abs('z'-ch)+1;
               res+=min(val1,val2)+1;
               c=ch;
           }
           else{
               int val1=abs(ch-c);
               int val2=abs(c-'z')+1+abs('a'-ch);
               res+=min(val1,val2)+1;
               c=ch;
           }
        }
        return res;
    }
};