class Solution {
public:
    int bs2(vector<pair<int,int>>&v,int l,int h,int num,int &ans){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(v[mid].first>=num){
            ans=v[mid].second;
            return bs2(v,l,mid-1,num,ans);
        }
        return bs2(v,mid+1,h,num,ans);
    }
    int bs1(vector<pair<int,int>>&v,int num,int &ans){
        return bs2(v,0,v.size()-1,num,ans);
    }
    vector<int> findRightInterval(vector<vector<int>>& a) {
        vector<pair<int,int>>v;
        for(int i=0;i<a.size();i++){
            pair<int,int>p;
            p.first=a[i][0];
            p.second=i;
            v.push_back(p);
        }
        sort(v.begin(),v.end());
        vector<int>ans;
        for(int i=0;i<a.size();i++){
            int s=-1;
            ans.push_back(bs1(v,a[i][1],s));
        }
        return ans;
        
    }
};