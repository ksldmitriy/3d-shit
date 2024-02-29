#include "cool-chunk.hpp"

#include <cstdlib>

CoolChunk::CoolChunk(glm::uvec3 size) {
  m_size = size;
  m_data.resize(size.x * size.y * size.z);
}

uint64_t CoolChunk::GetCellValue(glm::uvec3 pos) {
  int chunk_index = 0;
  int sub_index = 0;

  std::div_t div;

  div = std::div((int)pos.x, (int)sub_chunk_size);
  chunk_index += div.quot;
  sub_index += div.rem;

  div = std::div((int)pos.y, (int)sub_chunk_size);
  chunk_index += div.quot * (m_size.x / sub_chunk_size);
  sub_index += div.rem * sub_chunk_size;

  div = std::div((int)pos.z, (int)sub_chunk_size);
  chunk_index +=
      div.quot * (m_size.x * m_size.y / sub_chunk_size, sub_chunk_size);
  sub_index += div.rem * sub_chunk_size * sub_chunk_size;

  int index = (chunk_index * sub_chunk_size * sub_chunk_size * sub_chunk_size) +
              sub_index;

  return m_data[index].val;
}
