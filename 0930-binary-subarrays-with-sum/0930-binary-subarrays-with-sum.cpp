class Solution {
public:
   int AM(vector<int>&s,int k){
       int i=0,j=0,ans=0,sum=0;
       int n=s.size();
       if(k<0){
           return 0;
       }
       while(j<n){
           sum+=s[j];
           
           while(sum>k){
               sum-=s[i++];
           }
           ans+=j-i+1;
           j++;
       }
       return ans;
   }
   int numSubarraysWithSum(vector<int>& s, int k) {
        return AM(s,k)-AM(s,k-1);
   }

};