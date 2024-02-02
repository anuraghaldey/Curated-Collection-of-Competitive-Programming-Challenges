class Solution {
public:
    
    bool search(vector<int>& a, int x) {
        int l=0,h=a.size()-1;
        
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(a[mid]==x){
                return true;
            }
            if(a[mid]==a[l]&&a[l]==a[h]){
                l++;h--;
                continue;
            }
            if(a[l]<=a[mid]){
                if(x>=a[l]&&x<=a[mid]){
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(x>=a[mid]&&x<=a[h]){
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
        }
        return false;
    }
};