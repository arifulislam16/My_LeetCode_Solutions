class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res="";
    int i=0,j=0,k=0;
    while(i<word1.size()&&j<word2.size()){
        if(k&1){res+=word2[j++];}
        else{res+=word1[i++];}
        k++;
    }
    while(i<word1.size()){
        res+=word1[i++];
    }
    while(j<word2.size()){
        res+=word2[j++];
    }
    return res;
    }
};