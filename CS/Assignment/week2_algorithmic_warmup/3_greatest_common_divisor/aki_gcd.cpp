#include <iostream>

long long gcd_naive(long long a, long long b) {
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
  std::cout << gcd_naive(a, b) << std::endl;
  return 0;
}


//     182 117  1
// 1    65  52  1 
// 4    13   0
