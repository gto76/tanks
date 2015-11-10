TANKS!
======

Two player game…

![Alt text](/doc/tanks-screenshot.png?raw=true "Screenshot of the game")

Made this one long time ago. The source of the final version got lost, that's why I added the compiled Windows binary to the project. It works in _DOSBox_. Use ctrl F11/F12 to slow down/speed up the emulation.

How to run compiled (final) version on…
---------------------------------------

### Windows
1. Download and install [DOSBox](http://sourceforge.net/projects/dosbox/files/latest/download?accel_key=56%3A1425822250%3Ahttp%253A//www.dosbox.com/download.php%253Fmain%253D1%3Ad55255fd%24a12400df8eebd87c25f5ab461bc8f735bfa63f2a&click_id=32fbcef4-c599-11e4-b7db-0200ac1d1d8b&source=accel)
2. Download and extract [the game](https://github.com/gto76/tanks/archive/master.zip)
3. Double click run.bat

### UNIX
```bash
sudo apt-get install dosbox
git clone https://github.com/gto76/tanks.git
cd tanks
echo "mount t $PWD/bin" >> ~/.dosbox/dosbox*.conf
dosbox -fullscreen -c "t:" -c "tanks!"
```

How to compile and run unfinished version
-----------------------------------------
```bash
sudo apt-get install libglib2.0-dev
sudo apt-get install liballegro4-dev
git clone https://github.com/gto76/tanks.git
cd tanks
make
./tanks
```
