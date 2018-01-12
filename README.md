libnice-openssl
===

We are upgrading our server to the latest [libnice](https://github.com/libnice/libnice) library (0.14.1 at the time of writing). However, latest libnice depends on [GnuTLS](https://www.gnutls.org/). This is undesirable due to we use OpenSSL and also statically link our server. Statically linking with GnuTLS seems rather difficult due to dependency on p11-kit.

This project provides some libnice functionality implemented on top of OpenSSL.

Some files are taken from libnice (`stun/stun.h`, `stun/stun.c`, `stun/stunhmac.h` and `stun/stunhmac.c`). Couple of files were reduced to minimum (`stun/constants.h` and `stun/stunmessage.h`). `stun/rand-openssl.c` and `stun/stunhmac-openssl.c` are the respective implementation using OpenSSL.

Building
--

In `tests/Makefile`, specify whether you want use GnuTLS and adjust compile parameters.
