class NumArray {
public:
   //65536
    int st[67000];
    int N;
    void build(int b,int e,int i,vector<int>&a,int st[]){
        if(b>e){return ;}
        else if(b==e){st[i]=a[b];return;}
        int mid=b+(e-b)/2,l=i*2+1,r=i*2+2;
        build(b,mid,l,a,st);
        build(mid+1,e,r,a,st);
        st[i]=st[l]+st[r];
        return;
    }
    NumArray(vector<int>& nums) {
        N=nums.size();
        build(0,nums.size()-1,0,nums,st);
    }
    void udate(int b,int e,int i,int idx,int val){
        if(b>e||b>idx||e<idx){return ;}
        else if(b>=idx&&e<=idx){st[i]=val;return;}
        int mid=b+(e-b)/2,l=i*2+1,r=i*2+2;
        udate(b,mid,l,idx,val);
        udate(mid+1,e,r,idx,val);
        st[i]=st[l]+st[r];
    }
    void update(int index, int val) {
        udate(0,N-1,0,index,val);
    }
    int q(int b,int e,int i,int qs,int qe){
        if(b>e||b>qe||e<qs){return 0;}
        else if(b>=qs&&e<=qe){return st[i];}
        int mid=b+(e-b)/2,l=i*2+1,r=i*2+2;
        int lq=q(b,mid,l,qs,qe);
        int rq=q(mid+1,e,r,qs,qe);
        return lq+rq;
    }
    int sumRange(int left, int right) {
        return q(0,N-1,0,left,right);
        return 0;
    }
};