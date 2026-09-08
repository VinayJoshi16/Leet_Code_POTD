class Solution {
public:
    int findSize(int n){
        string str = to_string(n);
        int len = str.size();
        return len;
    }
    int countCommas(int n) {
        int fourDigitNum = 1000;
        int val = findSize(n);
        int ans = 0;
        if(val <= 3){
            return 0;
        }
        else {
            ans = n - 1000;
        }
        return ans + 1;
    }
};