class Solution {
public:
    struct MonotoneDQ{
        deque<int>dq;
        void insert(int x){
            while(!dq.empty()&&dq.front()<x){
                dq.pop_front();
            }
            dq.push_front(x);
        }
        void erase(int x){
            if(dq.back()==x){
                dq.pop_back();
            }
        }
        int getmax(){
            return dq.back();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        int n=a.size();
        vector<int>ans;
        MonotoneDQ mdq;
        for(int i=0;i<n;i++){
            mdq.insert(a[i]);
            if((i-k)>=0){
                mdq.erase(a[i-k]);
            }
            if(i>=(k-1)){
                ans.push_back(mdq.getmax());
            }
        }
        return ans;
    }
};