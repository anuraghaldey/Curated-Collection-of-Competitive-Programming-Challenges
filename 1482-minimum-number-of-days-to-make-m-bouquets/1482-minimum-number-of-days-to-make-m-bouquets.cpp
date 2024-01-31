class Solution {
public:
    bool check(int mid,vector<int>&b,int m,int k){
        int n=0,ans=0;
        for(int i=0;i<b.size();i++){
            if(b[i]<=mid){
                n++;
                if(n==k){
                ans++;
                n=0;
            }
            }
            else{
                n=0;
            }
            
        }
        
        return ans>=m;
    }
    int BS(vector<int>&b,int m,int k,int &ans,int l,int h){
       
        while(l<=h){
            int mid=l+(h-l)/2;
            
            if(check(mid,b,m,k)){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
    int minDays(vector<int>& b, int m, int k) {
        int l=1,ans=-1,h=1;
        h=*max_element(b.begin(),b.end());
        
        if((m)>b.size()/k){
            return -1;
        }
        
        return BS(b,m,k,ans,l,h);
    }
};