class Solution {
public:
    int BS(vector<int>&a,int l,int h,int x){
        if(l>h){
            return 0;
        }
        int mid=l+(h-l)/2;
        
        if(a[mid]==x){
            return 1;
        }
        if(a[l]==a[mid]&&a[l]==a[h]){
            return BS(a,l+1,h-1,x);
        }
        if(a[l]<=a[mid]){
            if((a[l]<=x)&&(x<=a[mid])){
                return BS(a,l,mid-1,x);
            }else{
                return BS(a,mid+1,h,x);
            }
        }else{
            if((a[mid]<=x)&&(x<=a[h])){
                return BS(a,mid+1,h,x);
            }else{
                return BS(a,l,mid-1,x);
            }
        }
    }
    bool search(vector<int>& a, int x) {
        return BS(a,0,a.size()-1,x);
    }
};