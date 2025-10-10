class Solution {
public:
    void backtrack(int n, string curr, int open, int close, vector<string>& result) {
        // Base case: if the string has 2*n characters
        if (curr.size() == 2 * n) {
            result.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n) {
            backtrack(n, curr + '(', open + 1, close, result);
        }

        // Add ')' if it doesn't exceed '(' count
        if (close < open) {
            backtrack(n, curr + ')', open, close + 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, "", 0, 0, result);
        return result;
    }
};
