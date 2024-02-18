class Solution {
public:
    int AMOI(vector<int>&a,int k){
        if(k<0){
            return 0;
        }
        int i=0,j=0,ans=0,count=0,n=a.size();
        while(j<n){
           if(a[j]%2){
               count++;
           }
            while(count>k){
                if(a[i++]%2){
                    count--;
                }
            }
            ans+=j++ -i+1;
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& a, int k) {
       return AMOI(a,k)-AMOI(a,k-1);
    }
};