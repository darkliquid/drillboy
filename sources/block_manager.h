#ifndef _BLOCK_MANAGER_H
#define _BLOCK_MANAGER_H

#include "block.h"
#include <vector>

class Block;

#define WIDTH 10
#define HEIGHT 100

class BlockManager {
  public:
    void drill(int, int);
    void clean_up();
    void apply_gravity();
    std::vector<Block> get_adjacent_blocks(int, int);
  private:
    Block * current_level[10][100];
};

#endif // _BLOCK_MANAGER_H
