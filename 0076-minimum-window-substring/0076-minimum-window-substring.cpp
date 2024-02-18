class Solution {
public:
    string minWindow(string s ,string t) {
        int n=s.size();
        int m=t.size();
        if(n==0||m==0||n<m){
            return "";
        }
        vector<int>mp(256,0);
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int i=0,j=0,ans=0;
        int mnln=INT_MAX;
        int count=0;
        while(j<n){
            if(mp[s[j]]>0){
                count++;
            }
            mp[s[j]]--;
            while(count==m){
                if(mnln>j-i+1){
                    mnln=j-i+1;
                    ans=i;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0){
                    count--;
                }
                i++;
            }
            j++;
        }
        return mnln==INT_MAX?"":s.substr(ans,mnln);
    }
};