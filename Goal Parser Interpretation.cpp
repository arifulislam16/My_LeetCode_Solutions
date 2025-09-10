class Solution {
public:
    string interpret(string&s) {
        string res="";
        int i=0;
        while(i<s.size()){
            if(s[i]=='G'){res+='G';i+=1;}
else if(s[i]=='('&&i+1<s.size()&&s[i+1]==')'){res+='o';i+=2;}
else if(s[i]=='('&&i+1<s.size()&&s[i+1]=='a'){
    res+="al";
    i+=4;
}
        }
        return res;
    }
    
};