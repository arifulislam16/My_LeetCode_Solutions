class Solution {
public:
string get(string &s){
    int val=0;
    for(char ch:s){val+=ch-'0';}
    return to_string(val);
}
    int getLucky(string s, int k) {
        string res="";
        for(char ch:s){
            int val=(ch-'a') + 1;
           // cout<<ch<<" "<<val<<"\n";
            res+=to_string(val);
        }
        //cout<<res<<"\n";
        int ans=0;
        while(k){
            res=get(res);
            k--;
        }
        return stoi(res);
        return 0;
    }
};