# So_Long-42
A Simple 2D adventure game where you navigate through a maze-like world, collecting coins and searching for the exit. Built with MiniLibX, this project showcases clean game development practices with a focus on effective resource management and engaging gameplay.

## 🎮 Game Overview

Navigate your character through a grid-based world where every move counts! Your mission is to:
- Collect all coins scattered throughout the level
- Find and reach the exit
- Avoid walls and obstacles
- Complete the level in as few moves as possible

## ✨ Key Features

### Mandatory
- Smooth, responsive controls using WASD or arrow keys
- Dynamic coin collection system
- Victory tracking and move counter
- Intelligent map validation and pathfinding
- Clean, pixel-perfect graphics
- Robust error handling and memory management

### Bonus Features
- Enemy patrols (T) that end the game on contact
- Enhanced graphics and animations
- Additional game mechanics

## 🚀 Getting Started

### Prerequisites

- MiniLibX library
- X11 (for Linux systems)
- GCC compiler
- Make

### Installation

1. Clone the repository:
```bash
git clone [repository-url]
cd so_long
```

2. Compile the game:
```bash
make        # For mandatory part
make bonus  # For bonus features
```

### Running the Game

Launch with any valid map file:
```bash
./so_long maps/level1.ber         # Mandatory version
./so_long_bonus maps/level1.ber   # Bonus version
```

## 🕹️ Controls

| Key | Action |
|-----|--------|
| W / ↑ | Move up |
| A / ← | Move left |
| S / ↓ | Move down |
| D / → | Move right |
| ESC | Quit game |

## 🗺️ Map Creation

Create your own levels using these tile types:

| Tile | Description |
|------|-------------|
| 1 | Wall |
| 0 | Empty space |
| C | Collectible coin |
| P | Player starting position |
| E | Exit |
| T | Enemy (Bonus version only) |

### Map Requirements

- Must be rectangular
- Fully enclosed by walls (1)
- Contains exactly one player (P)
- Contains exactly one exit (E)
- Contains at least one collectible (C)
- Must have a valid path to all coins and exit
- Can include enemies (T) in bonus version

Example map:
```
111111
1P0C01
10T001
1E0C11
111111
```

## 🏗️ Project Structure

### Mandatory Version (`/src`)
```
src/
├── check_map.c          # Map validation functions
├── check_map_helper.c   # Helper functions for map validation
├── close_game.c         # Game termination handling
├── free.c              # Memory management
├── game.c              # Core game logic
├── handle_input.c      # Input processing
├── map.c               # Map loading and processing
├── print_moves.c       # Move counter display
├── render.c            # Graphics rendering
├── so_long.c           # Main program entry
├── so_long.h           # Header definitions
└── valid_path.c        # Path validation
```

### Bonus Version (`/bonus`)
```
bonus/
├── check_map_bonus.c          # Enhanced map validation
├── check_map_helper_bonus.c   # Additional validation helpers
├── close_game_bonus.c         # Enhanced game termination
├── free_bonus.c              # Memory management
├── game_bonus.c              # Enhanced game logic with enemies
├── handle_input_bonus.c       # Extended input handling
├── map_bonus.c               # Advanced map processing
├── print_moves_bonus.c        # Enhanced move display
├── render_bonus.c            # Advanced graphics rendering
├── so_long_bonus.c           # Bonus version entry
├── so_long_bonus.h           # Extended header definitions
└── valid_path_bonus.c        # Enhanced path validation
```

## 🐛 Error Handling

The game performs extensive validation and will display helpful error messages for:
- Invalid map files or formats
- Memory allocation failures
- Unreachable coins or exits
- Invalid game states
- Invalid enemy placement (bonus version)

## 📚 Development Notes

This project demonstrates several key programming concepts:
- Dynamic memory management
- Recursive algorithms (flood fill)
- Event-driven programming
- Graphics rendering
- File I/O operations
