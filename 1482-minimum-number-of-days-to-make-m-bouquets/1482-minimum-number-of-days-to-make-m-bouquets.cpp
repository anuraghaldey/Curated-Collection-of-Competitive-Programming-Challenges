class Solution {
public:
    int check(int mid, vector<int>&a, int m, int k) {
	int n = a.size();
	int bouquets = 0;
	int count = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] <= mid) {
			count++;
			if (count == k) {
				bouquets++;
				count = 0;
			}
		} else {
			count = 0;
		}

	}
	return bouquets >= m;
}
    int bs(vector<int>&a,int l,int h,int &ans,int m,int k){
        if(l>h){
            return ans;
        }
        int mid=l+(h-l)/2;
        if(check(mid,a,m,k)){
            ans=mid;
            return bs(a,l,mid-1,ans,m,k);
        }
        return bs(a,mid+1,h,ans,m,k);
    }
    int minDays(vector<int>& a, int m, int k) {
        int n=a.size();
        if(m>n/k){
            return -1;
        }
        int l=*min_element(a.begin(),a.end()),h=*max_element(a.begin(),a.end());
        int ans=-1;
        return bs(a,l,h,ans,m,k);
    }
};