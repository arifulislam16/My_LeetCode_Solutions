class Solution {
public:
vector<double>res;
  bool dfs(string u,string tar,map<string,bool>&visit,
  map<string,vector<pair<string,double>>>&g,double ans){
      if(u==tar){res.push_back(ans);return true;}
      visit[u]=true;
      for(pair<string,double>p: g[u]){
          string v=p.first;
          double cost=p.second;
          if(visit[v]==false){
              if(dfs(v,tar,visit,g,ans*cost)){return true;}
          }
      }
      return false;
  }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
       map<string,vector<pair<string,double>>>g;
       // a/b   ==   a <--- b;
       for(int i=0;i<equations.size();i++){
           string u=equations[i][1];
           string v=equations[i][0];
           double cost=values[i];
           g[u].push_back({v,cost});
           g[v].push_back({u,1.00/cost});
       }
    for(int i=0;i<queries.size();i++){
        string u=queries[i][1];
        string v=queries[i][0];
        bool ok=false;
        if(g.find(u)==g.end() || g.find(v)==g.end()){
            ok=false;
            res.push_back(-1.0000);
        }
        else{
            map<string,bool>visit;
            ok=dfs(u,v,visit,g,1.000);
            if(!ok){res.push_back(-1.0000);}
        }
    }
    return res;
    }
};