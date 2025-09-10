class Solution {
public:
string getinverse(string&s){
    string tmp="";
    for(int i=s.size()-1;i>=0;i--){tmp+=s[i];}
    return tmp;
}
    string reverseWords(string s) {
       string res="",tmp="";
       for(char ch:s){
           if(isspace(ch)){
               cout<<getinverse(tmp)<<"\n";
               res+=getinverse(tmp)+" ";
               tmp="";
               continue;
           }
           tmp+=ch;
       }
       res+=getinverse(tmp);
       return res;
    }
};