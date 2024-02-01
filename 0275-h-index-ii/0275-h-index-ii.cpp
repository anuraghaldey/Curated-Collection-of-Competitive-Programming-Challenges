class Solution {
public:
    bool check(int mid,vector<int>& c){
        return (c[mid]>=(c.size()-mid));
        
    }
    
    int BS(vector<int>&c,int l,int h,int &ans,int n){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        
        if(check(mid,c)){
            ans=max(ans,(n-mid));
            return BS(c,l,mid-1,ans,n);
        }
        return BS(c,mid+1,h,ans,n);
    }
    int hIndex(vector<int>& c) {
        int l=0,h=c.size()-1;
        int mid=l+(h-l)/2;
        int ans=INT_MIN;
        int n=c.size();
        int p=BS(c,l,h,ans,n);
        
        return p==INT_MIN? 0:p;
    }
};