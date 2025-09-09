//again resubmitting for github repo
class Solution {
public:
bool possible(vector<int>&v,int cap,int days){
    int sm=0,day=1,i=0;
    while(i<v.size()){
        if(sm+v[i]<=cap){sm+=v[i];}
        else{sm=v[i];day++;}
        i++;
    }
    return day<=days;
}
int max(int a,int b){return (a>b)?a:b;}
    int shipWithinDays(vector<int>& weights, int days) {
       int b=0,e=0,res=0;
       for(int x:weights){
           b=max(b,x);
           e+=x;
       }
        //sort(weights.begin(),weights.end());
        while(b<=e){
            int mid=b+(e-b)/2;
            //cout<<"b:e"<<"("<<b<<","<<e<<") ";
            if(possible(weights,mid,days)){
              ///  cout<<"possible : tmp-res:"<<mid<<'\n';
                res=mid;
                e=mid-1;
            }
           
            else{
              //  cout<<"not posible\n";
                b=mid+1;}
        }
        return res;
    }
};