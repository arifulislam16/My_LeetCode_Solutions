class Solution {
public:
bool isopen(char ch){
    return ch=='('||ch=='{'||ch=='[';
}
    bool isValid(string s) {
        stack<char>st;
        int i=0;
        while(i<s.size()){
            if(isopen(s[i])){
                st.push(s[i]);
            }
            else{
                if(st.size()==0){return false;}
                if(st.top()=='('&&s[i]==')'){st.pop();}
                else if(st.top()=='{'&&s[i]=='}'){st.pop();}
                else if(st.top()=='['&&s[i]==']'){st.pop();}
                else{return false;}
            }
            i++;
        }
        return st.size()==0;
    }
};