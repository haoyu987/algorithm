class Solution1 {
public:
    int rangeBitwiseAnd(int m, int n) {
        unsigned int x = m ^ n;
        x |= x >> 1, x |= x >> 2, x |= x >> 4, x |= x >> 8, x |= x >> 16;
        return m & ~x;  
    }
};  // mask, set all the bits that changes to zero.

class Solution2 {
public:
    int rangeBitwiseAnd(int m, int n) {
        int move=0;
        while(m!=n){
            m>>=1;
            n>>=1;
            move++;
        }
        return m<<move;
    }
}; // if m!=n, the last bit must be zero.
