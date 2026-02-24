class Solution{
    public:
    int numRabbits(vector<int>& ans) {
        unordered_map<int, int> count;
        for (int a : ans) {
            count[a]++;
        }
        int rabbits = 0;
        for (auto& [a, c] : count) {
            rabbits += ((c + a) / (a + 1)) * (a + 1);
    }
        return rabbits;
    }
};


//         set<int> seen;
//         int rabbits = 0;
//         for (int a : ans) {
//             if (!seen.count(a)) {
//                 rabbits += a + 1;
//                 seen.insert(a);
//             }
//         }
//         return rabbits;
//     }
// };