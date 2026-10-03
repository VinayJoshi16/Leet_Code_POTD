class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> st;
        vector<int> ans(n, 0);

        if(n == 0) return 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (!st.empty()) {
                    int idx = st.top();
                    st.pop();

                    ans[i] = 1;
                    ans[idx] = 1;
                }
            }
        }
        int count = 0;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (ans[i] == 1) {
                count++;
            } else {
                maxi = max(maxi, count);
                count = 0;
            }
        }
        maxi = max(maxi, count);

        return maxi;
    }
};