#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here

    int count = 0, full_tank = tank, dis = stops[0];
    if (dist <= tank) return 0;
    if(dis > tank) return -1;

    stops.push_back(dist);
    tank -= stops[0];
    for( int i = 0; i<stops.size()-1; i++){
        dis = stops[i+1] - stops[i];
        if(dis > full_tank){
            return -1;
        }
        else if(tank >= dis){
            tank -= dis;
        }
        else{ // tank < dis
            tank = full_tank - dis;
            count++;
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