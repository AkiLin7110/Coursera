#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;

  //write your code here
  int first;
  int last;
  
  //Sorting
  int big;
  for (int i = 0; i < segments.size(); ++i){
    big = i;
    for (int j = i; j < segments.size(); ++j){
      if (segments[j].start >  segments[big].start){
        big = j;
      }
    }

    int tmp = segments[i].start;
    segments[i].start = segments[big].start;
    segments[big].start = tmp;

    tmp = segments[i].end;
    segments[i].end = segments[big].end;
    segments[big].end = tmp;

  }
  

  //透過有無重疊分組
  for (int i = 1; i < segments.size(); ++i) {
    first = segments[i-1].start;
    last = segments[i-1].end;

    if (first <= segments[i].start && segments[i].end <= last){ // 包在裡面
      segments[i-1].start = segments[i].start;
      segments[i-1].end = segments[i].end;
    }
    else if (first <= segments[i].start && segments[i].end > last){
      segments[i-1].start = segments[i].start;
      segments[i].end = segments[i-1].end;
    }
    else if (first > segments[i].start && segments[i].end <= last){
      segments[i].start = segments[i-1].start;
      segments[i-1].end = segments[i].end;
    }
    else{
      continue;
    }

  }



  for (int i = 0; i < segments.size(); ++i) {
    int signal = 0;
    for (int j = 0; j < points.size(); ++j) {
      if (segments[i].start == points[j]){
        signal = 1;
        break;
      }
    if (signal == 0){
      points.push_back(segments[i].start);
    } 
  }
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
