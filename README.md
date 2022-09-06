# fdf - pforesti
### About 
The goal of this project is to create a "wireframe" representation of a scene. The coordinates (x, y, z) are transmitted to the program via a specifically formatted file. We then transform them to obtain what looks like an isometric projection.

![png 01](https://zupimages.net/up/22/36/gh62.png)

### Setting Up
The program can be tested on any Mac or Linux distribution with the MinilibX installed - the very basic library allowed for our first projects at 42.

* On the school's computers: there is not much to do. Run ``make`` from ``.fdf_42project/``.

* Mac OS X
  * To install the MinilibX, follow the instructions from this link : [minilibx-mac-osx](https://github.com/dannywillems/minilibx-mac-osx)
  * Then run the ``make`` command from ``.fdf_42project/``.

* Linux (Debian/Ubuntu)
  * To install the MinilibX, follow the instructions from this link : [minilibx-linux](https://github.com/42Paris/minilibx-linux)
  * After installing all the necessary libraries. Clone the repo from the previous link into ``.fdf_42project/`` , and compile it using the ``./configure`` script.
  * Then run the ``make`` command from ``.fdf_42project/``.

### Usage
Type ``./fdf`` followed by the map of your choice as a parameter.\
    **e.g.** ``./fdf maps/basictest.fdf``

* ``w, a, s, d`` keys are used to rotate the projection.
* ``j`` and ``k``allow you to zoom in or out.
* Arrow keys allow you to move around.
* ``c`` key is used to activate or deactivate the color.

### Words
I've spent too many hours on it, it's not perfect but I learned a lot. And I encourage everyone who is taking their first steps in this project not to give up, it's worth it.

 ![png 01](https://zupimages.net/up/22/36/1eiy.png)
 
![png 01](https://zupimages.net/up/22/36/gvvq.png)

Feel free to clone, explore the code, and toussa toussa.
* 42 Login:	*pforesti*
* Email:		*pforesti@student.42nice.fr*
