class Solution {
public:
    int bs(vector<int>&a,int l,int h,int n){
        return (l>=h)?l:((l+h+1)/2*((l+h+1)/2+1)/2<=n)?bs(a,(l+h+1)/2,h,n):bs(a,l,(l+h+1)/2-1,n);
    }
    int maximumGroups(vector<int>& a) {
        return bs(a,0,500,a.size());
    }
};