#include <iostream>
#include <vector>
#include <thread>
#include <cassert>
#include <future>
#include "clock.h"

// only for input
template <typename T>
T input(std::string s){
    T x;
    std::cout << s << "=? ";
    std::cin >> x;
    return x;
}

int fib(int x){
    if (x < 2)
        return x;
    else
        return fib(x-1) + fib(x-2);
}

void fib_thread(int x, int threshold, int& result){
    if (x < 2 || x <= threshold){
        result = fib(x);
    } else {
        int res1, res2;
        std::thread f1 (fib_thread, x-1, threshold, std::ref(res1));
        std::thread f2 (fib_thread, x-2, threshold, std::ref(res2));
        f1.join();
        f2.join();
        result = res1 + res2;
    }
}

int main(){
    std::cout << "hardware concurrency: " << std::thread::hardware_concurrency() << std::endl;
    Clock clock;
    auto n = input<int>("n");
    auto threshold = input<int>("threshold");
    int result;

    clock.tick();
    result = fib(n);
    clock.tock();
    std::cout << "fib(" << n << ")= " << result << " (" << clock.elapsed() << ")" << std::endl;
    auto ts = clock.end-clock.start;

    clock.tick();
    std::thread f (fib_thread, n, threshold, std::ref(result));
    f.join();
    clock.tock();
    std::cout << "fib(" << n << ")= " << result << " (" << clock.elapsed() << ")" << std::endl;
    auto tp = clock.end-clock.start;

    std::cout << "speedup " << double(ts.count()) / tp.count() << std::endl;


    return 0;
}
