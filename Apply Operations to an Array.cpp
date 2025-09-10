class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1]){nums[i]*=2;nums[i+1]=0;}
        }
        vector<int>res;
        int zero=0;
        for(auto&i:nums){
    //(i!=0){res.emplace_back(i);}
    if(i==0){zero+=1;}
    else{
        res.emplace_back(i);
    }

        }
        while(zero--){
            res.emplace_back(0);
        }
        return res;
    }
};