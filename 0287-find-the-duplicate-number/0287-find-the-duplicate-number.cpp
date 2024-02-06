class Solution {
public:
    int check(vector<int>a,int mid){
        int c=0;
        for(auto x:a){
            if(x<=mid){
                c++;
            }
        }
        return (c<=mid);
    }
    int bs(vector<int>&a,int l,int h){
        return l>h?l:(check(a,(l+(h-l)/2))?bs(a,(l+(h-l)/2)+1,h):bs(a,l,(l+(h-l)/2)-1));
    }
    int findDuplicate(vector<int>& nums) {
        return bs(nums,1,nums.size()-1);
    }
};