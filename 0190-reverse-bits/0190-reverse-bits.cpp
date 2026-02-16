// class Solution {
// public:
//     int reverseBits(int n) {
//         unsigned int result = 0;
//         for(int i = 0; i < 32; i++) {
//             result <<= 1;
//             result |= (n & 1);
//             n >>= 1;
//         }
//         return result;
//     }
// };

class Solution {
public:
    int convert_back(vector<int>bits){
        int num=bits[31];
        for(int i=0;i<31;i++){
            num=num+bits[i]*pow(2,31-i);
        }
        return num;
    }
    int reverseBits(int n) {
        vector<int>bits(32,0);
        int num=n,i=0;
        while(num!=0){
            int rem=num%2;
            bits[i]=rem;
            num=num/2;
            i++;
        }
        return convert_back(bits);
    }
};