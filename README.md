# OpenDanceCPP

## Setup
Repository clonen: <br>
```bash
git clone https://github.com/DanceGameStudio/OpenDance.git
```
CUDA installieren:
```bash
cd tools
cuda_11.1.1_win10_network.exe
```
KI-Modelle herunterladen und 3rdparty Libs entpacken:<br>
```bash
cd tools
setup_dev_env_win64.bat
```
Buildprozess:<br>
```bash
mkdir build
cd build
cmake ..
cmake --build . --config <Release/Debug>
```

