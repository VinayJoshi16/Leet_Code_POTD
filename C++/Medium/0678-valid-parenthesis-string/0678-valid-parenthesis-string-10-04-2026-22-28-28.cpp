class Solution {
public:
    int n;
    string s;
    vector<vector<int>> dp; 

    bool solve(int idx, int count) {
        if (count < 0) return false;        
        if (idx == n) return (count == 0);  

        if (dp[idx][count] != -1)          
            return dp[idx][count];

        bool ans = false;
        if (s[idx] == '(') {
            ans = solve(idx + 1, count + 1);
        } 
        else if (s[idx] == ')') {
            ans = solve(idx + 1, count - 1);
        } 
        else { 
            ans = solve(idx + 1, count + 1) || 
                  solve(idx + 1, count - 1) || 
                  solve(idx + 1, count);
        }

        return dp[idx][count] = ans;
    }

    bool checkValidString(string str) {
        s = str;
        n = s.size();
        dp.assign(n + 1, vector<int>(n + 1, -1)); 
        return solve(0, 0);
    }
};
