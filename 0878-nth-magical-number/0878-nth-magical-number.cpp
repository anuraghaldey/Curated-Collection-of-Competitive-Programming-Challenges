#define ll long long
const int MOD = (1e9 + 7);
class Solution {
public:
    ll count(ll mid,int a,int b){
        ll tc=mid/a+mid/b-mid/((a*b)/gcd(a,b));
        return tc;
    }
    int nthMagicalNumber(int n, int a, int b) {
        ll l=2,h=1e15;
        ll ans=-1;
        while(l<=h){
            ll mid=l+(h-l)/2;
            if(count(mid,a,b)>n){
                h=mid-1;
            }else if(count(mid,a,b)<n){
                l=mid+1;
            }else{
                if(!(mid%a)||!(mid%b)){
                    return (mid%MOD+MOD)%MOD;
                }
                h=mid-1;
            }
        }
        return (ans%MOD+MOD)%MOD;
    }
};