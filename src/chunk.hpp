#pragma once
#include "cell.hpp"
#include <glm/glm.hpp>
#include <vector>

class Chunk {
public:
  Chunk() = default;
  Chunk(glm::uvec3 size);

  uint64_t GetCellValue(glm::uvec3 pos);

private:
  glm::uvec3 m_size;
  std::vector<Cell> m_data;
};
