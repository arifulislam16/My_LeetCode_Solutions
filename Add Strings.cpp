class Solution {
public:
    string addStrings(string num1, string num2) {
        string res="";
        if(num1.size()<num2.size()){
            string tmp="";
            for(int i=0;i<num2.size()-num1.size();i++){tmp+='0';}
            tmp+=num1;
            num1=tmp;
        }
      else if(num2.size()<num1.size()){
         string tmp="";
         for(int i=0;i<num1.size()-num2.size();i++){tmp+='0';}
        tmp+=num2;
        num2=tmp;
     }
     int hand=0;
     for(int i=num1.size()-1;i>=0;i--){
         int val=(num1[i]-'0')+(num2[i]-'0')+hand;
         if(val>=10){res+=to_string(val%10);hand=val/10;}
         else{res+=to_string(val);hand=0;}
     }
     if(hand){res+=to_string(hand);}
     reverse(res.begin(),res.end());
     return res;
    }
};