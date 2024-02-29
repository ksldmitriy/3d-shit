#pragma once
#include "chunk.hpp"
#include "cool-chunk.hpp"
#include <chrono>
#include <iostream>
#include <random>

size_t test_chunk(Chunk &chunk, std::uniform_int_distribution<uint> dist,
                  size_t iterations);

size_t test_chunk(CoolChunk &chunk, std::uniform_int_distribution<uint> dist,
                  size_t iterations);
