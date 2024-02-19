class Solution {
public:
    int am(vector<int>&a,int k){
        if(k<0){
            return 0;
        }
        int i=0,j=0,ans=0,n=a.size();
        unordered_map<int,int>mp;
        
        while(j<n){
            mp[a[j]]++;
            while(mp.size()>k){
                mp[a[i]]--;
                if(!(mp[a[i]])){
                    mp.erase(a[i]);
                }
                i++;
            }
            ans+=j++ -i+1;
            
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return am(nums,k)-am(nums,k-1);
    }
};