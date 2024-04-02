#include <ctime>
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>
#include <chrono>

// Global vars
std::mt19937 mt; // Mersenne-Twister algorithm
const int MAX_NUM = std::numeric_limits<int>::max();

// Function declerations
std::chrono::_V2::system_clock::time_point SpawnThreads(int, int);
void RandomNum(int);


int main() {
    int init, thrd, times;

    std::cout << "Seed value to use (0 for a semi-random seed): ";
    std::cin >> init;
    if (init == 0) {init = time(nullptr);}
    mt.seed(init);

    std::cout << "How many times to run the algorithm (0 for the maximum interger): ";
    std::cin >> times;
    if (times == 0) {times = MAX_NUM;}

    std::cout << "Amount of threads to create (0 for the maximum interger): ";
    std::cin >> thrd;
    if (thrd == 0) {thrd = MAX_NUM;};

    auto t1 = std::chrono::high_resolution_clock::now();

    const std::chrono::duration<double, std::milli> fp_ms = SpawnThreads(thrd, times) - t1;
    std::cout << "Program took: " << fp_ms.count() << " ms." << std::endl;

    return 0;
}

// Functions
std::chrono::_V2::system_clock::time_point SpawnThreads(int thrd, int times) {
    std::vector<std::thread> threads(thrd);
    
    for (int i = 0; i < thrd; i++) {
        threads[i] = std::thread(RandomNum, times);
    }

    for (auto& th : threads) {
        th.join();
    }

    std::cout << std::endl;

    return std::chrono::high_resolution_clock::now();
}

void RandomNum(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << mt();
    }
}