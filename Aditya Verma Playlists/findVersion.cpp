#include <iostream>

int main() {
    if (__cplusplus == 202004L) std::cout << "C++20\n";
	else if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "pre-standard C++\n";
    std::cout << (long long)__cplusplus << std::endl;

    if(int i = 1; i < 2){
        std::cout << '\n' << (i < 3);
    }
}