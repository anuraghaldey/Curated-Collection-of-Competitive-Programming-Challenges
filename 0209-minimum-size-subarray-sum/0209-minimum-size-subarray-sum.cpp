class Solution {
public:
    int check(int mid,vector<int>a,int k){
        
        int sum=0;
        if(mid==a.size()){
            int s=accumulate(a.begin(),a.end(),0);
            return s>=k;
        }
        for(int i=0;i<mid;i++){
            sum+=a[i];
        }
        if(sum>=k){
            return true;
        }
        int q=0;
        for(int i=mid;i<a.size();i++){
            sum-=a[q++];
            sum+=a[i];
            if(sum>=k){
                return true;
            }
        }
        return false;
    }
    int bs(vector<int>&a,int l,int h,int k,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,k)){
            ans=mid;
            return bs(a,l,mid-1,k,ans);
        }
        return bs(a,mid+1,h,k,ans);
    }
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=1;
        int h=nums.size();
        int ans=0;
        return bs(nums,l,h,target,ans);
    }
};