class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> num1;
        vector<int> num2;
        num1.push_back(nums[0]);
        num2.push_back(nums[1]);
        int i=2;
        while(i<n){
            if(num1.back() > num2.back()){
                num1.push_back(nums[i]);
            }else{
                num2.push_back(nums[i]);
            }
            i++;
        }
        vector<int> result;
        for(int i=0;i<num1.size();i++){
            result.push_back(num1[i]);
        }
        for(int i=0;i<num2.size();i++){
            result.push_back(num2[i]);
        }
        return result;
    }
};