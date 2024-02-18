class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
        int i=0,j=0,ans=0,zc=0;
        int n=a.size();
        while(j<n){
            if(!(a[j])){
                zc++;
            }
            if(zc<=k){
                ans=max(ans,j-i+1);
                
            }else{
                if(!(a[i])){
                    zc--;
                }
                i++;
            }
            j++;
        }
        return ans;
    }

};