class Solution {
public:
    
    int check(vector<int>&a,int mid,int k){
        int cnt=0;
        for(int i=0;i<a.size();i++){
            if(a[i]%mid){
                cnt+=(a[i]/mid);
            }else{
                cnt+=((a[i]/mid)-1);
            }
        }
        return cnt<=k;
    }
    int bs(vector<int>&a,int l,int h,int &ans,int k){
        if(l>h)return ans;
        int mid=l+(h-l)/2;
        if(check(a,mid,k)){
            ans=mid;
            return bs(a,l,mid-1,ans,k);
        }
        return bs(a,mid+1,h,ans,k);
    }
    int minimumSize(vector<int>& a, int k) {
        int l=1,h=*max_element(a.begin(),a.end());
        int ans=0;
        return bs(a,l,h,ans,k);
    }
};