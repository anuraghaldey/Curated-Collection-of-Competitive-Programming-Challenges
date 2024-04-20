#include<iostream>
using namespace std;


class Solution {
public:
    
    long long maximumSubarraySum(vector<int>& a, int k) {
        vector<int> count(100100, 0);
        long long ans = 0;
        long long sum = 0;
        int dist = 0;
        int n = a.size();

        for (int i = 0; i < k; i++) {
            count[a[i]]++;
            sum += a[i];
            count[a[i]] == 1 ? dist++ : dist = dist;
        }
        dist == k ? ans = max(ans, sum) : ans = ans;

        for (int i = k; i < n; i++) {
            count[a[i - k]]--;
            count[a[i]]++;
            sum -= a[i - k];
            sum += a[i];
            count[a[i - k]] == 0 ? dist-- : dist = dist;
            if(a[i]!=a[i-k]){
                count[a[i]] == 1 ? dist++ : dist = dist;   
            }
            dist == k ? ans = max(ans, sum) : ans = ans;
        }
        return ans;
    }
};