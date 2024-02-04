class Solution {
public:
    int check(int mid,vector<int>&b,int m,int k){
        int c=0;
        int ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid){
                c++;
            }else{
                if(c){
                    ans+=(c/k);
                }
                c=0;
            }
        }
        ans+=(c/k);
        return ans>=m;
    }
    int BS(vector<int>&b,int l,int h,int m,int k,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,b,m,k)){
            ans=mid;
            return BS(b,l,mid-1,m,k,ans);
        }
        return BS(b,mid+1,h,m,k,ans);
    }
    int minDays(vector<int>& b, int m, int k) {
        int l=*min_element(b.begin(),b.end());
        int h=*max_element(b.begin(),b.end());
        int ans=-1;
        return BS(b,l,h,m,k,ans);
    }
};