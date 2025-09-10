class Solution {
public:
int getsize(int sum,int pre[],int n){
    int b=0,e=n-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(pre[mid]<=sum){b=mid+1;}
        else{e=mid-1;}
    }
    return e+1;
}
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int pre[nums.size()];
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            pre[i]=pre[i-1]+nums[i];
        }
        vector<int>res;
        for(int q:queries){
            int sz=getsize(q,pre,nums.size());
            res.push_back(sz);
        }
        return res;
    }
};