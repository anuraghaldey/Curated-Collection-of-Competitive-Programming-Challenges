class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        
        int flag=0;
        for(int i=0;i<nums.size();i+=3){
            vector<int>temp;
            
            temp.push_back(nums[i]);
            temp.push_back(nums[i+1]);
            temp.push_back(nums[i+2]);
            if((temp[2]-temp[0])>k||temp[1]-temp[0]>k||temp[2]-temp[1]>k){
                flag=1;
                break;
            }else{
                ans.push_back(temp);
            }
        }
        
        if(!flag){
            return ans;
        }else{
            vector<vector<int>>an;
            return an;
        }
    }
};