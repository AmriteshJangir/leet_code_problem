// class Solution{
//     public:
//     bool find132pattern(vector<int>& nums) {
//         int n=nums.size();
//         if(n<3) return false;
//         stack<int> st;
//         int s1=INT_MAX;
//         for(int i=0;i<n;i++){
//             if(nums[i]>s1)return false;
//             while(!st.empty()&&nums[i]>st.top()){
//                 s1=st.top();
//                 st.pop();
//             }
//             st.push(nums[i]);
//         }
//         return true;
//     }
// };


// class Solution{
//     public:
//     bool find132pattern(vector<int>& nums) {
//         stack<int> s;
//         int s1=INT_MIN;
//         if(n<=3) return false;
//         for(int i=0;i<n;i++){
//         }
//     }
// };


class Solution{
    public:
    bool find132pattern(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        stack<int> st;
        int s3=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(nums[i]<s3)return true;
            while(!st.empty()&&nums[i]>st.top()){
                s3=st.top();
                st.pop();
            }
            st.push(nums[i]);
        }
        return false;
    }
};