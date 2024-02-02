class Solution {
public:
    int BS(vector<int>& a, int l, int h) {
        if(l>=h){
            return a[l];
        }
      
        int mid=l+(h-l)/2;
        if(a[mid]!=a[mid-1]&&a[mid]!=a[mid+1]){
            return a[mid];
        }
        if((mid%2&&a[mid-1]==a[mid])||!(mid%2)&&a[mid]==a[mid+1]){
            return BS(a,mid+1,h);
        }
        return BS(a,l,mid-1);
        
    }

    int singleNonDuplicate(vector<int>& a) {
        if(a.size()==1){
            return a[0];
        }
        if(a[1]!=a[0]){
            return a[0];
        }
        if(a[a.size()-2]!=a[a.size()-1]){
            return a[a.size()-1];
        }
        return BS(a, 1, a.size() - 2);
    }
};
