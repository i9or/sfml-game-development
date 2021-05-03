# SFML Game Development

Source code written while reading "SFML Game Development by Example" book by Raimondas Pupius.

## Setup

### Ubuntu

Install dependencies:

```sh
sudo apt-get install libx11-dev libegl1-mesa-dev libudev-dev libopenal-dev libvorbis-dev libflac-dev libxrandr-dev libfreetype-dev xorg-dev
```

Clone repository:

```sh
git clone --recursive https://github.com/i9or/sfml-game-development.git
```

Code itself was written and tested in Qt Creator under Ubuntu, however it should be possible to use CMake from command line here:

```sh
cd ./sfml-game-development
mkdir build
cd ./build
cmake ..
cmake --build .
```

Run appropriate executable in the `bin` folder.
