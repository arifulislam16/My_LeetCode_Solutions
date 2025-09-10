class Solution {
public:
    vector<vector<int>> generate(int n) {
        if(n==1){return {{1}};}
        else if(n==2){
            return {{1},{1,1}};
        }
        else if(n==3){
            return {{1,},{1,1},{1,2,1}};
        }
        else{
            vector<vector<int>>res;
            res.push_back({1});
            res.push_back({1,1});
            res.push_back({1,2,1});
            vector<int>tmp={1,2,1};
            for(int i=4;i<=n;i++){
                vector<int>cur(tmp.size()+1,0);
                cur[0]=cur[cur.size()-1]=1;
                for(int i=1;i<cur.size()-1;i++){
                    cur[i]=tmp[i-1]+tmp[i];
                }
                tmp=cur;
                res.push_back(cur);
            }
            for(auto&i:res){
                for(auto&j:i){cout<<j<<" ";}
                cout<<"\n";
            }
            return res;
        }
    }
};