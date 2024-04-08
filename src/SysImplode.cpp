#include <chrono>
#include <iostream>
#include <random>
#include <thread>
#include <vector>

// Global vars
std::mt19937_64 mt; // Mersenne-Twister algorithm
const unsigned long long MAX_NUM =
	std::numeric_limits<unsigned long long>::max();

// Function declerations
std::chrono::_V2::system_clock::time_point
	SpawnThreads(unsigned long long, unsigned long long, bool);
void RandomNum(unsigned long long);
void RandomNumInf();

// Main
int main() {
    unsigned long long thrd, times;
	mt.seed(std::random_device()());
	std::vector<std::thread> VEC_MAX;
	bool inf = false;

	std::cout << "Max number: " << MAX_NUM << std::endl;
	std::cout << "Max thread number: "
		<< VEC_MAX.max_size() << std::endl << std::endl;

	std::cout << "How many times to run the algorithm:\n-1 for the maximum interger (2^64)\n0 for infinite\n";
	std::cin >> times;
	if (times == 0) {inf = true;}

	std::cout << "Amount of threads to create:\n0 for the maximum interger (2^60)\n";
	std::cin >> thrd;
	if (thrd == 0) {thrd = VEC_MAX.max_size();}

	auto t1 = std::chrono::high_resolution_clock::now();

	const std::chrono::duration<double, std::milli> ms =
		SpawnThreads(thrd, times, inf) - t1;
		
	std::cout << "Program took: " << ms.count() << " ms." << std::endl;

	return 0;
}

// Functions
std::chrono::_V2::system_clock::time_point
SpawnThreads(unsigned long long thrd, unsigned long long times, bool inf) {
	std::vector<std::thread> threads(thrd);

	if (inf) {for (unsigned long long i = 0; i < thrd; i++) {
		threads[i] = std::thread(RandomNumInf);
	}}
	
	else {for (unsigned long long i = 0; i < thrd; i++) {
		threads[i] = std::thread(RandomNum, times);
	}}

	for (auto &th : threads) {
		th.join();
	}

	std::cout << std::endl;

	return std::chrono::high_resolution_clock::now();
}

void RandomNum(unsigned long long times) {
	for (unsigned long long i = 0; i < times; i++) {
		auto v = mt();
		std::cout << v;
		mt.seed(v);
	}
}

void RandomNumInf() {
	while(true) {
		auto v = mt();
		std::cout << v;
		mt.seed(v);
	}
}