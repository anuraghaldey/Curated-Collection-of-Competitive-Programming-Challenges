class Solution {
public:
int lb(vector<int>&a,int n,int x){
    int l=0,h=n-1,ans=n;

    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]>=x){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
int ub(vector<int>&a,int n,int x){
    int l=0,h=n-1,ans=n;

    while(l<=h){
        int mid=l+(h-l)/2;
        if(a[mid]>x){
            ans=mid;
            h=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& arr, int k) {
         int n=arr.size();
    int fi=lb(arr,n,k);
    int li=ub(arr,n,k);
    vector<int>p;
    if(fi!=n&&arr[fi]==k){
       p.push_back(fi);
        p.push_back(li-1);
    }else{
      p.push_back(-1);
        p.push_back(-1);
    }
    return p;
    }
};