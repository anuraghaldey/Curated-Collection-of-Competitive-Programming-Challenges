class Solution {
public:
    bool check(int mid,vector<int>& c){
        return (c[mid]>=(c.size()-mid));
        
    }
    int hIndex(vector<int>& c) {
        int l=0,h=c.size()-1;
        int mid=l+(h-l)/2;
        int ans=INT_MIN;
        int n=c.size();
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(check(mid,c)){
                ans=max(ans,(n-mid));
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        
        return ans==INT_MIN? 0:ans;
    }
};