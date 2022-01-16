#include <cassert>
#include <iostream>
#include <limits>

using namespace std;

using namespace std;

class Solution {
 public:
  int myAtoi(string s) {
    bool negative = false;
    int result = 0;
    size_t i = 0;
    while (i < s.length() and isspace(s[i])) { ++i; }
    if (i < s.length()) {
      if ('+' == s[i]) {
        ++i;
      } else if ('-' == s[i]) {
        negative = true;
        ++i;
      }
      while (i < s.length() and isdigit(s[i])) {
        result = multiply(result, 10);
        int digit = s[i] - 0x30;
        if (negative) { digit = -digit; }
        result = add(result, digit);
        ++i;
      }

      return result;
    }

    return result;
  }

  bool isAddOverflow(int a, int b) {
    return (0 <= a and INT32_MAX - a < b)
        or (a < 0 and b < INT32_MIN - a);
  }

  int add(int a, int b) {
    if (not isAddOverflow(a, b)) { a += b; }
    else {
      if (a < 0) { a = INT32_MIN; }
      else { a = INT32_MAX; }
    }

    return a;
  }

  int multiply(int a, int b) {
    int result = 0;
    for (int i = 0; i < b; ++i) {
      result = add(result, a);
    }

    return result;
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
