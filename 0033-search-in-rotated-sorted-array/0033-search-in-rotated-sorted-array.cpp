class Solution {
public:
    int BS(vector<int>&a,int l,int h,int x){
        if(l>h){
            return -1;
        }
        int mid=l+(h-l)/2;
        
        if(a[mid]==x){
            return mid;
        }
        if(a[l]<=a[mid]){
            if((a[l]<=x)&&(x<=a[mid])){
                return BS(a,l,mid-1,x);
            }else{
                return BS(a,mid+1,h,x);
            }
        }else{
            if((a[mid]<=x)&&(x<=a[h])){
                return BS(a,mid+1,h,x);
            }else{
                return BS(a,l,mid-1,x);
            }
        }
        
    }
    int search(vector<int>& nums, int target) {
        return BS(nums,0,nums.size()-1,target);
    }
};