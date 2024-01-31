class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n=t.size();
        vector<int>ans(t.size(),0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minhp;
        
        
        for(int i=1;i<n;i++){
            if(t[i-1]>=t[i]){
                minhp.push({t[i-1],i-1});
            }else{
                ans[i-1]=1;
                int flag=true;
                while(!minhp.empty()&&flag){
                    pair temp=minhp.top();
                    if(temp.first<t[i]){
                        minhp.pop();
                        ans[temp.second]=i-temp.second;
                    }else{
                        flag=false;
                    }
                }
            }
        }
        
        return ans;
        
    }
};