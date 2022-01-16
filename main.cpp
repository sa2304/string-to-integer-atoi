#include <cassert>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    // FIXME

    return 0;
  }
};

void TestMyAtoi() {
  Solution s;
  assert(42 == s.myAtoi("42"s));
  assert(-42 == s.myAtoi("    -42"s));
  assert(4193 == s.myAtoi("4193 with words"s));
  assert(0 == s.myAtoi(""s));
  assert(0 == s.myAtoi("text"s));
  assert(numeric_limits<int32_t>::max() == s.myAtoi(string(200, '9')));
  assert(numeric_limits<int32_t>::min() == s.myAtoi(to_string(numeric_limits<int64_t>::min())));
  assert(numeric_limits<int32_t>::max() == s.myAtoi(to_string(numeric_limits<int64_t>::max())));
}

int main() {
  TestMyAtoi();
  cout << "Ok!" << endl;
  return 0;
}
