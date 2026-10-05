class Solution {
    void generate(vector<string>& ans, string& temp, int n, int k, int index,int sum, bool prevOne) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back('0');
        generate(ans, temp, n, k, index + 1, sum, false);
        temp.pop_back();
        if (!prevOne && sum + index <= k) {
            temp.push_back('1');
            generate(ans, temp, n, k, index + 1, sum + index, true);
            temp.pop_back();
        }
    }
public:
    vector<string> generateValidStrings(int n, int k) {
        vector<string> ans;
        string temp;
        temp.reserve(n);
        generate(ans, temp, n, k, 0, 0, false);
        return ans;
    }
};