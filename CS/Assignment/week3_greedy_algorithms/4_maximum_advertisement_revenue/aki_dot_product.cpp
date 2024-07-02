#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  long long result = 0;
  int big = 0;
  int big_ = 0;
  int tmp;
  for (int i = 0; i < a.size(); i++){
    big = i;
    big_ = i;
    for (int j = i; j < a.size(); j++){
      if  (a[j] > a[big]){
        big = j;
      }

      if (b[j] > b[big_]){
        big_ = j;
      }
  }
  tmp = a[i];
  a[i] = a[big];
  a[big] = tmp;

  tmp = b[i];
  b[i] = b[big_];
  b[big_] = tmp;

  // std::cout << a[i] << " " << b[i] << " \n";
  result += ((long long) a[i]) * b[i];
  }
  // for (size_t i = 0; i < a.size(); i++) {
  //   result += ((long long) a[i]) * b[i];
  // }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
