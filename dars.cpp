#include <iostream>
#include <thread>
#include <chrono>

int add (int a, int b){
    return a + b;
}
int abss (int d, int c){
    return d * c;
}

int main (){
    int val;
    
    //val = add(4, 5);
    auto start = std::chrono::high_resolution_clock::now();
       auto g = [](int d, int c)->void{
        std::cout << d * c << std::endl;
    };
    std::thread t1(g, 45, 56);
    auto f = [](int a, int b)->void{
        std::cout << a +b << std::endl;
    };
    std::thread t(f, 4,5);

    t.join();
    t1.join();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(end - start);
    std::cout << duration.count() * 100;
    //std::cout << val << std::endl;
}

