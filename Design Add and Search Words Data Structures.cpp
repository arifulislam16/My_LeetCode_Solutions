class WordDictionary {
public:
  struct node{
      bool leaf;
     node* child[27];
  };
  node* getnode(){
      node* tmp=new node;
      tmp->leaf=false;
      for(int i=0;i<26;i++){
          tmp->child[i]=nullptr;
      }
      return tmp;
  }
  node *root;
    WordDictionary() {
        root=getnode();
    }
    void add(node* root,string&s){
        node* tmp=root;
        for(char ch:s){
            int idx=ch-'a';
            if(tmp->child[idx]==nullptr){
                tmp->child[idx]=getnode();
            }
            tmp=tmp->child[idx];
        }
        tmp->leaf=true;
        return ;
    }
    void addWord(string word) {
        add(root,word);
    }
    bool dfs(node* root,string &s,int i){
        if(i==s.size()){
            return root->leaf==true;
        }
    if(s[i]=='.'){
        for(int j=0;j<26;j++){
            if(root->child[j]!=nullptr){
                if(dfs(root->child[j],s,i+1)){return true;}
            }
        }
        return false;
    }
    else{
        int idx=s[i]-'a';
        if(root->child[idx]!=nullptr){return dfs(root->child[idx],s,i+1);}
        return false;
    }
    }
    bool search(string word) {
        return dfs(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */