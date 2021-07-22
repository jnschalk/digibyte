// Copyright (c) 2009-2010 Satoshi Nakamoto
<<<<<<< HEAD
// Copyright (c) 2009-2018 The DigiByte Core developers
=======
// Copyright (c) 2009-2020 The DigiByte Core developers
>>>>>>> bitcoin/8.22.0
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIGIBYTE_COMPAT_H
#define DIGIBYTE_COMPAT_H

#if defined(HAVE_CONFIG_H)
#include <config/digibyte-config.h>
<<<<<<< HEAD
#endif

#include <type_traits>

// GCC 4.8 is missing some C++11 type_traits,
// https://www.gnu.org/software/gcc/gcc-5/changes.html
#if defined(__GNUC__) && __GNUC__ < 5
#define IS_TRIVIALLY_CONSTRUCTIBLE std::is_trivial
#else
#define IS_TRIVIALLY_CONSTRUCTIBLE std::is_trivially_constructible
=======
>>>>>>> bitcoin/8.22.0
#endif

#ifdef WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#ifdef FD_SETSIZE
#undef FD_SETSIZE // prevent redefinition compiler warning
#endif
#define FD_SETSIZE 1024 // max number of fds in fd_set
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdint.h>
#else
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <net/if.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <limits.h>
#include <netdb.h>
#include <unistd.h>
#endif

#ifndef WIN32
typedef unsigned int SOCKET;
#include <errno.h>
#define WSAGetLastError()   errno
#define WSAEINVAL           EINVAL
#define WSAEALREADY         EALREADY
#define WSAEWOULDBLOCK      EWOULDBLOCK
#define WSAEAGAIN           EAGAIN
#define WSAEMSGSIZE         EMSGSIZE
#define WSAEINTR            EINTR
#define WSAEINPROGRESS      EINPROGRESS
#define WSAEADDRINUSE       EADDRINUSE
#define WSAENOTSOCK         EBADF
#define INVALID_SOCKET      (SOCKET)(~0)
#define SOCKET_ERROR        -1
#else
#ifndef WSAEAGAIN
#ifdef EAGAIN
#define WSAEAGAIN EAGAIN
#else
#define WSAEAGAIN WSAEWOULDBLOCK
#endif
#endif
#endif

#ifdef WIN32
#ifndef S_IRUSR
#define S_IRUSR             0400
#define S_IWUSR             0200
#endif
#else
#define MAX_PATH            1024
#endif
#ifdef _MSC_VER
#if !defined(ssize_t)
#ifdef _WIN64
typedef int64_t ssize_t;
#else
typedef int32_t ssize_t;
#endif
#endif
#endif

#if HAVE_DECL_STRNLEN == 0
size_t strnlen( const char *start, size_t max_len);
#endif // HAVE_DECL_STRNLEN

#ifndef WIN32
typedef void* sockopt_arg_type;
#else
typedef char* sockopt_arg_type;
#endif

// Note these both should work with the current usage of poll, but best to be safe
// WIN32 poll is broken https://daniel.haxx.se/blog/2012/10/10/wsapoll-is-broken/
// __APPLE__ poll is broke https://github.com/digibyte/digibyte/pull/14336#issuecomment-437384408
#if defined(__linux__)
#define USE_POLL
#endif

bool static inline IsSelectableSocket(const SOCKET& s) {
#if defined(USE_POLL) || defined(WIN32)
    return true;
#else
    return (s < FD_SETSIZE);
#endif
}

<<<<<<< HEAD
=======
// MSG_NOSIGNAL is not available on some platforms, if it doesn't exist define it as 0
#if !defined(MSG_NOSIGNAL)
#define MSG_NOSIGNAL 0
#endif

// MSG_DONTWAIT is not available on some platforms, if it doesn't exist define it as 0
#if !defined(MSG_DONTWAIT)
#define MSG_DONTWAIT 0
#endif

>>>>>>> bitcoin/8.22.0
#endif // DIGIBYTE_COMPAT_H
