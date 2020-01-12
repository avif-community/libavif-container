//
// Created by psi on 2019/11/25.
//

#include "StreamWriter.hpp"

namespace avif::util {

void StreamWriter::putU8(uint8_t data) {
  this->buff_.emplace_back(data);
}

void StreamWriter::putU16L(uint16_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
}

void StreamWriter::putU16B(uint16_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
}

void StreamWriter::putU32L(uint32_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 16u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 24u) & 0xffu);
}

void StreamWriter::putU32B(uint32_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 24u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 16u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
}

void StreamWriter::putU64L(uint64_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 16u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 24u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 32u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 40u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 48u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 56u) & 0xffu);
}

void StreamWriter::putU64B(uint64_t data) {
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 56u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 48u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 40u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 32u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 24u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 16u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 8u) & 0xffu);
  this->buff_.emplace_back(static_cast<uint16_t>(data >> 0u) & 0xffu);
}

void StreamWriter::append(std::vector<uint8_t> const& data) {
  this->buff_.insert(this->buff_.end(), data.begin(), data.end());
}

void StreamWriter::append(uint8_t const*const data, size_t const length) {
  this->buff_.insert(this->buff_.end(), data, data + length);
}

}