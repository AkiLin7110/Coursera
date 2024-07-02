#include <iostream>
#include <vector>
unsigned long long fibonacci_sum_naive(unsigned long long n, unsigned long long m) {

    // std::vector<unsigned long long> fi;  // fi.push_back(NUM)
    // fi.push_back(0);
    // fi.push_back(1);
    // unsigned long long current;
    // unsigned long long tmp1 = 1, tmp2 = 0;

    // for (unsigned long long i = 2; i<=m ;i++){
    //     current = (fi[i-1] + fi[i-2]) % 10 ;
    //     // std::cout<< "current:" << current <<std::endl;
    //     // std::cout<< "i:" << i <<std::endl; //i = 60
    //     if (current == 0 && fi[1] == fi[i-1]) break;

    //     fi.push_back(current);
    //     tmp1 += current;
    //     tmp1 %= 10;
    //     if(i==n-1){
    //         tmp2 = tmp1;
    //     }
    //     // std::cout<< "tmp:" << tmp <<std::endl;
    // }

    // // 算幾輪
    // int q = n/(unsigned long long)fi.size();
    // int r = n%(unsigned long long)fi.size();
    // unsigned long long ans1 = (tmp1*q)%10, ans2;
    // // std::cout<<i<<std::endl;
    // std::cout<<q<<" "<<r<<std::endl;

    // for (unsigned long long i = 0; i < r ; i++){
    //     ans1 += fi[i];
    // }

    // q = m/(unsigned long long)fi.size();
    // r = m%(unsigned long long)fi.size();
    // ans2 = (tmp2*q)%10;

    // for (unsigned long long i = 0; i <= r ; i++){
    //     ans2 += fi[i];
    // }

    // std::cout<<ans2<<" "<<ans1<<std::endl;
    // ans2 %= 10;
    // ans2 -= ans1%10;

    // if(ans2 < 0){
    //     ans2 += 10;
    // }

    // return ans2%10;
    unsigned long long sum = 0;
    n = (n % 60); // pisano(10) = 60
    m = (m % 60);

    // make sure n is greater than m
    if (m < n)
        m += 60;

    unsigned long long current = 0;
    unsigned long long next  = 1;
    unsigned long long newCurrent;


    for (int i = 0; i <= m; i++) {
        if (i >= n) {
            sum += current;
        }

        newCurrent = next;
        next = next + current;
        current = newCurrent;
    }

    return (int) (sum % 10);

}

int main() {
    unsigned long long n, m;
    std::cin >> n >> m;
    std::cout << fibonacci_sum_naive(n, m) << std::endl;

    return 0;
}


// 0    1    1    2    3    5    8    13    21    34    55    89    144    233    377   610   987
// 0    1    1    2    3    5    8     3     1     4     5     9      4      3      7     0     7
// 0    1    2    4    7    12   20   23    24

// n = 3

// tmp = 4

// q = 3/4 = 0
// r = 3%4 = 3

