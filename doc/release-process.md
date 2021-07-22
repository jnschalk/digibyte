Release Process
====================

## Branch updates

<<<<<<< HEAD
* Update translations see [translation_process.md](https://github.com/digibyte/digibyte/blob/master/doc/translation_process.md#synchronising-translations).

* Update manpages, see [gen-manpages.sh](https://github.com/digibyte/digibyte/blob/master/contrib/devtools/README.md#gen-manpagessh).
=======
### Before every release candidate

* Update translations see [translation_process.md](https://github.com/digibyte/digibyte/blob/master/doc/translation_process.md#synchronising-translations).
* Update manpages, see [gen-manpages.sh](https://github.com/digibyte/digibyte/blob/master/contrib/devtools/README.md#gen-manpagessh).
* Update release candidate version in `configure.ac` (`CLIENT_VERSION_RC`).
>>>>>>> bitcoin/8.22.0

### Before every major and minor release

<<<<<<< HEAD
* Update [bips.md](bips.md) to account for changes since the last release.
* Update version in `configure.ac` (don't forget to set `CLIENT_VERSION_IS_RELEASE` to `true`)
* Write release notes (see below)
* Update `src/chainparams.cpp` nMinimumChainWork with information from the getblockchaininfo rpc.
* Update `src/chainparams.cpp` defaultAssumeValid with information from the getblockhash rpc.
  - The selected value must not be orphaned so it may be useful to set the value two blocks back from the tip.
  - Testnet should be set some tens of thousands back from the tip due to reorgs there.
  - This update should be reviewed with a reindex-chainstate with assumevalid=0 to catch any defect
     that causes rejection of blocks in the past history.

Before every major release:

* Update hardcoded [seeds](/contrib/seeds/README.md), see [this pull request](https://github.com/digibyte/digibyte/pull/7415) for an example.
* Update [`BLOCK_CHAIN_SIZE`](/src/qt/intro.cpp) to the current size plus some overhead.
* Update `src/chainparams.cpp` chainTxData with statistics about the transaction count and rate. Use the output of the RPC `getchaintxstats`, see
  [this pull request](https://github.com/digibyte/digibyte/pull/12270) for an example. Reviewers can verify the results by running `getchaintxstats <window_block_count> <window_last_block_hash>` with the `window_block_count` and `window_last_block_hash` from your output.
* Update version of `contrib/gitian-descriptors/*.yml`: usually one'd want to do this on master after branching off the release - but be sure to at least do it before a new major release

### First time / New builders

If you're using the automated script (found in [contrib/gitian-build.py](/contrib/gitian-build.py)), then at this point you should run it with the "--setup" command. Otherwise ignore this.

Check out the source code in the following directory hierarchy.

    cd /path/to/your/toplevel/build
    git clone https://github.com/digibyte-core/gitian.sigs.git
    git clone https://github.com/digibyte-core/digibyte-detached-sigs.git
    git clone https://github.com/devrandom/gitian-builder.git
    git clone https://github.com/digibyte/digibyte.git

### DigiByte maintainers/release engineers, suggestion for writing release notes

Write release notes. git shortlog helps a lot, for example:
=======
* Update [bips.md](bips.md) to account for changes since the last release (don't forget to bump the version number on the first line).
* Update version in `configure.ac` (don't forget to set `CLIENT_VERSION_RC` to `0`).
* Write release notes (see "Write the release notes" below).
>>>>>>> bitcoin/8.22.0

### Before every major release

<<<<<<< HEAD
Generate list of authors:
=======
* On both the master branch and the new release branch:
  - update `CLIENT_VERSION_MAJOR` in [`configure.ac`](../configure.ac)
  - update `CLIENT_VERSION_MAJOR`, `PACKAGE_VERSION`, and `PACKAGE_STRING` in [`build_msvc/digibyte_config.h`](/build_msvc/digibyte_config.h)
* On the new release branch in [`configure.ac`](../configure.ac) and [`build_msvc/digibyte_config.h`](/build_msvc/digibyte_config.h) (see [this commit](https://github.com/digibyte/digibyte/commit/742f7dd)):
  - set `CLIENT_VERSION_MINOR` to `0`
  - set `CLIENT_VERSION_BUILD` to `0`
  - set `CLIENT_VERSION_IS_RELEASE` to `true`

#### Before branch-off
>>>>>>> bitcoin/8.22.0

* Update hardcoded [seeds](/contrib/seeds/README.md), see [this pull request](https://github.com/digibyte/digibyte/pull/7415) for an example.
* Update [`src/chainparams.cpp`](/src/chainparams.cpp) m_assumed_blockchain_size and m_assumed_chain_state_size with the current size plus some overhead (see [this](#how-to-calculate-assumed-blockchain-and-chain-state-size) for information on how to calculate them).
* Update [`src/chainparams.cpp`](/src/chainparams.cpp) chainTxData with statistics about the transaction count and rate. Use the output of the `getchaintxstats` RPC, see
  [this pull request](https://github.com/digibyte/digibyte/pull/20263) for an example. Reviewers can verify the results by running `getchaintxstats <window_block_count> <window_final_block_hash>` with the `window_block_count` and `window_final_block_hash` from your output.
* Update `src/chainparams.cpp` nMinimumChainWork and defaultAssumeValid (and the block height comment) with information from the `getblockheader` (and `getblockhash`) RPCs.
  - The selected value must not be orphaned so it may be useful to set the value two blocks back from the tip.
  - Testnet should be set some tens of thousands back from the tip due to reorgs there.
  - This update should be reviewed with a reindex-chainstate with assumevalid=0 to catch any defect
     that causes rejection of blocks in the past history.
- Clear the release notes and move them to the wiki (see "Write the release notes" below).
- Translations on Transifex
    - Create [a new resource](https://www.transifex.com/digibyte/digibyte/content/) named after the major version with the slug `[digibyte.qt-translation-<RRR>x]`, where `RRR` is the major branch number padded with zeros. Use `src/qt/locale/digibyte_en.xlf` to create it.
    - In the project workflow settings, ensure that [Translation Memory Fill-up](https://docs.transifex.com/translation-memory/enabling-autofill) is enabled and that [Translation Memory Context Matching](https://docs.transifex.com/translation-memory/translation-memory-with-context) is disabled.
    - Update the Transifex slug in [`.tx/config`](/.tx/config) to the slug of the resource created in the first step. This identifies which resource the translations will be synchronized from.
    - Make an announcement that translators can start translating for the new version. You can use one of the [previous announcements](https://www.transifex.com/digibyte/digibyte/announcements/) as a template.
    - Change the auto-update URL for the resource to `master`, e.g. `https://raw.githubusercontent.com/digibyte/digibyte/master/src/qt/locale/digibyte_en.xlf`. (Do this only after the previous steps, to prevent an auto-update from interfering.)

#### After branch-off (on the major release branch)

- Update the versions.
- Create a pinned meta-issue for testing the release candidate (see [this issue](https://github.com/digibyte/digibyte/issues/17079) for an example) and provide a link to it in the release announcements where useful.
- Translations on Transifex
    - Change the auto-update URL for the new major version's resource away from `master` and to the branch, e.g. `https://raw.githubusercontent.com/digibyte/digibyte/<branch>/src/qt/locale/digibyte_en.xlf`. Do not forget this or it will keep tracking the translations on master instead, drifting away from the specific major release.

#### Before final release

- Merge the release notes from the wiki into the branch.
- Ensure the "Needs release note" label is removed from all relevant pull requests and issues.

#### Tagging a release (candidate)

<<<<<<< HEAD
    pushd ./digibyte
    export SIGNER="(your Gitian key, ie bluematt, sipa, etc)"
    export VERSION=(new version, e.g. 0.8.0)
    git fetch
    git checkout v${VERSION}
    popd
=======
To tag the version (or release candidate) in git, use the `make-tag.py` script from [digibyte-maintainer-tools](https://github.com/digibyte-core/digibyte-maintainer-tools). From the root of the repository run:
>>>>>>> bitcoin/8.22.0

    ../digibyte-maintainer-tools/make-tag.py v(new version, e.g. 0.20.0)

This will perform a few last-minute consistency checks in the build system files, and if they pass, create a signed tag.

## Building

### First time / New builders

Install Guix using one of the installation methods detailed in
[contrib/guix/INSTALL.md](/contrib/guix/INSTALL.md).

<<<<<<< HEAD
    pushd ./gitian-builder
    mkdir -p inputs
    wget -P inputs https://digibytecore.org/cfields/osslsigncode-Backports-to-1.7.1.patch
    wget -P inputs http://downloads.sourceforge.net/project/osslsigncode/osslsigncode/osslsigncode-1.7.1.tar.gz
    popd
=======
Check out the source code in the following directory hierarchy.
>>>>>>> bitcoin/8.22.0

    cd /path/to/your/toplevel/build
    git clone https://github.com/digibyte-core/guix.sigs.git
    git clone https://github.com/digibyte-core/digibyte-detached-sigs.git
    git clone https://github.com/digibyte/digibyte.git

### Write the release notes

Open a draft of the release notes for collaborative editing at https://github.com/digibyte-core/digibyte-devwiki/wiki.

<<<<<<< HEAD
By default, Gitian will fetch source files as needed. To cache them ahead of time, make sure you have checked out the tag you want to build in digibyte, then:

    pushd ./gitian-builder
    make -C ../digibyte/depends download SOURCES_PATH=`pwd`/cache/common
    popd
=======
For the period during which the notes are being edited on the wiki, the version on the branch should be wiped and replaced with a link to the wiki which should be used for all announcements until `-final`.

Generate the change log. As this is a huge amount of work to do manually, there is the `list-pulls` script to do a pre-sorting step based on github PR metadata. See the [documentation in the README.md](https://github.com/digibyte-core/digibyte-maintainer-tools/blob/master/README.md#list-pulls).
>>>>>>> bitcoin/8.22.0

Generate list of authors:

    git log --format='- %aN' v(current version, e.g. 0.20.0)..v(new version, e.g. 0.20.1) | sort -fiu

<<<<<<< HEAD
    pushd ./gitian-builder
    ./bin/gbuild --url digibyte=/path/to/digibyte,signature=/path/to/sigs {rest of arguments}
    popd
=======
### Setup and perform Guix builds
>>>>>>> bitcoin/8.22.0

Checkout the DigiByte Core version you'd like to build:

<<<<<<< HEAD
### Build and sign DigiByte Core for Linux, Windows, and macOS:

    pushd ./gitian-builder
    ./bin/gbuild --num-make 2 --memory 3000 --commit digibyte=v${VERSION} ../digibyte/contrib/gitian-descriptors/gitian-linux.yml
    ./bin/gsign --signer "$SIGNER" --release ${VERSION}-linux --destination ../gitian.sigs/ ../digibyte/contrib/gitian-descriptors/gitian-linux.yml
    mv build/out/digibyte-*.tar.gz build/out/src/digibyte-*.tar.gz ../

    ./bin/gbuild --num-make 2 --memory 3000 --commit digibyte=v${VERSION} ../digibyte/contrib/gitian-descriptors/gitian-win.yml
    ./bin/gsign --signer "$SIGNER" --release ${VERSION}-win-unsigned --destination ../gitian.sigs/ ../digibyte/contrib/gitian-descriptors/gitian-win.yml
    mv build/out/digibyte-*-win-unsigned.tar.gz inputs/digibyte-win-unsigned.tar.gz
    mv build/out/digibyte-*.zip build/out/digibyte-*.exe ../

    ./bin/gbuild --num-make 2 --memory 3000 --commit digibyte=v${VERSION} ../digibyte/contrib/gitian-descriptors/gitian-osx.yml
    ./bin/gsign --signer "$SIGNER" --release ${VERSION}-osx-unsigned --destination ../gitian.sigs/ ../digibyte/contrib/gitian-descriptors/gitian-osx.yml
    mv build/out/digibyte-*-osx-unsigned.tar.gz inputs/digibyte-osx-unsigned.tar.gz
    mv build/out/digibyte-*.tar.gz build/out/digibyte-*.dmg ../
    popd
=======
```sh
pushd ./digibyte
SIGNER='(your builder key, ie bluematt, sipa, etc)'
VERSION='(new version without v-prefix, e.g. 0.20.0)'
git fetch "v${VERSION}"
git checkout "v${VERSION}"
popd
```

Ensure your guix.sigs are up-to-date if you wish to `guix-verify` your builds
against other `guix-attest` signatures.

```sh
git -C ./guix.sigs pull
```

### Create the macOS SDK tarball: (first time, or when SDK version changes)
>>>>>>> bitcoin/8.22.0

Create the macOS SDK tarball, see the [macdeploy
instructions](/contrib/macdeploy/README.md#deterministic-macos-dmg-notes) for
details.

<<<<<<< HEAD
  1. source tarball (`digibyte-${VERSION}.tar.gz`)
  2. linux 32-bit and 64-bit dist tarballs (`digibyte-${VERSION}-linux[32|64].tar.gz`)
  3. windows 32-bit and 64-bit unsigned installers and dist zips (`digibyte-${VERSION}-win[32|64]-setup-unsigned.exe`, `digibyte-${VERSION}-win[32|64].zip`)
  4. macOS unsigned installer and dist tarball (`digibyte-${VERSION}-osx-unsigned.dmg`, `digibyte-${VERSION}-osx64.tar.gz`)
  5. Gitian signatures (in `gitian.sigs/${VERSION}-<linux|{win,osx}-unsigned>/(your Gitian key)/`)
=======
### Build and attest to build outputs:
>>>>>>> bitcoin/8.22.0

Follow the relevant Guix README.md sections:
- [Performing a build](/contrib/guix/README.md#performing-a-build)
- [Attesting to build outputs](/contrib/guix/README.md#attesting-to-build-outputs)

<<<<<<< HEAD
Add other gitian builders keys to your gpg keyring, and/or refresh keys: See `../digibyte/contrib/gitian-keys/README.md`.
=======
### Verify other builders' signatures to your own. (Optional)
>>>>>>> bitcoin/8.22.0

Add other builders keys to your gpg keyring, and/or refresh keys: See `../digibyte/contrib/builder-keys/README.md`.

<<<<<<< HEAD
    pushd ./gitian-builder
    ./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-linux ../digibyte/contrib/gitian-descriptors/gitian-linux.yml
    ./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-win-unsigned ../digibyte/contrib/gitian-descriptors/gitian-win.yml
    ./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-osx-unsigned ../digibyte/contrib/gitian-descriptors/gitian-osx.yml
    popd
=======
Follow the relevant Guix README.md sections:
- [Verifying build output attestations](/contrib/guix/README.md#verifying-build-output-attestations)
>>>>>>> bitcoin/8.22.0

### Next steps:

Commit your signature to guix.sigs:

```sh
pushd ./guix.sigs
git add "${VERSION}/${SIGNER}"/noncodesigned.SHA256SUMS{,.asc}
git commit -m "Add ${VERSION} unsigned sigs for ${SIGNER}"
git push  # Assuming you can push to the guix.sigs tree
popd
```

Codesigner only: Create Windows/macOS detached signatures:
- Only one person handles codesigning. Everyone else should skip to the next step.
- Only once the Windows/macOS builds each have 3 matching signatures may they be signed with their respective release keys.

Codesigner only: Sign the macOS binary:

    transfer digibyte-osx-unsigned.tar.gz to macOS for signing
    tar xf digibyte-osx-unsigned.tar.gz
    ./detached-sig-create.sh -s "Key ID"
    Enter the keychain password and authorize the signature
    Move signature-osx.tar.gz back to the guix-build host

Codesigner only: Sign the windows binaries:

    tar xf digibyte-win-unsigned.tar.gz
    ./detached-sig-create.sh -key /path/to/codesign.key
    Enter the passphrase for the key when prompted
    signature-win.tar.gz will be created

Codesigner only: Commit the detached codesign payloads:

<<<<<<< HEAD
    cd ~/digibyte-detached-sigs
    checkout the appropriate branch for this release series
    rm -rf *
    tar xf signature-osx.tar.gz
    tar xf signature-win.tar.gz
    git add -a
    git commit -m "point to ${VERSION}"
    git tag -s v${VERSION} HEAD
    git push the current branch and new tag
=======
```sh
pushd ./digibyte-detached-sigs
# checkout the appropriate branch for this release series
rm -rf ./*
tar xf signature-osx.tar.gz
tar xf signature-win.tar.gz
git add -A
git commit -m "point to ${VERSION}"
git tag -s "v${VERSION}" HEAD
git push the current branch and new tag
popd
```
>>>>>>> bitcoin/8.22.0

Non-codesigners: wait for Windows/macOS detached signatures:

- Once the Windows/macOS builds each have 3 matching signatures, they will be signed with their respective release keys.
- Detached signatures will then be committed to the [digibyte-detached-sigs](https://github.com/digibyte-core/digibyte-detached-sigs) repository, which can be combined with the unsigned apps to create signed binaries.

Create (and optionally verify) the codesigned outputs:

<<<<<<< HEAD
    pushd ./gitian-builder
    ./bin/gbuild -i --commit signature=v${VERSION} ../digibyte/contrib/gitian-descriptors/gitian-osx-signer.yml
    ./bin/gsign --signer "$SIGNER" --release ${VERSION}-osx-signed --destination ../gitian.sigs/ ../digibyte/contrib/gitian-descriptors/gitian-osx-signer.yml
    ./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-osx-signed ../digibyte/contrib/gitian-descriptors/gitian-osx-signer.yml
    mv build/out/digibyte-osx-signed.dmg ../digibyte-${VERSION}-osx.dmg
    popd
=======
- [Codesigning](/contrib/guix/README.md#codesigning)
>>>>>>> bitcoin/8.22.0

Commit your signature for the signed macOS/Windows binaries:

<<<<<<< HEAD
    pushd ./gitian-builder
    ./bin/gbuild -i --commit signature=v${VERSION} ../digibyte/contrib/gitian-descriptors/gitian-win-signer.yml
    ./bin/gsign --signer "$SIGNER" --release ${VERSION}-win-signed --destination ../gitian.sigs/ ../digibyte/contrib/gitian-descriptors/gitian-win-signer.yml
    ./bin/gverify -v -d ../gitian.sigs/ -r ${VERSION}-win-signed ../digibyte/contrib/gitian-descriptors/gitian-win-signer.yml
    mv build/out/digibyte-*win64-setup.exe ../digibyte-${VERSION}-win64-setup.exe
    mv build/out/digibyte-*win32-setup.exe ../digibyte-${VERSION}-win32-setup.exe
    popd
=======
```sh
pushd ./guix.sigs
git add "${VERSION}/${SIGNER}"/all.SHA256SUMS{,.asc}
git commit -m "Add ${SIGNER} ${VERSION} signed binaries signatures"
git push  # Assuming you can push to the guix.sigs tree
popd
```
>>>>>>> bitcoin/8.22.0

### After 3 or more people have guix-built and their results match:

Combine `all.SHA256SUMS` and `all.SHA256SUMS.asc` into a clear-signed
`SHA256SUMS.asc` message:

```sh
echo -e "-----BEGIN PGP SIGNED MESSAGE-----\nHash: SHA256\n\n$(cat all.SHA256SUMS)\n$(cat filename.txt.asc)" > SHA256SUMS.asc
```

Here's an equivalent, more readable command if you're confident that you won't
mess up whitespaces when copy-pasting:

```bash
cat << EOF > SHA256SUMS.asc
-----BEGIN PGP SIGNED MESSAGE-----
Hash: SHA256

<<<<<<< HEAD
The list of files should be:
```
digibyte-${VERSION}-aarch64-linux-gnu.tar.gz
digibyte-${VERSION}-arm-linux-gnueabihf.tar.gz
digibyte-${VERSION}-i686-pc-linux-gnu.tar.gz
digibyte-${VERSION}-x86_64-linux-gnu.tar.gz
digibyte-${VERSION}-osx64.tar.gz
digibyte-${VERSION}-osx.dmg
digibyte-${VERSION}.tar.gz
digibyte-${VERSION}-win32-setup.exe
digibyte-${VERSION}-win32.zip
digibyte-${VERSION}-win64-setup.exe
digibyte-${VERSION}-win64.zip
```
The `*-debug*` files generated by the gitian build contain debug symbols
for troubleshooting by developers. It is assumed that anyone that is interested
in debugging can run gitian to generate the files for themselves. To avoid
end-user confusion about which file to pick, as well as save storage
space *do not upload these to the digibyte.org server, nor put them in the torrent*.
=======
$(cat all.SHA256SUMS)
$(cat all.SHA256SUMS.asc)
EOF
```
>>>>>>> bitcoin/8.22.0

- Upload to the digibytecore.org server (`/var/www/bin/digibyte-core-${VERSION}`):
    1. The contents of `./digibyte/guix-build-${VERSION}/output`, except for
       `*-debug*` files.

<<<<<<< HEAD
- Upload zips and installers, as well as `SHA256SUMS.asc` from last step, to the digibyte.org server
  into `/var/www/bin/digibyte-core-${VERSION}`

- A `.torrent` will appear in the directory after a few minutes. Optionally help seed this torrent. To get the `magnet:` URI use:
```bash
transmission-show -m <torrent file>
```
Insert the magnet URI into the announcement sent to mailing lists. This permits
people without access to `digibyte.org` to download the binary distribution.
Also put it into the `optional_magnetlink:` slot in the YAML file for
digibyte.org (see below for digibyte.org update instructions).

- Update digibyte.org version

  - First, check to see if the DigiByte.io maintainers have prepared a
    release: https://github.com/digibyte-dot-org/digibyte.org/labels/Core
=======
       The `*-debug*` files generated by the guix build contain debug symbols
       for troubleshooting by developers. It is assumed that anyone that is
       interested in debugging can run guix to generate the files for
       themselves. To avoid end-user confusion about which file to pick, as well
       as save storage space *do not upload these to the digibytecore.org server,
       nor put them in the torrent*.

    2. The combined clear-signed message you just created `SHA256SUMS.asc`

- Create a torrent of the `/var/www/bin/digibyte-core-${VERSION}` directory such
  that at the top level there is only one file: the `digibyte-core-${VERSION}`
  directory containing everything else. Name the torrent
  `digibyte-${VERSION}.torrent` (note that there is no `-core-` in this name).

  Optionally help seed this torrent. To get the `magnet:` URI use:
>>>>>>> bitcoin/8.22.0

  ```sh
  transmission-show -m <torrent file>
  ```

<<<<<<< HEAD
  - If they have not prepared a release, follow the DigiByte.org release
    instructions: https://github.com/digibyte-dot-org/digibyte.org/blob/master/docs/adding-events-release-notes-and-alerts.md#release-notes
=======
  Insert the magnet URI into the announcement sent to mailing lists. This permits
  people without access to `digibytecore.org` to download the binary distribution.
  Also put it into the `optional_magnetlink:` slot in the YAML file for
  digibytecore.org.
>>>>>>> bitcoin/8.22.0

- Update other repositories and websites for new version

  - digibytecore.org blog post

  - digibytecore.org maintained versions update:
    [table](https://github.com/digibyte-core/digibytecore.org/commits/master/_includes/posts/maintenance-table.md)

  - digibytecore.org RPC documentation update

      - Install [golang](https://golang.org/doc/install)

      - Install the new DigiByte Core release

      - Run digibyted on regtest

      - Clone the [digibytecore.org repository](https://github.com/digibyte-core/digibytecore.org)

<<<<<<< HEAD
  - digibyte-dev and digibyte-core-dev mailing list

  - DigiByte Core announcements list https://digibytecore.org/en/list/announcements/join/

  - digibytecore.org blog post

  - Optionally twitter, reddit /r/DigiByte, ... but this will usually sort out itself

  - Notify BlueMatt so that he can start building [the PPAs](https://launchpad.net/~digibyte/+archive/ubuntu/digibyte)
=======
      - Run: `go run generate.go` while being in `contrib/doc-gen` folder, and with digibyte-cli in PATH

      - Add the generated files to git

  - Update packaging repo

      - Push the flatpak to flathub, e.g. https://github.com/flathub/org.digibytecore.digibyte-qt/pull/2

      - Push the latest version to master (if applicable), e.g. https://github.com/digibyte-core/packaging/pull/32

      - Create a new branch for the major release "0.xx" from master (used to build the snap package) and request the
        track (if applicable), e.g. https://forum.snapcraft.io/t/track-request-for-digibyte-core-snap/10112/7
>>>>>>> bitcoin/8.22.0

      - Notify MarcoFalke so that he can start building the snap package

<<<<<<< HEAD
  - Create a [new GitHub release](https://github.com/digibyte/digibyte/releases/new) with a link to the archived release notes.
=======
        - https://code.launchpad.net/~digibyte-core/digibyte-core-snap/+git/packaging (Click "Import Now" to fetch the branch)
        - https://code.launchpad.net/~digibyte-core/digibyte-core-snap/+git/packaging/+ref/0.xx (Click "Create snap package")
        - Name it "digibyte-core-snap-0.xx"
        - Leave owner and series as-is
        - Select architectures that are compiled via guix
        - Leave "automatically build when branch changes" unticked
        - Tick "automatically upload to store"
        - Put "digibyte-core" in the registered store package name field
        - Tick the "edge" box
        - Put "0.xx" in the track field
        - Click "create snap package"
        - Click "Request builds" for every new release on this branch (after updating the snapcraft.yml in the branch to reflect the latest guix results)
        - Promote release on https://snapcraft.io/digibyte-core/releases if it passes sanity checks

  - This repo

      - Archive the release notes for the new version to `doc/release-notes/` (branch `master` and branch of the release)

      - Create a [new GitHub release](https://github.com/digibyte/digibyte/releases/new) with a link to the archived release notes

- Announce the release:

  - digibyte-dev and digibyte-core-dev mailing list

  - DigiByte Core announcements list https://digibytecore.org/en/list/announcements/join/

  - DigiByte Core Twitter https://twitter.com/digibytecoreorg
>>>>>>> bitcoin/8.22.0

  - Celebrate

### Additional information

#### <a name="how-to-calculate-assumed-blockchain-and-chain-state-size"></a>How to calculate `m_assumed_blockchain_size` and `m_assumed_chain_state_size`

Both variables are used as a guideline for how much space the user needs on their drive in total, not just strictly for the blockchain.
Note that all values should be taken from a **fully synced** node and have an overhead of 5-10% added on top of its base value.

To calculate `m_assumed_blockchain_size`:
- For `mainnet` -> Take the size of the data directory, excluding `/regtest` and `/testnet3` directories.
- For `testnet` -> Take the size of the `/testnet3` directory.


To calculate `m_assumed_chain_state_size`:
- For `mainnet` -> Take the size of the `/chainstate` directory.
- For `testnet` -> Take the size of the `/testnet3/chainstate` directory.

Notes:
- When taking the size for `m_assumed_blockchain_size`, there's no need to exclude the `/chainstate` directory since it's a guideline value and an overhead will be added anyway.
- The expected overhead for growth may change over time, so it may not be the same value as last release; pay attention to that when changing the variables.
