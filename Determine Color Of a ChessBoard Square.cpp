class Solution {
public:
    bool squareIsWhite(string s) {
       //  abs(1-8) 
       int a=s[0]-'a';
       int b=s[1]-'0';
       if(a&1 && b&1){return true;}
       if(a%2==0&&b%2==0){return true;}
       return false;
    }
};