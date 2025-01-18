![Solong](https://github.com/user-attachments/assets/7b9911bd-36e6-4416-889e-b40e4e11bd7a)

```markdown
# SoLong - 2D Game

SoLong is a 2D game developed as part of the 42 school. The game was built using the **MLX 42** library, and it features both mandatory and bonus parts. The objective is to navigate a character through a map, collecting items and avoiding obstacles.

## Project Overview

This repository contains:

- **Mandatory part**: The core functionality of the game.
- **Bonus part**: Extra features such as enemies, more complex game mechanics, and improved visuals.

## Requirements

- **MLX 42 Library**: The project uses the **mlx42** library for graphical rendering. You will need to compile and install it before running the game.
- **C Compiler**: `gcc` (or another C compiler) to compile the source code.

## Setup Instructions

### 1. Compile the MLX 42 Library

Before compiling the game, you must compile the **mlx42** library. Navigate to the `mlx` directory and run the following command:

```bash
cd mlx
make
```

This will build the **mlx42** library. Once completed, return to the root of the repository:

```bash
cd ..
```

### 2. Compile the SoLong Project

You can compile either the **mandatory** or **bonus** version of the game.

- To compile the **mandatory** version:

```bash
make
```

- To compile the **bonus** version (with additional features such as enemies):

```bash
make bonus
```

### 3. Clean Up

To remove all object files and executables:

```bash
make clean
```

To remove all files (including executables and object files):

```bash
make fclean
```

### 4. Rebuild the Project

To remove all files and recompile everything from scratch:

```bash
make re
```

## Usage

After compiling, you can run the game by executing the following command:

- For the **mandatory** version:

```bash
./so_long maps/valid/map2.ber
```

- For the **bonus** version:

```bash
./so_long_bonus maps/valid/bonus/map1.ber
```

## Game Controls

The game can be controlled using the following keys:

- **Arrow Keys**: Move the character.
- **WADS**: Move the character.
- **Esc**: Exit the game.

## Project Structure

```
.
├── mlx/                    # MLX 42 library
├── mandatory/              # Mandatory part of the project
│   ├── src/                # Game logic source code
│   └── include/            # Header files
├── bonus/                  # Bonus part of the project
│   ├── src/                # Bonus features source code
│   └── include/            # Bonus header files
├── Makefile                # Makefile for compiling the project
└── README.md               # This file
```

### Key Source Files

- **mandatory/src/main.c**: Entry point of the game.
- **mandatory/src/graphic/render.c**: Handles rendering of the game graphics.
- **bonus/src/graphic/enemy/ft_enemy_ia_bonus.c**: Enemy AI for the bonus version.

## Thanks 
```
