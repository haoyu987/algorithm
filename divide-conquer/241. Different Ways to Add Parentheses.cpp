class solution{
public:
vector<int> diffWaysToCompute(string input) {
    vector<int> output;
    for (int i=0; i<input.size(); i++) {
        char c = input[i];
        if (ispunct(c))
            for (int a : diffWaysToCompute(input.substr(0, i)))
                for (int b : diffWaysToCompute(input.substr(i+1)))
                    output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
    }
    return output.size() ? output : vector<int>{stoi(input)};
}
}

/*
python

def diffWaysToCompute(self, input):
   tokens = re.split('(\D)', input)
   nums = map(int, tokens[::2])
   ops = map({'+': operator.add, '-': operator.sub, '*': operator.mul}.get, tokens[1::2])
   def build(lo, hi):
       if lo == hi:
           return [nums[lo]]
       return [ops[i](a, b)
               for i in xrange(lo, hi)
               for a in build(lo, i)
               for b in build(i + 1, hi)]
   return build(0, len(nums) - 1)
   
*/
