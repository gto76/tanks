TANKS!
======

Two player game.

![Alt text](/doc/tanks-screenshot.png?raw=true "Screenshot of the game")

Written in C. Needs Allegro library to compile. You can get it with:
```
sudo apt-get install liballegro4-dev
```

Made this one long time ago. The source of the final version got lost, that's why I added the compiled windows binary to the project. It works in DOSBox. In DOSBox use ctrl F11/F12 to slow down/speed up the emulation.

### How to compile and run:
```bash
sudo apt-get install libglib2.0-dev
sudo apt-get install liballegro4-dev
git clone https://github.com/gto76/tanks.git
cd tanks
make
./Tanks!
```
### How to run compiled (final) version:
```bash
sudo apt-get install dosbox
cd
git clone https://github.com/gto76/tanks.git
cd tanks
unzip Tanks!.zip
echo "mount t ~/tanks/Tanks!" >> ~/.dosbox/dosbox*.conf
dosbox -fullscreen -c "t:" -c "tanks!"
```

