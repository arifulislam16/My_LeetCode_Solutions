class Solution {
public:
struct node{
    node* child[26];
    int pre;
};
node* getnode(){
    node* tmp=new node();
    tmp->pre=0;
    for(int i=0;i<26;i++){tmp->child[i]=nullptr;}
    return tmp;
}
node* root=getnode();

void insert(node* root,string& s){
    node* tmp=root;
    for(char ch:s){
        if(tmp->child[ch-'a']==nullptr){tmp->child[ch-'a']=getnode();}
        tmp=tmp->child[ch-'a'];
        tmp->pre+=1;
      //  cout<<tmp->pre<<"\n";
    }
    return ;
}

    string longestCommonPrefix(vector<string>& strs) {
        for(string s:strs){insert(root,s);}
        string s=strs[0];
        int sz=strs.size();
        node* tmp=root;
        int ans=0;
        for(int i=0;i<s.size();i++){
            tmp=tmp->child[s[i]-'a'];
            //cout<<tmp->pre<<"\n";
            if(tmp->pre==sz){ans=i+1;}
            else{break;}
        }
        return s.substr(0,ans);
        return "";
    }
};