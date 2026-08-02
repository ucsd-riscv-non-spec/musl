
# MUSL LibC (Non-Spec Modification)

## How to configure
```
CC=clang-21 ./configure --prefix=/path/to/install --disable-shared
```

> [!NOTE]
> `--enable-optimize=no` and `--enable-debug` may also be useful.

## How to build
```
make install
```

## How to use MUSL LibC

Easiest way is to just add `--sysroot=/path/to/install` to your compiler flags.

# About

> musl, pronounced like the word "mussel", is an MIT-licensed
> implementation of the standard C library targetting the Linux syscall
> API, suitable for use in a wide range of deployment environments. musl
> offers efficient static and dynamic linking support, lightweight code
> and low runtime overhead, strong fail-safe guarantees under correct
> usage, and correctness in the sense of standards conformance and
> safety. musl is built on the principle that these goals are best
> achieved through simple code that is easy to understand and maintain.

> The 1.1 release series for musl features coverage for all interfaces
> defined in ISO C99 and POSIX 2008 base, along with a number of
> non-standardized interfaces for compatibility with Linux, BSD, and
> glibc functionality.

> For basic installation instructions, see the included INSTALL file.
> Information on full musl-targeted compiler toolchains, system
> bootstrapping, and Linux distributions built on musl can be found on
> the project website:

[musl-libc.org](http://www.musl-libc.org/)
