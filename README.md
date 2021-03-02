# SFML Game Development

Source code written while reading "SFML Game Development by Example" book by Raimondas Pupius.

## Setup

### Ubuntu

Install dependencies:

```commandline
sudo apt-get install libx11-dev libegl1-mesa-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype-dev
```

Clone repository:

```commandline
git clone --recursive https://github.com/i9or/sfml-game-development.git
```

Code itself was written and tested in CLion under Linux, however it should be possible to use CMake from command line here:

```commandline
cd ./sfml-game-development
mkdir build
cd ./build
cmake ..
cmake --build .
```

Run appropriate executable in the `bin` folder.
