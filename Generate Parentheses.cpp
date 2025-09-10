class Solution {
public:
 vector<string>res;
    void cnt(int b,int e,int n,string s){
        if(b>n||e>n){return ;}
        if(b==n&&e==n){res.push_back(s);return ;}
        if(b==e){
            cnt(b+1,e,n,s+"(");
        }
        if(b>e){
            cnt(b+1,e,n,s+"(");
            cnt(b,e+1,n,s+")");
        }
    }
    vector<string> generateParenthesis(int n) {
       
        cnt(0,0,n,"");
        return res;
    }
};