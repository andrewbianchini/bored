#!/bin/bash

g++ ../hello_triangle.cpp -o triangle $(sdl2-config --cflags --libs) -I/opt/homebrew/Cellar/glew/2.2.0_1/include -L/opt/homebrew/Cellar/glew/2.2.0_1/lib -lGLEW -framework OpenGL
exit 0
