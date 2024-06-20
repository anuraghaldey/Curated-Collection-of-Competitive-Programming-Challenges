class Solution {
public:
    bool canConstruct(string a, string b) {
        unordered_map<char,int>mp;
        int m=a.size(),n=b.size();
        for(int i=0;i<m;i++){
            mp[a[i]]++;
        }
        for(int i=0;i<n;i++){
            if(mp[b[i]]>=1){
                mp[b[i]]--;
            }
            if(!mp[b[i]]){
                mp.erase(b[i]);
            }
        }

        return!mp.size();
    }
};