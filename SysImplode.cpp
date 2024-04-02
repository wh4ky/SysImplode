#include <thread>
#include <iostream>
#include <string>
#include <vector>

int g_state{0};

void seed(int);
int PRNG();
void RandomInterger();
void spawnThreads(int);

int main() {
    int x, y;

    std::cout << "seed value: ";
    std::cin >> x;
    seed(x);

    std::cout << "ammount of threads: ";
    std::cin >> y;
    spawnThreads(y);
}


// Functions
void seed(int seed) {
    g_state = seed;
}

int PRNG() {
    g_state = 8253729 * g_state + 2396403;
    return g_state % 32768;
}

void RandomInterger() {
    for (int count{ 1 }; count <= 4; ++count) {
        std::cout << PRNG() << '\n';
    }
}

void spawnThreads(int n) {
    std::vector<std::thread> threads(n);
    
    for (int i = 0; i < n; i++) {
        threads[i] = std::thread(RandomInterger);
    }

    for (auto& th : threads) {
        th.join();
    }
}