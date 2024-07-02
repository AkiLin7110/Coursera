#include <iostream>
#include <vector>
unsigned long long fibonacci_sum_naive(unsigned long long n) {
    if (n <= 1)
        return n;

    std::vector<unsigned long long> fi;  // fi.push_back(NUM)
    fi.push_back(0);
    fi.push_back(1);
    unsigned long long current;
    unsigned long long tmp = 1;

    for (unsigned long long i = 2;;i++){
        current = (fi[i-1] + fi[i-2]) % 10 ;
        // std::cout<< "current:" << current <<std::endl;
        if (current == 0 && fi[1] == fi[i-1]) break;

        fi.push_back(current);
        tmp += current;
        tmp %= 10;
        // std::cout<< "tmp:" << tmp <<std::endl;
    }

    // 算幾輪
    int q = n/(unsigned long long)fi.size();
    int r = n%(unsigned long long)fi.size();
    unsigned long long ans = tmp*q ;

    for (unsigned long long i = 0; i <= r ; i++){
        ans += fi[i];  
        // std::cout << "ans:" << ans << std::endl; 
    }


    return ans%10;
}

int main() {
    unsigned long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_naive(n) << std::endl;

    return 0;
}


// 0    1    1    2    3    5    8    13    21    34    55    89    144    233    377   610   987
// 0    1    1    2    3    5    8     3     1     4     5     9      4      3      7     0     7

// n = 3

// tmp = 4

// q = 3/4 = 0
// r = 3%4 = 3

