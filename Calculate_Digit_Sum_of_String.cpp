class Solution {
public:
string getdigit(string &s){
    int val=0;
    for(char ch:s){val+=ch-'0';}
    return to_string(val);
}
    string digitSum(string s, int k) {
      if(s.size()<=k){return s;}
      while(true){
          string tmp="";
          int i=0;
          while(i<s.size()){
              string t=s.substr(i,k);
              tmp+=getdigit(t);
              i+=k;
          }
          if(tmp.size()<=k){return tmp;}
          s=tmp;
      }
      return s;
    }
};