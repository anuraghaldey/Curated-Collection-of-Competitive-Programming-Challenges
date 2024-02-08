class Solution {
public:
    int bs(vector<vector<int>>a,int l,int h,int k,int col){
        if(l>h){
            return 0;
        }
        int mid=l+(h-l)/2;
        int r=mid/col,c=mid%col;
        if(a[r][c]==k){
            return 1;
        }else if(a[r][c]<k){
            return bs(a,mid+1,h,k,col);
        }
        return bs(a,l,mid-1,k,col);
    }
    bool searchMatrix(vector<vector<int>>& a, int k) {
        return bs(a,0,(a.size()*a[0].size())-1,k,a[0].size());
    }
};