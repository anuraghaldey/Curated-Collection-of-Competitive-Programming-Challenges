class Solution {
public:
    int lengthOfLongestSubstring(string a) {
        unordered_map<char,int>mp;
        int ans=0;
        int i=0,j=0;
        int n=a.size();
        while(j<n){
            mp[a[j]]++;
            if(mp.size()>j-i+1){
                j++;
            }
            if(mp.size()==j-i+1){
                ans=max(ans,j-i+1);
                j++;
            }
            else if(mp.size()<j-i+1){
                while(mp.size()<j-i+1){
                    mp[a[i]]--; 
                    if(mp[a[i]]==0){
                        mp.erase(a[i]);
                    }
                    i++;
                }
                j++;
                
            }
            
            
        }
        return ans;
    }
};