#include <iostream>

long long lcm_naive(long long a, long long b) {
  long long q, r=1;
  while(r){
    q = a/b;
    r = a%b;
    a = b;
    b = r;
  }
  return a;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << a*b/lcm_naive(a, b) << std::endl;
  return 0;
}
