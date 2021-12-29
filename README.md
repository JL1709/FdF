# FDF
This repo is part of our project: On Self-Contact and Human Pose. \
[[Project Page](https://tuch.is.tue.mpg.de)] [[Paper](https://arxiv.org/pdf/2104.03176.pdf)] [[MPI Project Page](https://www.is.mpg.de/publications/mueller-cvpr-2021)]

It includes the main function to segment the SMPL and SMPL-X meshes into inside / outside / in-contact vertices.
It includes contact losses that are used with SMPLify-XMC and TUCH.

<p float="left">
<img src="images/selfcontact_teaser.png" height="300" alt="Result vertices in contact" class="center">
</p>
Vertices in contact (blue) based on geodesic and euclidean distances. In this example, the geodesic threshold is 30 cm and the euclidean threshold is 2 cm.
In red, detected self-intersecting vertices with segment tests. 


## Installation

#### 1) Clone this repository 
```
git clone git@github.com:muelea/selfcontact.git
cd selfcontact
```

#### 2) Execute Makfile
```
make
```

#### 3)  Run program
```
./fdf
```
