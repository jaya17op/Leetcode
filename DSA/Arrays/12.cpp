class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // int n = nums.size() ;
        // int count = 0 ;
        // for(int i=0;i<n;i++){
        //     nums[i] = n ;
        //     count = 0;
        //     for(int j = 0; j<n ; j++){
        //         if(nums[j]==n)
        //          return count++;
        //     }
        //     if(nums[i]==1)
        //      return n ;
        // }
        int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            res=res^nums[i];
        }
        return res;
    }
};