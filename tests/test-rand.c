#include <assert.h>
#include <inttypes.h>
#include <string.h>

#include "stun/rand.h"

int main(void) {

  uint8_t rand1[10];
  uint8_t rand2[10];

  nice_RAND_nonce(rand1, sizeof(rand1));
  nice_RAND_nonce(rand1, sizeof(rand2));

  assert(memcmp(rand1, rand2, sizeof(rand1)));

  return 0;
}
