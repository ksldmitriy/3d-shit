#include "chunk.hpp"

Chunk::Chunk(glm::uvec3 size) {
  m_size = size;
  m_data.resize(size.x * size.y * size.z);
}

uint64_t Chunk::GetCellValue(glm::uvec3 pos) {
  size_t index = pos.x + (pos.y * m_size.x) + (pos.z * m_size.x * m_size.y);

  return m_data[index].val;
}
