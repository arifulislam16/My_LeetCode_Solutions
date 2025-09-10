class Solution {
public:
bool cnt(int i,int j, string& s1, string& s2){
    if(i>=s1.size()&&j>=s2.size()){return true;}
    if(j>=s2.size()){return false;}
    if(s1[i]==s2[j]){return cnt(i+1,j+1,s1,s2);}
    else if(j-1>=0&&s2[j]==s2[j-1]){
        return cnt(i,j+1,s1,s2);
    }
    else return false;
}
    bool isLongPressedName(string name, string typed) {
        if(typed.size()<name.size()){return false;}
        return cnt(0,0,name,typed);

    }
};