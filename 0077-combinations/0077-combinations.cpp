class Solution {
    void justdo(vector<vector<int>>&ans,int n, int k, vector<int>& output, int index) {
        if(output.size() == k) {
            ans.push_back(output);
            return;
        }
        for(int i = index; i <= n; i++) {
            output.push_back(i);
            justdo(ans,n, k, output, i + 1);
            output.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> output;
        justdo(ans,n, k, output, 1);
        return ans;
    }
};