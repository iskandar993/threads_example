#include <iostream>
#include <thread>
#include <chrono>

int a = 56, b = 64;

void one(int a, int b){
    std::cout << a + b << std::endl;
}

void two(int a, int b){
    std::cout << a * b << std::endl;
}

void three(int a, int b){
    std::cout << a / b << std::endl;
}

void four(int a, int b){
    std::cout << a - b << std::endl;
}

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    one(a, b);
    two(a, b);
    three(a, b);
    four(a, b);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double>(end - start); 
    std::cout <<"birinchi vaqt "<< duration.count() * 100 << std::endl;

   
    auto start2 = std::chrono::high_resolution_clock::now();
    std::thread t1(one, a, b);
    std::thread t2(two, a, b);
    std::thread t3(three, a, b);
    std::thread t4(four, a, b);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    auto end2 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration<double>(end2 - start2);
    std::cout <<"Ikkinchi vaqt "<< duration1.count() * 100 << std::endl;

}