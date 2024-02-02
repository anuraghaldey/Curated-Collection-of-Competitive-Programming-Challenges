#define f(i,a,b) for(int i=a;i<b;i++)
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int>ans;
        f(i,1,10){
            int n=i;
            f(j,i+1,10){
                n=n*10+j;
                if(n>=low&&n<=high){
                    ans.push_back(n);
                }
            }
        }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};