# Traffic Signal In The City 🚦

A 2D OpenGL C++ graphics project featuring an animated traffic signal system controlling vehicle movement at a city intersection.

## 📸 Project Overview

This project simulates a city scene with:
- **Traffic Control System** - Two traffic lights (horizontal & vertical roads)
- **Road Network** - Cross-intersection with footpaths and zebra crossings
- **Vehicles** - 4 static cars positioned at intersection
- **Buildings** - 2 shops and 2 houses with detailed architecture
- **Environment** - 7 trees, river with boats, fence
- **Static Scene** - Clean, optimized rendering (no animation)

## ✨ Features

### Traffic Lights
- **Red Signal** - Stops traffic on that road
- **Green Signal** - Allows traffic movement
- **Toggle Control** - Switch between signal states

### Road Elements
- Horizontal & vertical road intersection
- Zebra crossings at 4 locations
- Road markings and dividers
- Footpaths on both sides

### Architecture
- BFC Shop (left) - White building with cyan doors/windows
- Candy Shop (right) - Orange building with products display
- Blue House (left) - Modern design with multiple windows
- Brown House (right) - Storage room on top floor

### Environment
- **7 Trees** - Mix of circular and triangular designs
- **River** - Static river with wave pattern
- **Boats** - 2 boats in the river
- **Fence** - Protective fence with vertical posts

## 🛠️ Technical Details

**Language:** C++ (Standard)  
**Graphics Library:** OpenGL + GLUT  
**Code Lines:** 608 (Optimized)  
**Window Size:** 1430×800 pixels  
**Coordinate System:** gluOrtho2D(-2, 2, -1, 1)

### Code Structure
```
1. Drawing Primitives (20 lines)
   - drawCircle()
   - drawLine()

2. Object Functions (400+ lines)
   - tree(), shop(), house()
   - road_footpath(), traffic lights
   - fence(), river(), boats()

3. Display & Input (50 lines)
   - start() - Title screen
   - day() - Main scene
   - button() - Keyboard input

4. Main & Setup (40 lines)
   - main(), inigl()
```

## ⌨️ Keyboard Controls

| Key | Function |
|-----|----------|
| **F** | Start the project |
| **R** | Red (Horizontal), Green (Vertical) |
| **G** | Green (Horizontal), Red (Vertical) |

## 📦 Installation & Compilation

### Windows (MinGW)
```bash
g++ -o traffic_signal.exe traffic_signal_static.cpp -lglut -lopengl32 -lglu32 -lm
traffic_signal.exe
```

### Linux (Ubuntu/Debian)
```bash
sudo apt-get install freeglut3-dev
g++ -o traffic_signal traffic_signal_static.cpp -lglut -lGL -lGLU -lm -std=c++11
./traffic_signal
```

### macOS
```bash
brew install freeglut
clang++ -o traffic_signal traffic_signal_static.cpp \
        -framework GLUT -framework OpenGL -lm -std=c++11
./traffic_signal
```

## 📊 Project Statistics

| Metric | Value |
|--------|-------|
| Total Lines | 608 |
| Functions | 25 |
| Global Variables | 3 |
| Trees | 7 |
| Houses | 2 |
| Shops | 2 |
| Traffic Lights | 2 |
| Static Elements | All |
| Animation | None |
| CPU Overhead | Minimal |

## 🎓 Educational Value

This project demonstrates:
- OpenGL primitive shapes (GL_POLYGON, GL_TRIANGLE_FAN, GL_LINES)
- Color management (RGB values)
- 2D transformations (glTranslate, glRotate)
- Coordinate systems and orthographic projection
- Modular code design with helper functions
- Clean code organization with comments

## 📝 Code Highlights

### Helper Functions
```cpp
void drawCircle(GLfloat cx, GLfloat cy, GLfloat r, int R, int G, int B);
void drawLine(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2, int R, int G, int B);
```

### Object Functions
```cpp
void tree();
void shop();
void house();
void road_footpath();
void traffic_light1();
void traffic_light2();
void fence();
void river();
void boats();
void day();
void start();
```

### Input Handling
```cpp
void button(unsigned char key, int x, int y);
```

## 🚀 Why This Version?

✅ **Optimized** - 57.5% smaller than original (1,431 → 608 lines)  
✅ **Static** - No animation complexity, fast rendering  
✅ **Clean** - Well-organized modular code  
✅ **Professional** - University-standard quality  
✅ **Rich** - 7 trees, multiple buildings, detailed scenes  
✅ **Fast** - Minimal CPU overhead  

## 📄 Files Included

- `traffic_signal_static.cpp` - Main source code
- `README.md` - This file
- `COMPILATION_GUIDE.txt` - Detailed setup instructions

## 🔗 Author

**Student Project**  
Graphics Programming with OpenGL & GLUT

## 📜 License

This project is free to use for educational purposes.

---

**Last Updated:** April 2026  
**Status:** ✅ Ready for Submission
