class Solution {
public:
    string reversePrefix(string word, char ch) {
      int pos=-1;
      for(int i=0;i<word.size();i++){
          if(word[i]==ch){
              pos=i;break;
          }
      }
      if(pos==-1){return word;}
      string tmp=word.substr(0,pos+1);
      string res=word.substr(pos+1);
      reverse(tmp.begin(),tmp.end());
      tmp+=res;
      return tmp;

    }
};