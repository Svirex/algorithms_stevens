//
// Created by svirex on 16.10.2019.
//
#include <climits>
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <vector>

using ull = unsigned long long;

bool ExceedLimit(ull a, ull b, ull limit) { return a > limit / b; }

void FillingPowsVector(ull a, unsigned pow, std::vector<ull> &pows) {
  pows.emplace_back(a);
  unsigned startPow = 2;
  while (startPow < pow) {
    if (ExceedLimit(pows.back(), pows.back(), ULLONG_MAX)) {
      throw std::length_error("Exceed limit");
    }
    pows.emplace_back(static_cast<ull>(std::pow(a, startPow)));
    startPow *= 2;
  }
}

ull CalcNumber(ull num, ull pow) {
  std::vector<ull> pows;
  FillingPowsVector(num, pow, pows);
  ull answer = 1;
  for (size_t i = 0; i < pows.size(); ++i) {
    if (((pow >> i) & 1) == 1) {
      if (ExceedLimit(answer, pows[i], ULLONG_MAX)) {
        throw std::length_error("Exceed limit");
      }
      answer *= pows[i];
    }
  }
  return answer;
}

int main() { std::cout << CalcNumber(15, 300) << std::endl; }
