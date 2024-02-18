class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum = 0;
		int n=a.size();
        for(int i=0;i<k;i++){ sum+=a[i];}
        
        int curr=sum;
        for(int i=k-1;i>=0;i--) {
            curr-=a[i];
            curr+=a[n-k+i];
			sum= max(sum, curr);
        }
        
        return sum; 
    }
};