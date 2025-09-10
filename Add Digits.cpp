class Solution {
public:
int get(int num){
    int val=0;
    if(num<=9){return num;}
    while(num>0){
        val+=num%10;
        num/=10;
    }
    return get(val);
}
    int addDigits(int num) {
        return get(num);
    }
};