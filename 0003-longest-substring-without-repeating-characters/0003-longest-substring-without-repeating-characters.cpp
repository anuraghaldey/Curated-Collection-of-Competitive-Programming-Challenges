class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        int i=0,j=0,ans=0;
        unordered_map<char,int>mp;
        int n=a.size();
        while(j<n){
            mp[a[j]]++;

            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
            }else{
                mp[a[i]]--;
                if(mp[a[i]]==0){
                    mp.erase(a[i]);
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};