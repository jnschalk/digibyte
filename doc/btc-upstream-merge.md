Bitcoin Upstream Merge Guide
====================================
DigiByte was originally forked from the Bitcoin & Litecoin UTXO codebase. Since 2014 many unique changes have been made to DGB that separate it from the latest BTC codebase. However, there is a tremendous amount of improvements continually being made by talented open-source blockchain developers from around the world to the Bitcoin codebase that DigiByte can quite often benefit from.

Therefore it is important for us to routinely take a look at how some of these improvements can be integrated into the DigiByte codebase in a safe, auditable, reviewable manner. This document is an attempt to document how to best take advantage of those code improvements from Bitcoin with a clearly defined process the community can follow. 

An upstream merge from Bitcoin to DigiByte can be a very complex undertaking for any one person to do alone. There have been several major merge events in DigiBytes history and in the past mistakes have been made during many of these upstream merge events and bugs inadvertently introduced into code. By following the process below many of these issues can be avoided, and the community united in the development process.

3 Approaches To Upstream BTC Merges
------------------------------------
There are roughly 3 different ways to keep DigiByte core up to date with the latest improvements and enhancements to Bitcoin core.

1. Cherry Pick Relelvent commits every 2-4 weeks. By setting a specific day each month, devs can come together and cherry-pick relevant commits that can benefit DGB. If this is done routinely it can prevent mass merge events that are needed after upstream merges are not done for several years.

2. The Bitcoin Rebase. A simple rebase of DGB specific changes onto a fresh Bitcoin clone. While this approach may have worked several years ago that is no longer the case and not recommended. There is a possibility of missing and breaking 100s of things and the only way to verify a release and commit is not breaking unknown and unseen parts of the code is to do a detailed diff comparison between the current stable DGB release and the new rebase, which pretty well leaves you at the third option anyways.

3. The complete Bitcoin/ DigiByte merge. This becomes necessary when routine cherry-pick updates have not been done for some time. This requires an all-hands-on-deck effort and a detailed process that is outlined below. However, this is necessary to provide a clear documented review process for all changes, merge conflicts, and issues that arise. So anyone can publicly verify all changes and the public at large has clear visibility into developer actions. 
Part 1: Pre-Merge Setup (Managed from Source Tree GUI to save time) 
------------------------------------------------------------------------------

1. Completely build latest Bitcoin Core from source all the way to deployment to ensure you have the proper build environment configured. Follow latest BTC dev build environment changes & thoroughly read release notes.

        git clone https://github.com/bitcoin/bitcoin.git
        cd bitcoin
	./autogen.sh
	./configure 
	make

2.  Make Clean directory & make sure no build files are present in clean directory.

        make clean

3.  Rename any text string containing: "BTC", "btc," "Bitcoin," "BITCOIN," "bitcoin" w "DGB," "dgb," "DigiByte," "DIGIBYTE," "digibyte" through out entire codebase with case sensitivity.
    Easily done with find & replace inside visual studio code. Should be about 20,0000 changes or more. Save all and make sure case sensitivity is on.

4. Commit all name changes and save in 1 commit for reference.

5. Rename all filenames including the text "bitcoin" to "digibyte."
	Easily done with finder on Mac. Open folder, use option + over arrow button, then command A to select all. Do this 10 times to open all folders and select all files in entire code base. Then rename and replace all files containing bitcoin -> digibyte.


6. Commit all file name changes and save in 1 commit for future reference.


7. Test compile core wallet from scratch with all name changes.


8. Make Clean directory & make sure no build files are present in clean directory. Will use this branch to merge into current stable DGB release.



Part 2: The Merge & Merge Conflicts Resolution (The Fun Part)
----------------------------------------------------------------

1.  Select Current DigiByte version as default branch, merge the renamed bitcoin branch you just worked on into DGB core. Will be many merge conflicts to go through. This is where its of utmost importance to take your time and go line by line and know what you are changing. Very easy to make a mistake here. Here will be the trouble areas to watch out for.

        git clone https://github.com/digibyte/digibyte
        cd digibyte

2.  Document & note every merge conflict of importance for future reference to look back on what has changed. Useful to learn updates, refactoring and important changes that can be used to identify bugs when compiling or later on.

Notes: 

fSupportsSegwit removed

MSG_BLOCK
MSG_DANDELION_TX

        ./autogen.sh
        ./configure
        make


	* Anything to do with MultiAlgo
	* Ports, Testnet configs, Genesis block info
	* Protocol Versoning
	* DGB Custom QT GUI Files
	* Private key prefixes (make sure old & new version accepted)
	* DGB address specific prefixes, Bech 32 etc
	* DGB previous hard fork block heights
	* DGB seeds
	* Logos, Icons, and media files, css files.
	* Copyrights (Make sure Bitcoin devs still get all credit they deserve)

