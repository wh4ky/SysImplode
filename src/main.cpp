#include <chrono> 
#include <iostream>
#include <random>
#include <string>
#include <sstream>
#include <thread>
#include <vector>

#include "ArgHandler.hpp"

// Global random number generator
std::mt19937_64 generator; 

// Function declarations
void generateRandomNumbers(unsigned long long);
std::chrono::system_clock::time_point spawnThreads(
  unsigned long long, unsigned long long);

// Main
int main(int argc, char* argv[]) {

  // Argument variables
  unsigned long long threads, iterations;  

  // Seed generator
  generator.seed(std::random_device()());

  // Parse arguments
  int result = ArgHandler(argc, argv);

  if(result == 0) return 1;

  if(result == 1) {
    try {
      std::stringstream(argv[2]) >> iterations;
    } catch(const std::exception& e) {
      std::cout << "Error parsing iterations\n";
    }

    try {  
      std::stringstream(argv[3]) >> threads;
    } catch(const std::exception& e) {
      std::cout << "Error parsing threads\n";
    }
  } else if(result == -1) {}

  // Start timer
  auto start = std::chrono::high_resolution_clock::now();

  // Spawn threads
  auto end = spawnThreads(threads, iterations);

  // Print elapsed time
  std::chrono::duration<double, std::milli> ms = end - start;
  std::cout << std::endl << "Time taken: " << ms.count() << "ms\n";

  return 0;

}

std::chrono::system_clock::time_point spawnThreads(unsigned long long threads, unsigned long long iterations) {

  std::vector<std::thread> threadPool(threads);

  for(unsigned long long i = 0; i < threads; i++) {
    threadPool[i] = std::thread(generateRandomNumbers, iterations); 
  }

  for(auto& thread : threadPool) {
    thread.join();
  }

  return std::chrono::system_clock::now();

}

void generateRandomNumbers(unsigned long long iterations) {

  for(unsigned long long i = 0; i < iterations; i++) {
    std::cout << generator();
  }

}
