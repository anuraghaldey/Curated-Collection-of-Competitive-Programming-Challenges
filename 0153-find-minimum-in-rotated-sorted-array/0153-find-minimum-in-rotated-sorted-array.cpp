class Solution {
public:
    int BS(vector<int>&a,int l,int h,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        ans=min(ans,a[mid]);
        if(a[mid]<a[h]){
            return BS(a,l,mid-1,ans);
        }
        return BS(a,mid+1,h,ans);
    }
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        return BS(nums,0,nums.size()-1,ans);
    }
};