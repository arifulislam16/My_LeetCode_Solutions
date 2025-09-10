class Solution {
public:
  struct node{
      bool leaf;
      int val;
      node* child[10];
      //0 - 9;
  };
  node* getnode(){
      node* tmp=new node;
      tmp->val=-1;
      tmp->leaf=false;
      for(int i=0;i<10;i++){
          tmp->child[i]=nullptr;
      }
      return tmp;
  }
  void insert(node* root,int val){
      string s=to_string(val);
      node* tmp=root;
      for(char ch:s){
          int idx=ch-'0';
          if(tmp->child[idx]==nullptr){
              tmp->child[idx]=getnode();
          }
          tmp=tmp->child[idx];
      }
      tmp->leaf=true;
      tmp->val=val;
      return ;
  }
  void dfs(node* root,vector<int>&res){
      if(root==nullptr){return ;}
      if(root->leaf==true){res.emplace_back(root->val);}
      for(int i=0;i<10;i++){
          if(root->child[i]!=nullptr){
              dfs(root->child[i],res);
          }
      }
      return ;
  }
  node* root=getnode();
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++){
            insert(root,i);
        }
        vector<int>res;
        dfs(root,res);
        return res;
    }
};