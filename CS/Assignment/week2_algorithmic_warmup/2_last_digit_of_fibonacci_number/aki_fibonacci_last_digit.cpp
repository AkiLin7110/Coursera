#include <iostream>
#include <cassert>

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int main() {
    unsigned long n = 0;
    int ans, a=0, b=1;
    std::cin >> n;

    if(n==0){
        std::cout << 0 << '\n';
        return 0;
    }
    if(n==1){
        std::cout << 1 << '\n';
        return 0;
    }
    
    for(int i = 2; i<n+1; i++){
        ans = (a + b)%10;
        a = b;
        b = ans;
    }

    std::cout << ans << '\n';
    return 0;
}
