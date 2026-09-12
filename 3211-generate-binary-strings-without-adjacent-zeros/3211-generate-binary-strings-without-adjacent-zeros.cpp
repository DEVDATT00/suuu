class Solution {
    void tryall(vector<string>& ans, int n, int index,string& temp, bool prevOne) {
        if (index == n) {
            ans.push_back(temp);
            return;
        }
        if (prevOne) {
            temp.push_back('0');
            tryall(ans, n, index + 1, temp, false);
            temp.pop_back();
        }
        temp.push_back('1');
        tryall(ans, n, index + 1, temp, true);
        temp.pop_back();
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;
        tryall(ans, n, 0, temp, true);
        return ans;
    }
};