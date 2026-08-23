class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> a;
        int n = temperatures.size();
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            while(!a.empty() && temperatures[a.top()] <= temperatures[i]) {
                a.pop();
            }
            if(!a.empty()) {
                ans[i] = a.top() - i;
            }
            a.push(i);
        }
        return ans;
    }
};