#include <iostream>
#include <thread>
#include <chrono>

void func() {
    std::cout << "Hello\t" << std::this_thread::get_id() << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main(){
    auto f = func;
    std::thread t(f);
    for (int i = 0; i<10; ++i){
        std::cout <<"main function\t" <<std::this_thread::get_id() << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    return 0;
}