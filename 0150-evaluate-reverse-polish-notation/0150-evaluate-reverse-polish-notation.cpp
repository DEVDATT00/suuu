class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for(int i = 0; i < tokens.size(); i++) {
            if(tokens[i] == "+") {
                int tem = s.top();
                s.pop();
                s.top() += tem;
            } else if(tokens[i] == "-") {
                int tem = s.top();
                s.pop();
                s.top() -= tem;
            } else if(tokens[i] == "*") {
                int tem = s.top();
                s.pop();
                s.top() *= tem;
            } else if(tokens[i] == "/") {
                int tem = s.top();
                s.pop();
                s.top() /= tem;
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};