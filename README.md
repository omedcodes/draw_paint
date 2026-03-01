# Draw Paint 

A high performance painting application built entirely in C and SDL2. 

## Why Draw Paint?
I built this project because I wanted to understand how software actually works "under the hood." Instead of using a heavy engine, I wanted to access the hardware directly using C. 

Draw Paint is about the joy of putting pixels on a screen with code that I wrote from scratch just pure logic and a C23 compiler. I am also a huge fan of distributing my code with others a.k.a *Open source.*

## Features
* **Pixel Circles:** Custom coded drawing algorithm optimized for performance.
* **Color Palette:** Quick access colors at the top of your screen.
* **Portable:** Compiles into a single, standalone executable for Windows.

![App Showcase](./screenshots/showcase.png)
![Drawing Landscape](./screenshots/landscape_example.png)

## How to Use
The interface is designed to stay out of your way so you can just focus on creating.

| Action | Control |
| :--- | :--- |
| **Draw** | Left Mouse Button |
| **Change Brush Size** | Mouse Wheel |
| **Change Color** | Click a color in the top palette |
| **Save Image** | Press `S` (Saves as `painting.bmp`) *adding soon .png and .jpg support*|
| **Clear Canvas** | Press `C` |

---

## Build Instructions
This project uses a custom `Makefile` to handle the heavy lifting. You will need **MinGW-w64** and the **SDL2 development libraries** installed on your system.

### Prerequisites
* **Windows:** Install [MinGW-w64](https://www.mingw-w64.org/) and [SDL2](https://www.libsdl.org/).
* **Linux/macOS:** Install GCC and SDL2 via your package manager (`sudo apt install libsdl2-dev`).

### 1. Development (Debug Mode)
Builds with extra info for debugging and keeps the console window open.
* **Windows:** `mingw32-make debug`
* **Linux/macOS:** `make debug`

### 2. Distribution (Release Mode - Recommended)
Optimizes the code for speed and hides the console window.
* **Windows:** `mingw32-make release`
* **Linux/macOS:** `make release`

## Extras

### License
This project is licensed under the **MIT License**. This means you are free to use, modify, and distribute the code however you like, as long as you provide credit. See the [LICENSE](./LICENSE) file for details.

### Credits
* **SDL2 Team:** For the amazing cross platform library that makes hardware access possible.
* **The C Community:** For keeping the most powerful language in the world alive for over 50 years.
* **You:** For checking out my project! If you like it feel free to give it a ⭐ on GitHub.