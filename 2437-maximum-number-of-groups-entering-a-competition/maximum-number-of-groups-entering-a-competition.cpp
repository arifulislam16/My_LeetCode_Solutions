class Solution {
public:
// again submitting
bool ok(long long  r,long long  n){
    long long res=r*(r+1)/2LL;
    return res<=n;
}
    int maximumGroups(vector<int>& grades) {
        long long res=1LL;
        long long  b=1,e=1e5;
        while(b<=e){
            long long  mid=b+(e-b)/2;
            if(ok(mid,grades.size())){res=mid;b=mid+1;}
            else{e=mid-1;}
        }
        return res;
    }
};