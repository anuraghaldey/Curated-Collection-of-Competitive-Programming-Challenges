class Solution {
public:
    bool checkInclusion(string a, string b) {
        map<char,int>mp1,mp2;
        
        int k=a.size(),m=b.size();
        if(k>m){
            return 0;
        }
        for(int i=0;i<k;i++){
            mp1[a[i]]++;
        }
        for(int i=0;i<k;i++){
            mp2[b[i]]++;
        }
        if(mp1==mp2){
            return 1;
        }
        for(int i=k;i<m;i++){
            mp2[b[i-k]]--;
            mp2[b[i]]++;
            if(!(mp2[b[i-k]])){
                mp2.erase(b[i-k]);
            }
            if(mp1==mp2){
                return 1;
            }
        }
        return 0;
    }
};