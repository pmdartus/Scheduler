# Advanced Operating System course

[Information](http://perso.citi-lab.fr/kmarquet/4if-GRP.html)

## GDB and Rasberry Pi Emulator

Checkout the gdb directory

## INSA workflow

First connect to INSA in ssh:
```
ssh [user]@iftpservev2.fr
```

And then make it pop! All the drivers for Rasberry Pi is installed, so you just need to `git clone git@github.com:pmdartus/Scheduler.git` the repo and follow the commands.

> Bonus SWAG

> Use transmit in sftp to open your files in Sublime and automatically push back to the server when saving! ;)

## Simple collaborative scheduler

Checkout `ordonnanceemnt_collaboratif` directory

###Commands

```
make : Compile
make clean : Delete useless files
./debug/run-qemu.sh : Launch the rasberry_PI emulator
./debug/debug.sh : Launch rasberry_PI gdb version
```
