#include "main.hpp"

namespace chrono = std::chrono;
using time_point_t = chrono::high_resolution_clock::time_point;
using duration_t = chrono::high_resolution_clock::duration;
constexpr auto now = chrono::high_resolution_clock::now;

static std::mt19937_64 rand_engine;
static const int seed = 69;

int main() {
  const uint chunk_size = 128 * 9;
  const uint iterations = 10000000;
  std::uniform_int_distribution<uint> dist(1, chunk_size - 2);

  { // regular chunk benchmark
    Chunk chunk(glm::uvec3(chunk_size, chunk_size, chunk_size));
    rand_engine.seed(seed);

    time_point_t start = now();
    test_chunk(chunk, dist, iterations);
    time_point_t end = now();

    duration_t duration = end - start;
    size_t time = chrono::duration_cast<chrono::microseconds>(duration).count();

    std::cout << "regular chunk time: " << time << std::endl;
  }

  { // cool chunk benchmark
    CoolChunk chunk(glm::uvec3(chunk_size, chunk_size, chunk_size));
    rand_engine.seed(seed);

    time_point_t start = now();
    test_chunk(chunk, dist, iterations);
    time_point_t end = now();

    duration_t duration = end - start;
    size_t time = chrono::duration_cast<chrono::microseconds>(duration).count();

    std::cout << "cool chunk time: " << time << std::endl;
  }
}

size_t test_chunk(Chunk &chunk, std::uniform_int_distribution<uint> dist,
                  size_t iterations) {
  int total; // used to prevent compiler to wipe function

  for (int i = 0; i < iterations; i++) {
    glm::uvec3 pos;
    pos.x = dist(rand_engine);
    pos.y = dist(rand_engine);
    pos.z = dist(rand_engine);

    total += chunk.GetCellValue(pos);

    total += chunk.GetCellValue(pos + glm::uvec3(1, 0, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(-1, 0, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 1, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, -1, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 0, 1));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 0, -1));
  }

  return total;
}

size_t test_chunk(CoolChunk &chunk, std::uniform_int_distribution<uint> dist,
                  size_t iterations) {
  int total; // used to prevent compiler to wipe function

  for (int i = 0; i < iterations; i++) {
    glm::uvec3 pos;
    pos.x = dist(rand_engine);
    pos.y = dist(rand_engine);
    pos.z = dist(rand_engine);

    total += chunk.GetCellValue(pos);

    total += chunk.GetCellValue(pos + glm::uvec3(1, 0, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(-1, 0, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 1, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, -1, 0));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 0, 1));
    total += chunk.GetCellValue(pos + glm::uvec3(0, 0, -1));
  }

  return total;
}
