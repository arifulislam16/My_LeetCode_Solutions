class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val=0;
        for(string str:operations){
            if(str=="++X"||str=="X++"){val+=1;}
            else{val-=1;}
        }
        return val;
    }
};