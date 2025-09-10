class Solution {
public:
    int mySqrt(int x) {
        long long  b=1,e=x;
        while(b<=e){
            long long mid=b+(e-b)/2;
            if(mid*mid==x){return mid;}
            else if(mid*mid>x){e=mid-1;}
            else{b=mid+1;}
        }
        return e;
    }
};