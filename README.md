# FdF - 42 Project

## 🚀 Project Overview

**FdF** is a graphical project aimed at creating a 3D image from a map of co-ordinates. The project is written using **C** and **MinilibX**.

This project explores key graphics and math concepts. The bonus part of the project involves implementing a **spherical projection** for the map, allowing for dynamic rotation and interaction.

---

## 💡 Key Features & Controls

The program includes multiple features to enhance user interaction and visualization. These features provide users the ability to manipulate the display and view the data from various perspectives.

### 📊 Image Navigation
- **`+`** / **`-`**: Switch between different maps. 
- **`c`**: Change color scheme.
- **`g`**: Switches to/from **globe mode**, a spherical projection.
- **`p`**: Initiates **pong mode**, where the image will bounce around the screen.
- **`b`**: Enables **banner mode**, where a banner will rotate around the object in the visualization.

### 🖱️ Mouse Controls
- **Mouse click and drag**: Rotate the map for a dynamic 3D visualization.
- **Mouse wheel**: Zoom in and out of the map.

---

## 🧑‍🔧 Compilation & Setup

To compile and set up the project, follow these steps:

### 1. Clone the repository

```bash
git clone https://github.com/mooresamuel/fdf.git
cd fdf
```


### 2. Compile the project
To compile the project and generate the push_swap executable, run:
```bash
make
```
This will create the push_swap executable and install the required X11 libraries if not available on the system.

### 3. Clean up
To remove the object files:
```bash
make clean
```

To remove all compiled files, including the push_swap executable:
```bash
make fclean
```

To recompile everything from scratch:
```bash
make re
```

## 🧪 Example Usage
To use the fdf program, simply run it from the command line.

```bash
./fdf
```
This will open the graphical window with the 3D visualization of the height map.

## 📄 License
This project is licensed under the MIT License - see the LICENSE file for details.

## 🤝 Collaboration
Feel free to contribute to this project! Fork it, submit issues, or open a pull request. If you have suggestions or feedback, don’t hesitate to reach out.

Happy coding! 🚀
