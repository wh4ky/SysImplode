#include <ctime>
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <limits>

// Mersenne twister algorithm
std::mt19937 mt;
const int MAX_NUM = std::numeric_limits<int>::max();

void RandomNum(int);
void spawnThreads(int, int);

int main() {
    int init, thrd, times;

    std::cout << "seed value (0 for semi-random seed): ";
    std::cin >> init;
    if (init == 0) {init = time(nullptr);}
    mt.seed(init);

    std::cout << "How many times to run algorithm (0 for maximum interger): ";
    std::cin >> times;
    if (times == 0) {times = MAX_NUM;}

    std::cout << "ammount of threads (0 for maximum interger): ";
    std::cin >> thrd;
    if (thrd == 0) {thrd = MAX_NUM;}
    spawnThreads(thrd, times);
}


// Functions
void spawnThreads(int thrd, int times) {
    std::vector<std::thread> threads(thrd);
    
    for (int i = 0; i < thrd; i++) {
        threads[i] = std::thread(RandomNum, times);
    }

    for (auto& th : threads) {
        th.join();
    }
}

void RandomNum(int times) {
    for (int i = 0; i < times; i++) {
        std::cout << mt();
    }
}