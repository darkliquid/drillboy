#ifndef _BLOCK_H_
#define _BLOCK_H_

#include "block_manager.h"

enum block_state {
  STABLE,
  SHAKING,
  BREAKABLE,
  SLIGHTLY_BROKEN,
  BROKEN,
  AWAITING_CLEANUP
};

enum block_type {
  TYPE_1,
  TYPE_2,
  TYPE_3,
  TYPE_4
};

class BlockManager;

class Block {
  public:
    Block(BlockManager *);
    void destroy();
    block_type getType();
    block_state getState();
  private:
    BlockManager * parent;
    int x, y;
    block_state state;
    block_type type;
};

#endif // _BLOCK_H_
