class Solution {
public:
bool ischar(char ch){
    return ch>='a'&&ch<='z';
}
    bool areNumbersAscending(string s) {
        vector<int>res;
        int i=0;
        string tmp="";
        while(i<s.size()){
           if(isspace(s[i])||ischar(s[i])){
               if(tmp.size()){res.push_back(stoi(tmp));}
               tmp="";
           }
           else{
               tmp+=s[i];
           }
           i++;
        }
        if(tmp.size()){res.push_back(stoi(tmp));}
        if(res.size()==0||res.size()==1){return true;}
        for(int i=1;i<res.size();i++){
            if(res[i-1]<res[i]){continue;}
            else{return false;}
        }

        return true;
    }
};