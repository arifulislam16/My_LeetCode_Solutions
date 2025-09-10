class Solution {
public:
    bool checkZeroOnes(string s) {
        int o=0,z=0;
        int b=-1,e=-1;
        int i=0;
        while(i<s.size()){
            if(s[i]=='1'){
                if(b==-1){b=i,e=i;}
                else{e=i;}
            }
            else{
                if(b==-1){;}
                else{
                o=max(o,e-b+1);
                b=-1,e=-1;
                }
            }
            i++;
        }
      if(b!=-1)  {o=max(o,e-b+1);}
      b=-1,e=-1,i=0;
      while(i<s.size()){
          if(s[i]=='0'){
              if(b==-1){b=i,e=i;}
              else{e=i;}
          }
          else{
              if(b==-1){;}
              else{
              z=max(z,e-b+1);b=e=-1;
              }
          }
          i++;
      }
      if(b!=-1){z=max(z,e-b+1);}
      cout<<o<<" "<<z<<'\n';
      return o>z;
    }
};