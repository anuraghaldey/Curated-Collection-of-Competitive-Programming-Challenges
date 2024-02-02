class Solution {
public:
int lb(vector<int>&a,int n,int x){
    int l=0,h=n-1,ans=-1;

    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]==x){
            ans=mid;
            h=mid-1;
        }else if(a[mid]<x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
int ub(vector<int>&a,int n,int x){
    int l=0,h=n-1,ans=-1;

    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]==x){
            ans=mid;
            l=mid+1;
        }else if(a[mid]<x){
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& arr, int k) {
         int n=arr.size();
    int fi=lb(arr,n,k);
    int li=ub(arr,n,k);
    vector<int>v;
    v.push_back(fi);
    v.push_back(li);
    return v;
    }
};