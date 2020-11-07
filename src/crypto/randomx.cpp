// Copyright (c) 2020 barrystyle
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <crypto/randomx.h>

#include <chainparams.h>
#include <crypto/randomx/randomx.h>
#include <crypto/seedmgr.h>
#include <primitives/block.h>
#include <primitives/moneroheader.h>

rxhash* blk_reader = new rxhash();
rxhash* blk_miner { nullptr };
seedmgr seedmanager;

void rxhash::init()
{
    this->cacheinit();
    this->vminit();
}

bool rxhash::hasseedchanged()
{
    int last_epoch = seedmanager.getlastepoch();
    uint256 last_seed = seedmanager.getlastseed();
    uint256 current_seed = seedmanager.getseedhash(last_epoch);
    if (last_seed != current_seed)
        return true;
    return false;
}

void rxhash::cacheinit()
{
    flags = randomx_get_flags();
    cache = randomx_alloc_cache(flags);
    randomx_init_cache(cache, &lastseed, 32);
    is_cache_init = true;
    if (this->debug)
        LogPrintf("%s complete\n", __func__);
}

void rxhash::cacherebuild()
{
    cache = randomx_alloc_cache(flags);
    randomx_init_cache(cache, &currentseed, 32);
    if (this->debug)
        LogPrintf("%s complete\n", __func__);
}

void rxhash::vminit()
{
    if (vm)
        randomx_destroy_vm(vm);
    vm = randomx_create_vm(flags, cache, nullptr);
    is_vm_init = true;
    if (this->debug)
        LogPrintf("%s complete\n", __func__);
}

void rxhash::shutoff()
{
    if (vm)
        randomx_destroy_vm(vm);
    vm = nullptr;
    randomx_release_cache(cache);
    if (this->debug)
        LogPrintf("%s complete\n", __func__);
}

void rxhash::hash(const char* input, char* output, int len, int height)
{
    if (!is_cache_init)
        cacheinit();
    if (!is_vm_init)
        vminit();
    if (this->hasseedchanged()) {
        this->shutoff();
        this->cacherebuild();
        this->vminit();
    }
    randomx_calculate_hash(vm, input, len, output);
}
