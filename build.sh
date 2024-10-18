#!/bin/sh

# Clean previous build artifacts
echo "Cleaning up..."
rm -f lib/liblogic.so *.o

# Ensure the lib directory exists
mkdir -p lib

# Compiler and linker flags
CFLAGS="-O2 -Wall -Wextra --std=c2x -g"
LIB="./lib"
SRC="./src"
FILES="
  ./src/logic.c 
  ./src/player.c
"

# Build shared library
# -fPIC (Position Independent Code) is required for shared libraries.
echo "Building shared library liblogic.so..."
gcc $CFLAGS -shared -o $LIB/liblogic.so -fPIC $FILES || exit 1

# Build the game executable
echo "Building game executable..."
gcc $CFLAGS $SRC/main.c $SRC/logic_loader.c -o game -L$LIB -lraylib -llogic -Wl,-rpath=$LIB || exit 1

echo "Build completed successfully."
