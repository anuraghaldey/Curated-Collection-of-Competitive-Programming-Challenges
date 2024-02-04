class Solution {
public:
    int check(int mid,vector<int>a,int k){
        int sum=0;
        int ans=1;
        
        int i=0;
        while(i<a.size()){
            sum+=a[i];
            if(a[i]>mid){
                return false;
            }
            if(sum>mid){
                ans++;
                sum=a[i];
            }
            i++;
        }
        return ans<=k;
    }
    int BS(vector<int>a,int l,int h,int k,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,k)){
            ans=mid;
            return BS(a,l,mid-1,k,ans);
        }
        return BS(a,mid+1,h,k,ans);
    }
    int shipWithinDays(vector<int>& w, int d) {
        int l=*max_element(w.begin(),w.end());
        int h=accumulate(w.begin(),w.end(),0);
        int ans=-1;
        
        return BS(w,l,h,d,ans);
    }
};