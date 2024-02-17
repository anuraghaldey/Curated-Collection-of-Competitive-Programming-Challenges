class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0,j=0;
        int n=s.size();
        int ans=0;
        int mx=0;
        unordered_map<char,int>mp;
        while(j<n){
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            if((j-i+1)-mx<=k){
                ans=max(ans,j-i+1);
            }else{
                mp[s[i++]]--;
            }
            j++;
            
        }
        return ans;
    }
};