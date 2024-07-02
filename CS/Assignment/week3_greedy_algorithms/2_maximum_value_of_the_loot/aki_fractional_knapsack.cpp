#include <iostream>
#include <vector>
#include <algorithm>

// using std::vector;
using namespace std;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int n = weights.size();
  vector<double> unit_value(n);

  for (int i  = 0; i<n; i++){
    unit_value[i] = (double)values[i] / (double)weights[i];
  }

  for (int i = 0; i<n; i++){
    int big = i; // 最大值index
    for(int j = i+1; j<n; j++){
      if (unit_value[big] < unit_value[j]){
        big = j;
      }
    }

    double tmp = unit_value[i];
    unit_value[i] = unit_value[big];
    unit_value[big] = tmp;

    tmp = weights[i];
    weights[i] = weights[big];
    weights[big] = tmp;
  }


  // // find max position
  int i = 0;
  while (i<=n && capacity > 0) 
  {

    double w = min(capacity, weights[i]);
    value += unit_value[i]*w;
    capacity -= w;
    i++;
  }



  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}


//   3 50
//  60 20 > 3 > 20
// 100 50 > 2 >  0
// 120 30 > 4 > 30