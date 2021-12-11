#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

int main() {
  std::vector<size_t> V;
  const size_t N = 4;
  const size_t K = 21;
  V.resize(K);
  std::vector<std::thread> Threads(N); 
  for(size_t i = 0; i < N; ++i) {
    Threads[i] = std::thread([i]() {
        std::cout << "Thread " << i << " started" << std::endl;
        }
        );
  }


  for(size_t i = 0; i < N; ++i) {
    Threads[i].join();
  }
}
