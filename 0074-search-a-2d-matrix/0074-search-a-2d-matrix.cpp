class Solution {
public:
    int bs(vector<int>a,int l,int h,int v){
        if(l>h){
            return 0;
        }
        int mid=l+(h-l)/2;
        if(a[mid]==v){
            return 1;
        }else if(a[mid]<v){
            return bs(a,mid+1,h,v);
        }
        return bs(a,l,mid-1,v);
    }
    bool searchMatrix(vector<vector<int>>& a, int k) {
        for(int i=0;i<a.size();i++){
            if(a[i][0]<=k&&k<=a[i][a[i].size()-1]){
                return bs(a[i],0,a[i].size()-1,k);
            }
        }
        return false;
    }
};