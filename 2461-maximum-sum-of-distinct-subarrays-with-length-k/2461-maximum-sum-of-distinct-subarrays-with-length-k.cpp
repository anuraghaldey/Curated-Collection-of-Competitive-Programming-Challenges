class Solution {
public:
    long long maximumSubarraySum(vector<int>& a, int k) {
        long long ans=0;
        long long sum=0;
        map<int,int>mp;
        int n=a.size();
        for(int i=0;i<k;i++){
            mp[a[i]]++;
            sum+=a[i];
        }
        mp.size()==k?ans=max(ans,sum):ans=ans;
        
        for(int i=k;i<n;i++){
            mp[a[i-k]]--;
            mp[a[i]]++;
            sum-=a[i-k];
            sum+=a[i];
            if(!(mp[a[i-k]])){
                mp.erase(a[i-k]);
            }
            mp.size()==k?ans=max(ans,sum):ans=ans;
        }
        return ans;
        
    }
};