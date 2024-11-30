# FdF - 42 Project

## 🚀 Project Overview

**FdF** is a graphical project aimed at visualizing a 3D map of a height map using **C** and **MinilibX**. The goal is to create a program that reads a text file with 2D data, processes it, and projects it in 3D using various transformations.

This project explores key graphics and math concepts, such as **projections**, **isometric views**, and **color gradients**. The bonus part of the project involves implementing a **spherical projection** for the map, allowing for dynamic rotation and interaction.

---

## 💡 Key Features & Controls

The program includes multiple features to enhance user interaction and visualization. These features provide users the ability to manipulate the display and view the data from various perspectives.

### 📊 Image Navigation
- **`+`** / **`-`**: Switch between different images. 
- **`c`**: Switch color scheme.
- **`p`**: Initiates **pong mode**, where the image will bounce around the screen.
- **`b`**: Enables **banner mode**, where a banner will rotate around the object in the visualization.

### 🖱️ Mouse Controls
- **Mouse click and drag**: Rotate the map for a dynamic 3D visualization.
- **Mouse wheel**: Zoom in and out of the map.

---

## 🧑‍💻 Algorithm & Approach

The project uses a **spherical projection** for the bonus, which is designed to represent the height map in a spherical coordinate system. The goal is to display a 3D representation of the height data in an interactive environment. 

The core principles of the project are:
- **Isometric Projection**: Used for generating the 3D effect based on a 2D height map.
- **Spherical Projection (Bonus)**: A transformation that adapts the 3D coordinates into a spherical form, enabling the map to rotate as if it's wrapped around a sphere.
- **Color Scheme Manipulation**: Allows the user to switch color schemes for better visual distinction.

### 🎮 Bonus Feature: Spherical Projection

For the bonus, a **spherical projection** is implemented. This projection allows the user to view the map as if it is wrapped around a sphere, adding a dynamic and interactive element to the visualization.

- In **pong mode**, the map image will "bounce" on the screen.
- In **banner mode**, a banner rotates around the sphere, adding another layer of interactivity.

---

## 🔧 Files

- **`fdf.c`**: Main source file containing the setup and initialization of the project.
- **`map_utils.c`**: Helper functions for processing the map data and handling transformations.
- **`draw.c`**: The drawing functions that render the 3D map on the screen.
- **`color.c`**: Functions for managing color schemes and dynamic changes.
- **`bonus.c`**: Contains the implementation of the bonus feature - spherical projection, pong mode, and banner mode.
- **`Makefile`**: Automates the build process, compiling all the necessary files.

---

## 🧑‍🔧 Compilation & Setup

To compile and set up the project, follow these steps:

### 1. Clone the repository

```bash
git clone https://github.com/mooresamuel/fdf.git
cd fdf
```

