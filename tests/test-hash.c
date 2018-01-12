#include <assert.h>
#include <inttypes.h>
#include <string.h>

#include "stun/stunhmac.h"

int main() {
  const uint8_t realm[] = "example.org";
  const uint8_t username[] = "username";
  const uint8_t password[] = "password";
  uint8_t md5[16];

  const uint8_t expected_md5[] = {0xba, 0x0c, 0xc7, 0xe0, 0xec, 0x20, 0x69, 0xf8, 0x38, 0x78, 0x83, 0xbd, 0x78, 0xc6, 0x2b, 0x30};

  stun_hash_creds(realm, strlen((char*)realm), username, strlen((char*)username), password, strlen((char*)password), md5);

  assert(!memcmp(md5, expected_md5, sizeof(md5)));

  return 0;
}
