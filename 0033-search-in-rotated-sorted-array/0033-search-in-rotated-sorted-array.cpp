class Solution {
public:
    int BS(vector<int>a,int l,int h,int x,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(a[mid]==x){
            ans=mid;
            return ans;
        }
        if(a[mid]>=a[l]){
            if(x>=a[l]&&x<=a[mid]){
                return BS(a,l,mid-1,x,ans);
            }
            return BS(a,mid+1,h,x,ans);
        }
        if(x>=a[mid]&&x<=a[h]){
            return BS(a,mid+1,h,x,ans);
        }
        return BS(a,l,mid-1,x,ans);
    }
    int search(vector<int>& nums, int target) {
        int ans=-1;
        return BS(nums,0,nums.size()-1,target,ans);
    }
};