#include <assert.h>
#include <stdint.h>
#include <string.h>

#include "stun/stunhmac.h"

int main (void) {
  uint8_t message[] = "some complicated input string which is over 44 bytes long";
  uint8_t key[] = "key";
  uint8_t hmac[20];

  const uint8_t expected_hmac[] = { 0x83, 0x5a, 0x9b, 0x05, 0xea,
                                    0xd7, 0x68, 0x45, 0x48, 0x74,
                                    0x6b, 0xa3, 0x37, 0xe0, 0xa9,
                                    0x3f, 0x4d, 0xb3, 0x9c, 0xa1 };

  const uint8_t expected_hmac2[] = { 0x58, 0xab, 0x5b, 0x3a, 0xc8,
                                     0x0d, 0x5e, 0x63, 0x06, 0xce,
                                     0x08, 0xfb, 0xd0, 0x36, 0xda,
                                     0xf4, 0x54, 0x9b, 0x61, 0x25 };

  stun_sha1(message, strlen((char*)message), 300, hmac, key, strlen((char*)key), 1);
  assert(!memcmp(hmac, expected_hmac, sizeof(hmac)));
  
  stun_sha1(message, strlen((char*)message), 300, hmac, key, strlen((char*)key), 0);
  assert(!memcmp(hmac, expected_hmac2, sizeof(hmac)));

  return 0;
}
