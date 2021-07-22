<<<<<<< HEAD

Setup
---------------------
DigiByte Core is the original DigiByte client and it builds the backbone of the network. However, it downloads and stores the entire history of DigiByte transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.
=======
>>>>>>> bitcoin/8.22.0
DigiByte Core
=============

Setup
---------------------
<<<<<<< HEAD
DigiByte Core is the original DigiByte client and it builds the backbone of the network. It downloads and, by default, stores the entire history of DigiByte transactions (which is currently more than 100 GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download DigiByte Core, visit [digibytecore.org](https://digibytecore.org/en/releases/).
=======
DigiByte Core is the original DigiByte client and it builds the backbone of the network. It downloads and, by default, stores the entire history of DigiByte transactions, which requires a few hundred gigabytes of disk space. Depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

To download DigiByte Core, visit [digibytecore.org](https://digibytecore.org/en/download/).
>>>>>>> bitcoin/8.22.0

Running
---------------------
The following are some helpful notes on how to run DigiByte Core on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/digibyte-qt` (GUI) or
- `bin/digibyted` (headless)

### Windows

Unpack the files into a directory, and then run digibyte-qt.exe.

### macOS

Drag DigiByte Core to your applications folder, and then run DigiByte Core.

### Need Help?

* See the documentation at the [DigiByte Wiki](https://en.digibyte.it/wiki/Main_Page)
for help and more information.
<<<<<<< HEAD
* Ask for help on [Gitter](https://gitter.im/DigiByte-Core/protocol). If you don't have a Gitter client [find one here](https://gitter.im/apps).
=======
* Ask for help on [DigiByte StackExchange](https://digibyte.stackexchange.com).
* Ask for help on #digibyte on Libera Chat. If you don't have an IRC client, you can use [web.libera.chat](https://web.libera.chat/#digibyte).
* Ask for help on the [DigiByteTalk](https://digibytetalk.org/) forums, in the [Technical Support board](https://digibytetalk.org/index.php?board=4.0).
>>>>>>> bitcoin/8.22.0

Building
---------------------
The following are developer notes on how to build DigiByte Core on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [macOS Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [FreeBSD Build Notes](build-freebsd.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [NetBSD Build Notes](build-netbsd.md)
- [Android Build Notes](build-android.md)
- [Gitian Building Guide (External Link)](https://github.com/digibyte-core/docs/blob/master/gitian-building.md)

Development
---------------------
The DigiByte repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Productivity Notes](productivity.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
<<<<<<< HEAD
- [Source Code Documentation (External Link)](https://dev.visucore.com/digibyte/doxygen/)
=======
- [Source Code Documentation (External Link)](https://doxygen.digibytecore.org/)
>>>>>>> bitcoin/8.22.0
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [JSON-RPC Interface](JSON-RPC-interface.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)

### Resources
<<<<<<< HEAD

- Discuss project-specific development on [Gitter](https://gitter.im/DigiByte-Core/protocol). If you don't have a Gitter client find one [here](https://gitter.im/apps).
- Discuss general DigiByte development on the general Gitter channel [here](https://gitter.im/DigiByte-Core/community).
=======
* Discuss on the [DigiByteTalk](https://digibytetalk.org/) forums, in the [Development & Technical Discussion board](https://digibytetalk.org/index.php?board=6.0).
* Discuss project-specific development on #digibyte-core-dev on Libera Chat. If you don't have an IRC client, you can use [web.libera.chat](https://web.libera.chat/#digibyte-core-dev).
>>>>>>> bitcoin/8.22.0

### Miscellaneous

- [Assets Attribution](assets-attribution.md)
- [digibyte.conf Configuration File](digibyte-conf.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [I2P Support](i2p.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [PSBT support](psbt.md)
- [Reduce Memory](reduce-memory.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
