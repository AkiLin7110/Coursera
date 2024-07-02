#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a) {
  //write your code here

  //按照位數排
  int big = 0;
  int i; 
  string tmp;

  for (i = 0; i < a.size(); i++){
    big = i;
    vector<string> pool;
    vector<string> a_tmp = a;
    
    for (int j = i; j < a.size(); j++){

      


    }

    tmp = a[i];
    a[i] = a[big];
    a[big] = tmp;
  }



  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
