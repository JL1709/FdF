# FdF
This repo provides the interactive program "fdf" that creates a simplified 3D graphic “wireframe” (“fils de fer”) representation of a relief landscape using isometric projection linking various points (x, y, z) via segments. The coordinates of this landscape are stored in a file passed as a parameter to the program.  

![DEMO](demo.png)

Tested on macOS Monterey.

## Installation

#### 1) Clone this repository 
```
git clone git@github.com:JL1709/FdF.git
```

#### 2) Execute Makfile
```
cd FdF
make
```

#### 3)  Run program, for example:
```
./fdf maps/42.fdf
```
