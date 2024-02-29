class Solution {
public:
    int check(int mid,vector<int>&a,int k){
        int sum=0;
        
        for(int i=0;i<a.size();i++){
            sum+=min(mid,a[i]);
        }
        return abs(k-sum);
    }
    int bs(vector<int>&a,int l,int h,int &ans,int k){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,k)<=check(mid+1,a,k)){
            ans=mid;
            return bs(a,l,mid-1,ans,k);
        }
        return bs(a,mid+1,h,ans,k);
    }
    int findBestValue(vector<int>& a, int k) {
        int l=0,h=*max_element(a.begin(),a.end());
        int ans=-1;
        return bs(a,l,h,ans,k);
    }
};