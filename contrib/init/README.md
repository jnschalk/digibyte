Sample configuration files for:
```
<<<<<<< HEAD
SystemD: digibyted.service
=======
systemd: digibyted.service
>>>>>>> bitcoin/8.22.0
Upstart: digibyted.conf
OpenRC:  digibyted.openrc
         digibyted.openrcconf
CentOS:  digibyted.init
<<<<<<< HEAD
macOS:    org.digibyte.digibyted.plist
=======
macOS:   org.digibyte.digibyted.plist
>>>>>>> bitcoin/8.22.0
```
have been made available to assist packagers in creating node packages here.

See [doc/init.md](../../doc/init.md) for more information.
