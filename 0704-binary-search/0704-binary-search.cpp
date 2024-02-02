class Solution {
public:
    int bs(vector<int>a,int l,int h,int x,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(a[mid]==x){
            ans=mid;
            return bs(a,l,mid-1,x,ans);
        }else if(a[mid]>x){
            return bs(a,l,mid-1,x,ans);
        }else{
            return bs(a,mid+1,h,x,ans);
        }
    }
    int search(vector<int>& nums, int target) {
        int ans=-1;
        return bs(nums,0,nums.size()-1,target,ans);
    }
};