## PGP keys of builders and Developers

The file `keys.txt` contains fingerprints of the public keys of builders and
active developers.

The associated keys are mainly used to sign git commits or the build results
of Guix builds.

The most recent version of each pgp key can be found on most pgp key servers.

Fetch the latest version from the key server to see if any key was revoked in
the meantime.
To fetch the latest version of all pgp keys in your gpg homedir,

```sh
gpg --refresh-keys
```

To fetch keys of builders and active developers, feed the list of fingerprints
of the primary keys into gpg:

```sh
while read fingerprint keyholder_name; do gpg --keyserver hkp://subset.pool.sks-keyservers.net --recv-keys ${fingerprint}; done < ./keys.txt
```

<<<<<<< HEAD:contrib/gitian-keys/README.md
Add your key to the list if you provided Gitian signatures for two major or
=======
Add your key to the list if you provided Guix attestations for two major or
>>>>>>> bitcoin/8.22.0:contrib/builder-keys/README.md
minor releases of DigiByte Core.
