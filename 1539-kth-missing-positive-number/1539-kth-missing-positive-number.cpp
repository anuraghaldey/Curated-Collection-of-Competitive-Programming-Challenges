class Solution {
public:
    int BS(vector<int>a,int l,int h,int k){
        if(l>h){
            return l+k;
        }
        int mid=l+(h-l)/2;
        int missing=a[mid]-(mid+1);
        if(missing<k){
            return BS(a,mid+1,h,k);
        }
        return BS(a,l,mid-1,k);
    }
    
    int findKthPositive(vector<int>& a, int k) {
       return BS(a,0,a.size()-1,k);
    }
};