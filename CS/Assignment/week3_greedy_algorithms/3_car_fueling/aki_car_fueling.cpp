#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int n = stops.size();
    int count = 0;
    int full_tank = tank;
    stops.push_back(dist);

    if (dist <= full_tank) return 0; //如果油箱可以直接行驶到目，不用加油。
    int i = 0;
    int pre = stops[0];

    for (i = 0 ; i <= n ; i++){
        int next_ = (stops[i+1] - stops[i]);
        // cout << next_ << "\n";
        if (next_ > full_tank){
            return -1;
            }
        else{
            // cout << "tank:" << tank <<"\n";
            tank -= pre;
            if (tank < 0) return -1;
            if (next_ > tank){
                // cout << "where fill: " << stops[i] << "\n";
                count++;
                tank = full_tank;
            }
        pre = next_;
        }
    
    }
    return count;
    }


int main() {
    int d = 0; //目的地距離
    cin >> d;
    int m = 0; //滿油，可以開多久
    cin >> m;
    int n = 0; //有幾個加油站
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
