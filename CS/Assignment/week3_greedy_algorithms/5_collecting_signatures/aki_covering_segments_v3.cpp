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

  //Sorting
  int small;
  for (int i = 0; i < segments.size(); ++i){
    small = i;
    for (int j = i; j < segments.size(); ++j){
      if (segments[j].end < segments[small].end){
        small = j;
      }
    }

    int tmp = segments[i].start;
    segments[i].start = segments[small].start;
    segments[small].start = tmp;

    tmp = segments[i].end;
    segments[i].end = segments[small].end;
    segments[small].end = tmp;

  }
  
  size_t i = 0;
  points.push_back(segments[i].end);
  for (i = 0; i < segments.size(); ++i) {
    int n = points.size();
    if (segments[i].start > points[n-1]) points.push_back(segments[i].end);
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
