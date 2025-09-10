class Solution {
public:
string get(string& s){
  while(s.size()){
      if(s[0]=='0'){s.erase(s.begin());}
      else{break;}
  }
  return s;
}
    int numDifferentIntegers(string word) {
        int i=0;
        unordered_map<string,int>mp;
        string tmp="";
        while(i<word.size()){
            if(isdigit(word[i])){tmp+=word[i];}
            else{
                if(tmp.size()){mp[get(tmp)]+=1;}
                tmp="";
            }
            i++;
        }
        if(tmp.size()){mp[get(tmp)]+=1;}
        return mp.size();
    }
};