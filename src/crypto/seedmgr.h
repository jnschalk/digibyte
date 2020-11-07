// Copyright (c) 2020 barrystyle
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef DIGIBYTE_SEEDMGR_H
#define DIGIBYTE_SEEDMGR_H

#include <uint256.h>
#include <util/system.h>

class seedmgr;
class uint256;

class seedmgr {
private:
    int lastepoch { 0 };
    uint256 lastseed {};
    uint256 currentseed {};

public:
    int getlastepoch();
    void setlastepoch(int epoch);
    int currentepoch(int height);
    void setseedhash(uint256 hash);
    uint256 getlastseed();
    uint256 getseedhash(int epoch);
    void updateheight(int height);
};

#endif // DIGIBYTE_SEEDMGR_H
