#include <iostream>
#include <vector>
long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;
    
    int current, i = 2;
    std::vector<int> fi;
    fi.push_back(0);
    fi.push_back(1);
    while(true){
        current = (fi[i-1] + fi[i-2]) % m;
        if(!current && (current + fi[i-1]) % m == fi[1])  break;
        i++;
        fi.push_back(current);
    }
    return fi[n%fi.size()];
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}

// n = 10  m = 3
//     0    1    2    3    4    5    6     7     8     9    10    11     12     13    14   15   16   17
//     0    1    1    2    3    5    8    13    21    34    55    89    144    333   577  910 1487 2397
//     0    1    1    2    0    2    2     1     0     1     1     2      0      2     2    1    0    1

// fi.size() = 8