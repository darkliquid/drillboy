#include "block.h"

Block::Block(BlockManager * bm) {
  parent = bm;
}

void Block::destroy() {
  switch(state) {
    case BREAKABLE:
      state = SLIGHTLY_BROKEN;
      return;
    case SLIGHTLY_BROKEN:
      state = BROKEN;
      return;
    case AWAITING_CLEANUP: // this case should never happen, but better safe than sorry
      return;
    case STABLE:
      break;
    case SHAKING:
      break;
    case BROKEN:
      break;
  }

  // if it's not any of those, actually destroy the block and all matching adjacent ones
  state = AWAITING_CLEANUP;
  std::vector<Block> blocks = parent->get_adjacent_blocks(x, y);
  for(std::vector<Block>::iterator block = blocks.begin(); block < blocks.end(); block++) {
    if(block->getType() == type && block->getState() != AWAITING_CLEANUP) {
      block->destroy();
    }
  }
}

block_state Block::getState() {
  return state;
}

block_type Block::getType() {
  return type;
}
