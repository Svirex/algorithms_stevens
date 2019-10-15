//
// Created by svirex on 15.10.2019.
//
#include <iostream>

int gcd(int a, int b) {
  while (b != 0) {
    int reminder = a % b;
    a = b;
    b = reminder;
  }
  return a;
}

int main() {
  std::cout << gcd(3, 15) << std::endl; // 3
  std::cout << gcd(4, 6) << std::endl; // 2
  std::cout << gcd(1300, 3055) << std::endl; // 65
  std::cout << gcd(3, 2) << std::endl; // 1
  return 0;
}