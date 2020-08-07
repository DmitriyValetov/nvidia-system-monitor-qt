# nvidia-system-monitor
<div style="text-align: center;">
    <img src="icon.png" alt="icon" width="256" height="256"/>
</div>

Task Manager for Linux for Nvidia graphics cards

## Dependencies
Qt 5.11+ is required for work.
* If you are an ArchLinux user, you can install from [here](https://wiki.archlinux.org/index.php/qt#Installation).
* If you are Ubuntu user, it can be installed with `sudo apt install qtdeclarative5-dev`.

Also in the system must be available `nvidia-smi`

## Building
### ArchLinux
You can install `nvidia-system-monitor-qt` directly from [AUR](https://aur.archlinux.org/packages/nvidia-system-monitor-qt/)
<br>To launch enter `qnvsm` or just click on `.desktop` file

#### From source
The only difference from **Other** commands is that it will try to load the icon located in 
`/usr/share/icons/hicolor/512x512/apps/nvidia-system-monitor-qt.png`

```bash
mkdir build
cmake -DCMAKE_BUILD_TYPE=Release -B build -DDistributive=Arch -G "Unix Makefiles"
cmake --build build --target qnvsm -- -j 2
```

### Other
```bash
cmake -DCMAKE_BUILD_TYPE=Release -G "Unix Makefiles" -B cmake-build-release
cd cmake-build-release
make -j4
```
To launch type `cmake-build-release/qnvsm`

The option -j describes the number of parallel processes for the build. In this case make will try to use 4 cores for the build.

If you want to use an IDE for Linux you can try CLion or QtCreator.

## Config
Here example of simple config located in `~/.config/nvidia-system-monitor/config`:
```
# time in ms
updateDelay 500
graphLength 120000

#           gpu id  red  green  blue
gpuColor    0       0    0      255
gpuColor    1       0    255    0
gpuColor    2       255  0      0
```

## Screenshots
[Open SCREENSHOTS.md](SCREENSHOTS.md)

## Donate
<b>Payeer:</b> P36281059

Or you can do it even without finance. Just open [this](http://fainbory.com/8aWY) link

Thank you.
