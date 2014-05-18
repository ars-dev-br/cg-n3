# Computer Graphics -- N3

This is a college assignment for Computer Graphics.  It's a simple drawing
application in which the user can draw some simple polygons and apply linear
transforms to them.

It uses OpenGL 1, so it should run on any PC.

## Dependencies

This project uses OpenGL, GLU and GLUT.

Documentation depends on Doxygen and LaTeX (for PDF doc only).

## Build instructions

This project uses a simple Makefile.  You can:

* `make`: compiles the project;
* `make clean`: removes compilation files;
* `make cleandoc`: removes documentation files and;
* `make doc`: generates documentation using Doxygen.

## Keyboard commands

This application is mostly keyboard driven.  Here are the valid commands:

* `A`: Enters addition mode.
* `C`: Changes current polygon color (picks a random color).
* `E`: Enters edition mode.
* `+`, `=`: Zooms In.
* `-`: Zooms Out.
* `Space bar`: Alternates between open or closed polygon.

In addition to the global keyboard commands, the application has two modes.
They have unique keybindings, documented below.

### Addition mode

* `LMB`: Adds a new point to the current polygon.  If no polygon is active,
  creates a new one.
* `RMB`: Finishes the current polygon.

### Edition mode

* `LMB`: Selects a polygon (and possibly one of its points).
* `RMB`: If a point is selected, saves its current position.

* `D`: If a point is selected, deletes it.
* `R`: Starts applying rotation transform (use the arrow keys to control).
* `S`: Starts applying scale transform (use the arrow keys to control).
* `T`: Starts applying translation transform (use the arrow keys to control).
* `Backspace`: Deletes selected polygon.
* `Esc`: Cancels selection.
* `Home`: Resets a polygon transform.

# Lessons learned

Having a `render` method on `ars::Object` and on `ars::World` was probably a bad
idea.  It “stains” two classes with OpenGL details instead of containing it on a
single `renderer` object.

It may be not so apparent because this is a simple project, but if we had more
object types and were to replace OpenGL immediate mode with modern OpenGL,
DirectX or any other graphical tool, it would become a problem.
