class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
         int ans=0;
         for(char c1:jewels){
             for(char c2:stones){
                 if(c1==c2){ans+=1;}
             }
         }   
         return ans;
    }
};