# fdf - pforesti
### About 
The goal of this project is to create a "wireframe" representation of a scene. The coordinates (x, y, z) are transmitted to the program via a specifically formatted file. We then transform them to obtain what looks like an isometric projection.

![png 01](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/89a27d0f-c0c1-4cb2-9bbd-8ff942a031c6/422.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20211212%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211212T101716Z&X-Amz-Expires=86400&X-Amz-Signature=e094821d802bc2e75c529ddef3a2ff6fb9c57821e43df3b094f7cc9a6709b12e&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22422.png%22&x-id=GetObject)

### Setting Up
The program can be tested on any Mac or Linux distribution with the MinilibX installed - the very basic library allowed for our first projects at 42.

* On the school's computers: there is not much to do. Run ``make`` from ``.fdf_42project/``.

* Mac OS X
  * To install the MinilibX, follow the instructions from this link : [minilibx-mac-osx](https://github.com/dannywillems/minilibx-mac-osx)
  * Then run the ``make`` command from ``.fdf_42project/``.

* Linux (Debian/Ubuntu)
  * To install the MinilibX, follow the instructions from this link : [minilibx-mac-osx](https://github.com/dannywillems/minilibx-mac-osx)
  * After installing all the necessary libraries. Clone the repo from the previous link into ``.fdf_42project/`` , and compile it using the ``./configure`` script.
  * Then run the ``make linux`` command from ``.fdf_42project/``.

### Usage
Type ``./fdf`` followed by the map of your choice as a parameter.\
    **e.g.** ``./fdf maps/basictest.fdf``
 
 ![png 01](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/66c83393-a7db-43f2-bd86-0a58a5014dc1/basictest.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20211212%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211212T103033Z&X-Amz-Expires=86400&X-Amz-Signature=5679a5977fc9a87171072829198439e637a16626044114d261f0373f244a7685&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22basictest.png%22&x-id=GetObject)

* ``w, a, s, d`` keys are used to rotate the projection.
* ``j`` and ``k``allow you to zoom in or out.
* Arrow keys allow you to move around.
* ``c`` key is used to activate or deactivate the color.

### Words
I can't say my project is a "good" one. My color management is primitive. And my implementation of the Bresenham algorithm is not optimized at all. But I wanted to share, because I enjoyed making it. I've spent too many hours on it, but I learned a lot. And I encourage everyone who is taking their first steps in this project not to give up, it's worth it !

 ![png 01](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/9795aef1-a036-4c91-9242-a98c8236d1b6/waves.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20211212%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211212T103805Z&X-Amz-Expires=86400&X-Amz-Signature=30d446324a5d45f1d7dd5a1a031a24d314f60576bd4cc867e920c5a171755200&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22waves.png%22&x-id=GetObject)
 
![png 01](https://s3.us-west-2.amazonaws.com/secure.notion-static.com/e9a2fd6f-ecb0-4d63-812b-d33043deb8a9/oeufs1.png?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Content-Sha256=UNSIGNED-PAYLOAD&X-Amz-Credential=AKIAT73L2G45EIPT3X45%2F20211212%2Fus-west-2%2Fs3%2Faws4_request&X-Amz-Date=20211212T103836Z&X-Amz-Expires=86400&X-Amz-Signature=e18a1756e080e1e3b7d6334f0d76548c266970b2d5150dd3d07b0b3b93ca4c76&X-Amz-SignedHeaders=host&response-content-disposition=filename%20%3D%22oeufs1.png%22&x-id=GetObject)

Feel free to clone, explore the code, and toussa toussa.
* 42 Login:	*pforesti*
* Email:		*pforesti@student.42nice.fr*
