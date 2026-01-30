*This project has been created as part of the 42 curriculum by nmagamad and abtouait*

cub3D
Description
cub3D is a project inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever developed. The goal of this project is to explore the Raycasting technique, a rendering method used to create a 3D perspective from a 2D map.

This program parses a .cub file (containing map layout and texture paths) and renders a dynamic view inside the maze using the MiniLibX library. It handles wall collisions, texture mapping, and player movement, providing a fluid first-person exploration experience.

Instructions
Compilation
To compile the project, run the following command at the root of the repository:

```Bash
make
```
Execution
To launch the game, provide a valid map file as an argument:

```Bash
./cub3D maps/map.cub
```

References
```REF
https://lodev.org/cgtutor/raycasting.html
https://ismailassil.medium.com/ray-casting-c-8bfae2c2fc13
https://github.com/vinibiavatti1/RayCastingTutorial/wiki
https://youtu.be/NbSee-XM7WA?si=9uH_b05-ALYKrEw6
https://harm-smits.github.io/42docs/libs/minilibx
```

MiniLibX Documentation: Official 42 docs and community guides for handling images and window management.