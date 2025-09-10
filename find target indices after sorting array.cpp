class Solution {
public:
struct comp{
    bool operator()(const int a,const int b)const{
        return a<b;
    }
};
int getb(vector<int>&v,int tar){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]>=tar){e=mid-1;}
        else{b=mid+1;}
    }
    return b;
}
int gete(vector<int>&v,int tar){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]<=tar){b=mid+1;}
        else{e=mid-1;}
    }
    return e;
}
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end(),comp());
        int b=getb(nums,target);
        int e=gete(nums,target);
        vector<int>res;
        for(int i=b;i<=e;i++){res.emplace_back(i);}
        return res;
    }
};