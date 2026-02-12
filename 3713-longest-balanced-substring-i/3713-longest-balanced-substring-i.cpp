class Solution {
public:
    int longestBalanced(string s) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
            vector<int> f(26);
            for(int j=i;j<n;j++){
                f[s[j]-'a']++;
                int mn=1e9,mx=0;
                for(int k=0;k<26;k++){
                    if(f[k]){
                        mn=min(mn,f[k]);
                        mx=max(mx,f[k]);
                    }
                }
                if(mn==mx) ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
