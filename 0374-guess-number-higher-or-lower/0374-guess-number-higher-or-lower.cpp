/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int bs(int l,int h){
        if(l>h){
            return -1;
        }
        int mid=l+(h-l)/2;
        if(!guess(mid)){
            return mid;
        }else if(guess(mid)==-1){
            return bs(l,mid-1);
        }
        return bs(mid+1,h);
    }
    int guessNumber(int n) {
        int l=1,h=n;
        return bs(l,h);
    }
};