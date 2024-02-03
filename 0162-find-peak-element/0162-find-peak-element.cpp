class Solution {
public:
    int BS(vector<int>&a,int l,int h,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(a[mid]>a[mid-1]&&a[mid]>a[mid+1]){
            ans=mid;
            return ans;
        }
        return (((a[mid]<a[mid-1])&&(a[mid]<a[mid+1]))||(a[mid]>a[mid+1]))?
            BS(a,l,mid-1,ans):BS(a,mid+1,h,ans);
        
        
    }
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1||nums[0]>nums[1]){
            return 0;
        }
        
        if(nums[n-1]>nums[n-2]){
            return n-1;
        }
        int ans=-1;
        return BS(nums,1,n-2,ans);
    }
    
};