class Solution {
public:
    int longestOnes(vector<int>& a, int k) {
    int zc=0;
    int i=0,j=0;
    int ans=0;
    int n=a.size();
    while(j<n){
        if(!(a[j])){
            zc++;
        }
        if(zc<=k){ 
            ans=max(ans,j-i+1);
            j++;
        }else{
            while(zc>k){
                if(!(a[i])){
                    zc--;
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

};