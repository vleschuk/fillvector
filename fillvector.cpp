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
  std::atomic<size_t> Current(0);
  for(size_t i = 0; i < N; ++i) {
    Threads[i] = std::thread([i, &Current, &V]() {
        const size_t Next = (i == N - 1) ? 0 : i + 1;
        size_t Idx = i;
        while(Idx < K) {
          while(Current.load() != i) {}
          V[Idx] = i;
          Idx += N;
          Current = Next;
          }
        }
        );
  }


  for(size_t i = 0; i < N; ++i) {
    Threads[i].join();
  }

  for(auto i : V) {
    std::cout << i << std::endl;
  }
}
