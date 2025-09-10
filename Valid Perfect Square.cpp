class Solution {
public:
    bool isPerfectSquare(int num) {
        long long b=1,e=(num);
        while(b<=e){
            long long  mid=b+(e-b)/2;
            if(mid*mid==num){return true;}
            if(mid*mid>num){e=mid-1;}
            else{b=mid+1;}
        }
        return false;
    }
};