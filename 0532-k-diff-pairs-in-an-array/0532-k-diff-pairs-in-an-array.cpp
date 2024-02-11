class Solution {
public:
    int BS(vector<int>&a,int l,int h,int x){
        if(l>h){
            return -1;
        }
        int mid=l+(h-l)/2;
        if(a[mid]==x){
            return mid;
        }else if(a[mid]>x){
            return BS(a,l,mid-1,x);
        }
        return BS(a,mid+1,h,x);
    }
    int findPairs(vector<int>& nums, int k) {
        set<pair<int,int>>s;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(BS(nums,i+1,nums.size()-1,nums[i]+k)!=-1){
                s.insert({nums[i],nums[i]+k});
            }
        }
        return s.size();
    }
};