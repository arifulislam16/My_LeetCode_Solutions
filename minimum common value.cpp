class Solution {
public:
int get(vector<int>&v,int x){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]==x){return 1;}
        else if(v[mid]>x){e=mid-1;}
        else{b=mid+1;}
    }
    return -1;
}
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int x:nums1){
            if(get(nums2,x)!=-1){return x;}
        }
        return -1;
    }
};