//
// Created by svirex on 16.10.2019.
//
#include <climits>
#include <cmath>
#include <iostream>
#include <vector>
#include <stdexcept>

using ull = unsigned long long;

void FillingPowsVector(ull a, unsigned pow, std::vector<ull> &pows) {
  pows.emplace_back(a);
  unsigned startPow = 2;
  while (startPow < pow) {
    // TODO insert ExceedLimit
    pows.emplace_back(static_cast<ull>(std::pow(a, startPow)));
    startPow *= 2;
  }
}

bool ExceedLimit(ull a, ull b, ull limit) { return a > limit / b; }

ull CalcNumber(ull num, ull pow) {
  std::vector<ull> pows;
  FillingPowsVector(num, pow, pows);
  ull answer = 1;
  for (size_t i = 0; i < pows.size(); ++i) {
    if (((pow >> i) & 1) == 1) {
      if (!ExceedLimit(answer, pows[i], ULLONG_MAX)) {
        answer *= pows[i];
      } else {
        std::cerr << "Exceed limit " << ULLONG_MAX;
        break;
      }
    }
  }
  return answer;
}

int main() {
  std::cout << CalcNumber(15, 300) << std::endl;
}
