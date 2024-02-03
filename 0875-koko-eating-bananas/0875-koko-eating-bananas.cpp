
class Solution {
public:
    int check(int mid, vector<int>& a, int hr) {
        long long ans=0;
        for(int i=0;i<a.size();i++)
        {
            if(!(a[i]%mid)){
                ans+=(a[i]/mid);
            }else{
                ans+=((a[i]/mid)+1);
            }
        }
        return ans<=hr;
    }

    int BS(int l,int h,vector<int>&a,int hr,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,hr)){
            ans=mid;
            return BS(l,mid-1,a,hr,ans);
        }
        return BS(mid+1,h,a,hr,ans);
    }
    int minEatingSpeed(vector<int>& p, int hr) {
        int l=1,h=*max_element(p.begin(),p.end());
        int ans=-1;
        return BS(l,h,p,hr,ans);
    }
}; 