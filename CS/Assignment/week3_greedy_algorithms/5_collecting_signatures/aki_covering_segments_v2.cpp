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
    bool covered[segments.size()] = {0};
    Segment tmp;
    int min;
    for(int i = 0 ; i<segments.size(); i++){
      min = i;
      for(int j = i+1 ; j<segments.size(); j++){
          if(segments[min].end > segments[j].end)
              min = j;
      }
      tmp           = segments[min];
      segments[min] = segments[i];
      segments[i]   = tmp;
    }
    
    for(int i = 0 ; i<segments.size(); i++){
        if(covered[i]) continue;
        
        points.push_back(segments[i].end);
        for(int j = i+1 ; j<segments.size(); j++){
            if(segments[j].start <= segments[i].end && segments[j].end >= segments[i].end )
                covered[j] = 1;
        }
    }

    // for(int i = 0 ; i<segments.size(); i++){
    //   std::cout<<segments[i].start<<", "<<segments[i].end<<std::endl;
    // }
  
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