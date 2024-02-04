class Solution {
public:
    int check(int mid,vector<int>a,int k){
        int sum=0;
        
        for(int i=0;i<a.size();i++){
            if((a[i]%mid)){
                sum+=(a[i]/mid+1);
            }else{
                sum+=(a[i]/mid);
            }
        }
        return sum<=k;
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
    int smallestDivisor(vector<int>& a, int k) {
        int l=1;
        int h=*max_element(a.begin(),a.end());
        int ans=-1;
        return BS(a,l,h,k,ans);
    }
};