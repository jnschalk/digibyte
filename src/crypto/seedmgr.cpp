// Copyright (c) 2020 barrystyle
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <crypto/seedmgr.h>

#include <chainparams.h>
#include <crypto/randomx.h>
#include <crypto/randomx/randomx.h>
#include <interfaces/chain.h>
#include <node/context.h>
#include <rpc/blockchain.h>
#include <util/system.h>
#include <wallet/wallet.h>

int seedmgr::getlastepoch()
{
    return lastepoch;
}

void seedmgr::setlastepoch(int epoch)
{
    lastepoch = epoch;
}

int seedmgr::currentepoch(int height)
{
    const int epochlen = Params().GetConsensus().nEpochLength;
    return (height / epochlen) * epochlen;
}

void seedmgr::setseedhash(uint256 hash)
{
    lastseed = currentseed;
    currentseed = hash;
}

uint256 seedmgr::getlastseed()
{
    return lastseed;
}

uint256 seedmgr::getseedhash(int epoch)
{
    uint256 seedhash {};
    const auto it = seedcache.find(epoch);
    if (it != seedcache.end())
        seedhash = it->second;
    return seedhash;
}

void seedmgr::updateheight(int height)
{
    const int epoch = currentepoch(height);
    if (epoch != this->getlastepoch()) {
        uint256 newseed = getseedhash(epoch);
        printf("%s - seed changed from %s to %s\n", __func__, lastseed.ToString().c_str(), newseed.ToString().c_str());
        lastseed = newseed;
        setlastepoch(epoch);
    }
}
