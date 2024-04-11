class Solution {
public:
    int check(vector<int>&a,int mid){
        int c=0;
        int n=a.size();
        for(int i=0;i<n;i++){
            (a[i]<mid)?c++:c=c;
        }
        return c<mid;
    }
    int bs(vector<int>&a,int l,int h,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(a,mid)){
            ans=mid;
            return bs(a,mid+1,h,ans);
        }
        return bs(a,l,mid-1,ans);
    }
    int findDuplicate(vector<int>& nums) {
       int l=1,h=*max_element(nums.begin(),nums.end()),ans=-1;
       return bs(nums,l,h,ans);
    }
};