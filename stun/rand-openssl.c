#include <openssl/rand.h>

#include "rand.h"

void nice_RAND_nonce(uint8_t *dst, int len) {
  RAND_bytes(dst, len);
}
