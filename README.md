# Terminal-Saver

This is a terminal screensaver application that displays animated sprites in the terminal window. It is designed to run in a linux terminal environment and provides a fun and visually appealing way to keep your terminal active.

# Installation

```bash
   make
   sudo make install
```

# Usage

```bash
   terminal-saver [path_to_sprites_file]
```

If you want to provide your own sprite file, you can specify the path as an argument. Then you also need to provide the number of sprites and the maximum length of each sprite as additional arguments:

```bash
   terminal-saver <path_to_sprites_file> <number_of_sprites> <sprite_length>
```


Otherwise, it will use the default sprite file located at `/usr/share/terminal-saver/sprites.dat`.

