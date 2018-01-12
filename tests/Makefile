CC=clang
USE_GNUTLS=0
ifeq ($(USE_GNUTLS), 1)
LDFLAGS=-lgnutls
CFLAGS=-I/usr/local/opt/gnutls/include -I..
LIB=../stun/rand.o ../stun/stunhmac.o
else
CFLAGS=-I/usr/local/opt/openssl/include -I..
LDFLAGS=-lssl -lcrypto -ldl
LIB=../stun/rand-openssl.o ../stun/stunhmac-openssl.o
endif

all: test-rand test-hmac test-hash

test-rand: test-rand.o $(LIB)
	$(CC) -o test-rand test-rand.o $(LIB) $(LDFLAGS)

test-hash: test-hash.o $(LIB)
	$(CC) -o test-hash test-hash.o $(LIB) $(LDFLAGS)

test-hmac: test-hmac.o $(LIB)
	$(CC) -o test-hmac test-hmac.o $(LIB) $(LDFLAGS)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f *.o ../stun/*.o
	rm -f test-rand test-hash test-hmac
