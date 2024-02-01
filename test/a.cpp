#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>

std::mutex m;

void Print(char c) {
  std::lock_guard<std::mutex> guard(m);
  // m.lock();

  for (int i = 0; i < 10; ++i) {
    for (int j = 0; j < 10; ++j) {
      std::cout << c;
      std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << std::endl;
  }

  // m.unlock();
}

int main (int argc, char *argv[]) {
  std::thread t1(Print, '*');
  std::thread t2(Print, '#');

  t1.join();
  t2.join();
  
  return 0;
}
