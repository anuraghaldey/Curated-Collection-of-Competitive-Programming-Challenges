class Solution {
public:
    int minimumLevels(vector<int>& p) {
        int n=p.size();
        int sum=0;
        int a[n];
        for(int i=0;i<n;i++){
            a[i]=p[i]?++sum:--sum;
        }
        for(int i=0;i<n-1;i++){
            int b;
            (a[i]>a[n-1]-a[i])?(b=i+1):(b=0);
            if(b){
                return b;
            }
        }
        return -1;
    }
};