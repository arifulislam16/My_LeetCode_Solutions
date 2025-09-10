class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
       vector<string>res;
       int i=0;
       while(i<s.size()){
           // 0 1 2 3 4 5 6
           //           
           if(s.size()-i<k){
               string tmp=s.substr(i);
               while(tmp.size()<k){tmp+=fill;}
               res.push_back(tmp);break;
           }
           string tmp=s.substr(i,k);
           res.push_back(tmp);
           i+=k;
       }
       return res; 
    }
};