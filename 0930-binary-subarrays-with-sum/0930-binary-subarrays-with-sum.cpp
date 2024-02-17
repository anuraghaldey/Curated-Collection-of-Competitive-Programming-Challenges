class Solution {
public:
   int numSubarraysWithSum(vector<int>& a, int k) {
    int i = 0, j = 0, ans = 0, n = a.size();
    int one = 0;
    
    while (j < n) {
        one+=a[j];
        while(i<j&&one>k){
            one-=a[i++];
        }
        if(one==k){
            int t=i;
            ans++;
            while(t<j&&!(a[t])){
                ans++;
                t++;
            }
        }
            
        
        j++;
    }
    
    return ans;
}

};