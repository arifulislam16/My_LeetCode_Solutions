class Solution {
public:
char v[10]={'a','e','i','o','u','A','E','I',
'O','U'};
bool isvowel(char ch){
    //return ch=='A'||ch=='E'||ch==''
    for(int i=0;i<10;i++){
        if(v[i]==ch){return true;}
    }
    return false;
}
    bool halvesAreAlike(string s) {
        string a=s.substr(0,s.size()/2);
        string b=s.substr(s.size()/2);
        int count1=0,count2=0;
       for(int i=0;i<a.size();i++){
           if(isvowel(a[i])){count1+=1;}
           if(isvowel(b[i])){count2+=1;}
       }
       return count1==count2;
        
    }
};