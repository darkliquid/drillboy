#include "block_manager.h"
#include <vector>

std::vector<Block> BlockManager::get_adjacent_blocks(int x, int y) {
  // do something to return a vector of blocks
  // it will always be either 3 (in the case of being next to a wall) or 4 long
  std::vector<Block> blocks;
  if(x > 0) {
    blocks.push_back(*current_level[x - 1][y]);
  }
  if(x < WIDTH) {
    blocks.push_back(*current_level[x + 1][y]);
  }
  if(y > 0) {
    blocks.push_back(*current_level[x][y - 1]);
  }
  if(y < HEIGHT) {
    blocks.push_back(*current_level[x][y + 1]);
  }
  return blocks;
}

void BlockManager::drill(int x, int y) {
  Block * block = current_level[x][y];
  if(block) {
    // destroy the block
    block->destroy();
    // clean up blocks queued for destruction
    clean_up();
    // now tell the block manager to initiate falling procedures for remaining blocks
    apply_gravity();
  }
}

void BlockManager::clean_up() {
}

void BlockManager::apply_gravity() {
}
