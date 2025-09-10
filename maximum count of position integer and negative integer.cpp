class Solution {
public:
int  max(int a,int b){return (a>b)?a:b;}
int get(vector<int>&v){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]<0){b=mid+1;}
        else{e=mid-1;}
    }
    return b;
}
int getpos(vector<int>&v){
    int b=0,e=v.size()-1;
    while(b<=e){
        int mid=b+(e-b)/2;
        if(v[mid]>0){e=mid-1;}
        else{b=mid+1;}
    }
    return b;
}
    int maximumCount(vector<int>& nums) {
        int neg=get(nums);
        //cout<<neg<<'\n';
        int pos=getpos(nums);
        //cout<<pos<<"\n";
        return max(neg,nums.size()-pos);
    }
};