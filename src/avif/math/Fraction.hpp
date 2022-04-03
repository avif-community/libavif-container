//
// Created by psi on 2022/03/24.
//
#pragma once

#include <cstdint>
#include <numeric>
#include <complex>

namespace avif::math {

struct Fraction {
private:
  int32_t numerator_;
  int32_t denominator_;
public:
  explicit constexpr Fraction(int32_t const numerator, int32_t const denominator)
  :numerator_(denominator >= 0 ? numerator : -numerator)
  ,denominator_(std::abs(denominator))
  {
  }

  [[ nodiscard ]] constexpr Fraction reduce() const {
    if(denominator_ == 0) {
      return Fraction(0, 1);
    }
    int32_t const r = std::gcd(std::abs(numerator_), std::abs(denominator_));
    return Fraction(numerator_ / r, denominator_ / r);
  }
  [[ nodiscard ]] constexpr Fraction minus(Fraction const& b) const {
    int32_t const r = std::lcm(std::abs(denominator_), std::abs(b.denominator_));
    return Fraction((r / denominator_ * numerator_) - (r / b.denominator_ * b.numerator_), r).reduce();
  }
  [[ nodiscard ]] constexpr int32_t numerator() const {
    return numerator_;
  }
  [[ nodiscard ]] constexpr int32_t denominator() const {
    return denominator_;
  }
  [[ nodiscard ]] constexpr bool isInteger() const {
    return denominator_ == 1;
  }
  [[ nodiscard ]] constexpr Fraction div(int32_t const d) const {
    return d > 0 ?
      Fraction(numerator_, denominator_ * d).reduce() :
      Fraction(-numerator_, denominator_ * -d).reduce();
  }
};

}