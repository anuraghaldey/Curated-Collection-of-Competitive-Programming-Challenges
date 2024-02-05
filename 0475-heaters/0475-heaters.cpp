class Solution {
public:
    
    bool check(int mid, vector<int>& a,vector<int>& v) {
        int i=0,j=0,n=v.size(),m=a.size();
        while(i<n&&j<m){
            if(abs(v[i]-a[j])<=mid){
                j++;
            }
            else{
                i++;
            }
        }
        return i<n;
        
        
    }
    int BS(vector<int>a,vector<int>v,int l,int h,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,v)){
            ans=mid;
            return BS(a,v,l,mid-1,ans);
        }
        return BS(a,v,mid+1,h,ans);
    }
    int findRadius(vector<int>& a, vector<int>& v) {
        sort(v.begin(),v.end());
        sort(a.begin(),a.end());
        int l=0;
        int h=max(a.back(), v.back());
        int ans=-1;
        return BS(a,v,l,h,ans);
    }
};