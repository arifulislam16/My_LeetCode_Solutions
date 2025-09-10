class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int>mp1,mp2;
        string tmp="";
        int i=0;
        while(i<s1.size()){
            if(isspace(s1[i])){
                if(tmp.size()){mp1[tmp]+=1;}
                tmp="";
            }
            else{tmp+=s1[i];}
            i++;
        }
        if(tmp.size()){mp1[tmp]+=1;}
        tmp="";
        i=0;
        while(i<s2.size()){
            if(isspace(s2[i])){
                if(tmp.size()){mp2[tmp]+=1;}
                tmp="";
                }
               
                else{tmp+=s2[i];}
                i++;
        }
        if(tmp.size()){mp2[tmp]+=1;}
        vector<string>res;
        for(pair<string,int>p:mp1){
            if(p.second==1&&mp2[p.first]==0){res.push_back(p.first);}
        }
        for(pair<string,int>p:mp2){
            if(p.second==1&&mp1[p.first]==0){res.push_back(p.first);}
        }
        return res;
    }
};