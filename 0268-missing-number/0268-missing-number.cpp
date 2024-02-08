class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size() ;
        int rs= n*(n+1)/2;
        int s=accumulate(nums.begin(),nums.end(),0);
        return (rs-s);
    }
};