#include <iostream> //for input, output
#include <vector>
#include <algorithm> //找最大值
#include <ctime> //報時
using namespace std;

int main(){
    
    // double start_time = (double)clock();
    long n ;
    cin >> n;
    // vector<int> numbers(n);
    // numbers.push_back
    long long tmp,a,b;
    cin >> a;
    cin >> b;

    if (b > a) // 確定a大b小
    {
        tmp = a;
        a = b;
        b = tmp;
    }

    for (int i = 2; i < n; i++){
        cin >> tmp;

        if (tmp > b){
            b = tmp;
            if (b > a) // 確定a大b小
            {
                tmp = a;
                a = b;
                b = tmp;
            }
        }


    }

    cout << a*b << "\n" ;

    // double end_time = (double)clock();
    // double delta = end_time - start_time;
    // cout << delta << "\n";
    return 0;
}