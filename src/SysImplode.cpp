#include <ctime>
#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <random>

// Mersenne twister algorithm
std::mt19937 mt;

void RandomNum();
void spawnThreads(int);

int main() {
    int init, thrd;

    std::cout << "seed value (0 for semi-random seed): ";
    std::cin >> init;
    if (init == 0) {init = time(nullptr);}
    mt.seed(init);

    std::cout << "ammount of threads: ";
    std::cin >> thrd;
    spawnThreads(thrd);
}


// Functions
void RandomNum() {
    std::cout << mt();
}

void spawnThreads(int n) {
    std::vector<std::thread> threads(n);
    
    for (int i = 0; i < n; i++) {
        threads[i] = std::thread(RandomNum);
    }

    for (auto& th : threads) {
        th.join();
    }
}