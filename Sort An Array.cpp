class Solution {
public:
void merge(int b,int ml,int mr,int e,int arr[]){
  int d1=ml-b+1,d2=e-mr+1;
  int i=0,j=0;
  int tmp[d1+d2];
  int tb=b,te=e;
 // cout<<b<<" "<<ml<<"  -  "<<mr<<"  "<<e<<'\n';
  while(b<=ml&&mr<=e){
    if(arr[b]<=arr[mr]){tmp[i++]=arr[b++];}
    else{tmp[i++]=arr[mr++];}
  }
  while(b<=ml){tmp[i++]=arr[b++];}
  while(mr<=e){tmp[i++]=arr[mr++];}
 // cout<<"\n------------\n";
  
  for(int i=0,j=tb;i<d1+d2;i++,j++){
    arr[j]=tmp[i];
  }
  
 // cout<<"\n-------------\n";
  
}
void build(int b,int e,int arr[]){
  if(b>e||b==e){return ;}
  int mid=b+(e-b)/2;
  build(b,mid,arr);
  build(mid+1,e,arr);
  merge(b,mid,mid+1,e,arr);
  return;
}
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        int arr[n];for(int i=0;i<nums.size();i++){arr[i]=nums[i];}
        build(0,n-1,arr);
        vector<int>res(n,0);for(int i=0;i<n;i++){res[i]=arr[i];}
        return res;
    }
};