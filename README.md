# Nostalgia Bytes

A collection of classic C++ games from my college days. This repository will include:

- Serpente (Snake)
- Traffigo (Car Race)
- Egatho (Egg Basket)

## Structure

- `games/` - Contains the source code for each game in its own subfolder.
- `Makefile` - Build and run the games easily (Linux/macOS or with MinGW on Windows).
- `build.bat` - Batch file to build the games on Windows without Make.

## How to Use

### On Linux/macOS

1. Add your game source code into a new subfolder under `games/` (e.g., `games/snake/`).
2. Update the `Makefile` to include your new game if needed.
3. Run `make` commands to build or play the games.

**Example:**
```bash
make snake
./bin/snake
```

### On Windows

#### Option 1: Using MinGW (`mingw32-make`)
1. Install [MinGW](http://www.mingw.org/) and add it to your PATH.
2. Open a command prompt in the project directory.
3. Run:
   ```
   mingw32-make snake
   bin\snake.exe
   ```

#### Option 2: Using the provided `build.bat`
1. Double-click `build.bat` to compile all games.
2. Run the generated `.exe` files from the `bin` folder.

---

Feel free to add more games or improve the existing ones!
