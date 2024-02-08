// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bs(int l,int h,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(isBadVersion(l+(h-l)/2)){
            ans=mid;
            return bs(l,mid-1,ans);
        }
        return bs(mid+1,h,ans);
    }
    int firstBadVersion(int n) {
        int ans=-1;
        return bs(1,n,ans);
    }
};