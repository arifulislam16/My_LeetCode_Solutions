class Solution {
public:
    vector<int> getRow(int n) {
            if(n==0){return {1};}
            else if(n==1){return {1,1};}
            else if(n==2){return {1,2,1};}
            else if(n==3){return {1,3,3,1};}
            vector<int>tmp={1,3,3,1};// n=3;
            for(int i=3;i<n;i++){
                vector<int>cur(tmp.size()+1,0);
                cur[0]=cur[cur.size()-1]=1;
                for(int j=1;j<cur.size()-1;j++){
                    cur[j]=tmp[j-1]+tmp[j];
                }
                tmp=cur;
            }
            return tmp;

    }
};