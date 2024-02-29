#pragma once
#include "cell.hpp"
#include <glm/glm.hpp>
#include <vector>

class CoolChunk {
public:
  CoolChunk() = default;
  CoolChunk(glm::uvec3 size);

  uint64_t GetCellValue(glm::uvec3 pos);

private:
  glm::uvec3 m_size;
  std::vector<Cell> m_data;
  static constexpr uint sub_chunk_size = 4;
};
