class Solution{
    public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!s.empty() && asteroid < 0 && s.top() > 0) {
                if (s.top() < -asteroid) {
                    s.pop();
                } else if (s.top() == -asteroid) {
                    s.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }
            if (!destroyed) {
                s.push(asteroid);
            }
        }
        vector<int> result(s.size());
        for (int i = s.size() - 1; i >= 0; --i) {
            result[i] = s.top();
            s.pop();
        }
        return result;
    }
};