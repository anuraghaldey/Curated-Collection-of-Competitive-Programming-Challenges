class Solution {
public:
    int characterReplacement(string a, int k) {
        int i=0,j=0,ans=0;
        int n=a.size();
        unordered_map<char,int>mp;
        int mx=0;
        while(j<n){
            mp[a[j]]++;
            mx=max(mx,mp[a[j]]);
            
            if(j-i+1-mx<=k){
                ans=max(ans,j-i+1);
            }
            else{
                mp[a[i++]]--;
            }
            j++;
        }
        return ans;
    }
};