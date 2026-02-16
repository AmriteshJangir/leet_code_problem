// class Solution{
//     public:
//     string reverseParentheses(string s) {
//         stack<string> st;
//         string temp = "";
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(') {
//                 st.push(temp);
//                 temp = "";
//             } else if (s[i] == ')') {
//                 reverse(temp.begin(), temp.end());
//                 temp = st.top() + temp;
//                 st.pop();
//             } else {
//                 temp += s[i];
//             }
//         }
//         return temp;
//     }
// };
class Solution {
public:
    string reverseParentheses(string s) {
        string result;
        stack<int>st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(result.size());
            }
            else if(s[i]==')')
            {
                int start=st.top();
                st.pop();
                reverse(result.begin()+start,result.end());
            }
            else
            {
                result.push_back(s[i]);
            }
        }
        return result;
    }
};