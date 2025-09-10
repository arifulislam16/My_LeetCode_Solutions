class Solution {
public:
    int countSegments(string s) {
     int i=0;
     int count=0;
     string tmp=""   ;
     while(i<s.size()){
         if(isspace(s[i])){
             if(tmp.size()){count+=1;}
             tmp="";
         }
         else{
             tmp+=s[i];
         }
         i++;
     }
     if(tmp.size()){count+=1;}
     return count;
    }
};