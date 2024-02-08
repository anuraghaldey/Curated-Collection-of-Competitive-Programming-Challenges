class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0) return true;
        for(long long int i=0;i*i<c;i++){
            int x=i*i;
            int search=c-x;
            int low=i;
            int high=sqrt(search);
            
            while(low<=high){
                int mid=(low+high)/2;

                if(x+mid*mid==c) return true;
                if(x+mid*mid>c){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            
        }
        return false;
    }
};
