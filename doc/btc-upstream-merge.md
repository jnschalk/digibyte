Bitcoin Upstream Merge Guide
====================================
DigiByte    

3 Approaches To Upstream BTC Merges
------------------------------------
There

Part 1: Pre-Merge Setup (Managed from Source Tree GUI to save time) 
------------------------------------------------------------------------------

1. Completely build latest Bitcoin Core from source all the way to deployment to ensure you have the proper build environment configured. Follow latest BTC dev build environment changes & thoroughly read release notes.

        git clone https://github.com/digibyte/digibyte
        cd digibyte

2.  Make Clean directory & make sure no build files are present in clean directory.

        ./autogen.sh
        ./configure
        make

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

