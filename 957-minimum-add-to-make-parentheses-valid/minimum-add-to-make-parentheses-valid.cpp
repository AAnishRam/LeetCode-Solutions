class Solution {
public:
    
int minAddToMakeValid(string s) {
    stack<char> stack;
    for (char x : s) {
        if (!stack.empty() && stack.top() == '(' && x == ')') {
            stack.pop();
        } else {
            stack.push(x);
        }
    }
    return stack.size();
}

};