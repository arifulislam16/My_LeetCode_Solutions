class Solution {
public:
struct node{
    bool leaf;
    unordered_map<char,node*>child;
};
node* getnode(){
  node* tmp=new node();
  tmp->leaf=false;
  return tmp;
}
void insert(node* root,string &s){
    node* tmp=root;
    for(char ch:s){
        if(tmp->child.find(ch)==tmp->child.end()){
            tmp->child[ch]=getnode();
        }
        tmp=tmp->child[ch];
    }
    tmp->leaf=true;
    return ;
}
bool ok(node* root,string &s){
    node* tmp=root;
    for(char ch:s){
        if(tmp->child.find(ch)==tmp->child.end()){
            return false;
        }
        tmp=tmp->child[ch];
    }
    return true;
}
    int countPrefixes(vector<string>& words, string s) {
      node* root=getnode();
      insert(root,s);
      int cnt=0;
      for(string str:words){
          if(ok(root,str)){
              cnt+=1;
          }
      }
      return cnt;
    }
};