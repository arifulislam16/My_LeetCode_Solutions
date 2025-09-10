class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
     unordered_map<string,int>   mp;
     for(string str:arr){
         mp[str]+=1;
     }
     for(string str:arr){
         if(mp[str]==1){
             k-=1;
             if(k==0){
                 return str;
             }
         }
     }
     return "";
    }
};