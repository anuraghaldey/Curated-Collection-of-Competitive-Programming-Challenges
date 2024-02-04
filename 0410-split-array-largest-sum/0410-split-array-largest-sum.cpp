class Solution {
public:
    
    int check(int mid,vector<int>a){
        int ans=0;
        int sTn=0;

        for(int i=0;i<a.size();i++){
           if((sTn+a[i])<=mid){
               sTn+=a[i];
           }else{
               ans++;
               sTn=a[i];
           }
        }
        return ++ans;
    }
    int BSonANS(vector<int>a,int l,int h,int k){
        return l>h?l:(check((l+(h-l)/2),a)>k?BSonANS(a,(l+(h-l)/2)+1,h,k):BSonANS(a,l,(l+(h-l)/2)-1,k));
    }
    int findPages(vector<int>& a, int n, int k) {
        int l=*max_element(a.begin(),a.end());
        int h=accumulate(a.begin(),a.end(),0);
        return k>n?-1:BSonANS(a,l,h,k);
    }
    int splitArray(vector<int>& nums, int k) {
        return findPages(nums,nums.size(),k);
    }
};