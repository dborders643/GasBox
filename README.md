# 2D Particle Simulation: Entropy & Deterministic Trajectories

A 2D physics simulation built in C++ to model statistical mechanics (entropy over time) vs. deterministic particle kinetics. Particles are initialized on one side of a divided box with an opening in the wall, allowing real-time tracking of macrostate equilibrium alongside individual microstate trajectories.

---

## 1. Core Concepts & Objectives

* **Physics Modeling:**
  * **Microstate Analysis:** Deterministic kinematic tracking of individual particles ($x, y, v_x, v_y$).
  * **Macrostate Analysis:** Particle count distribution between chambers.
  * **Entropy Calculation:** Spatial binning using Shannon/Boltzmann entropy ($S = -\sum p_i \ln p_i$).
* **Software Architecture:**
  * Clean modern C++ structure without manual raw pointer management.
  * Decoupled physics calculation loop and rendering pipeline.

---

## 2. C++ Prerequisite Reading Checklist (LearnCpp.com)

Before starting each phase of development, ensure the following concepts are understood from the tutorial chapters:

### Phase 1: Engine Logic & Physics Basics
* [ ] **Chapter 1 & 2:** Basics, Functions, and Files
* [ ] **Chapter 4:** Fundamental Data Types (floating-point precision, `double`)
* [ ] **Chapter 6:** Scope, Duration, and Linkage
* [ ] **Chapter 8:** Control Flow (loops, conditional branching for wall collisions)
* [ ] **Chapter 12:** Pointers and References (specifically **Pass-by-Reference `&`** to avoid copying particle data during frame updates)
* [ ] **Chapter 13:** Compound Types (**Structs** for storing particle attributes)

### Phase 2: Dynamic Data & Object-Oriented Architecture
* [ ] **Chapter 14:** Introduction to Classes (encapsulating simulation bounds, particle pools, and wall parameters)
* [ ] **Chapter 16:** Dynamic Arrays & Vectors (**`std::vector`** for managing variable amounts of particles dynamically)

### Phase 3: Graphics Integration
* [ ] Basic knowledge of CMake and third-party library linking via `vcpkg`.
* [ ] Reading external documentation for OpenGL context creation (GLFW/GLAD) and ImGui rendering.

---

## 3. Toolchain & Dependencies

* **Language Standard:** Modern C++ (C++17 or later)
* **Compiler:** GCC, Clang, or MSVC
* **Build System:** CMake (v3.20+)
* **Package Manager:** vcpkg
* **Libraries (To be integrated later):**
  * **GLFW** — Window management and event handling
  * **GLAD** — OpenGL loader
  * **Dear ImGui + ImPlot** — Real-time telemetry dashboard and live graphs

---

## 4. Development Roadmap

- [ ] **Milestone 1: Terminal Prototype**
  - Implement `Particle` struct and `Box` bounds logic.
  - Write fixed-timestep physics updates and outer boundary bounces.
  - Implement center wall with a configurable aperture size.
  - Output particle counts per chamber to stdout / CSV.

- [ ] **Milestone 2: CMake & Toolchain Setup**
  - Create `CMakeLists.txt` and integrate `vcpkg`.
  - Configure GLFW and GLAD dependencies.

- [ ] **Milestone 3: Graphics Pipeline Integration**
  - Initialize window context and rendering loop.
  - Render particles on screen inside the container boundaries.

- [ ] **Milestone 4: Telemetry & Live Plotting**
  - Add Dear ImGui & ImPlot UI overlays.
  - Plot real-time system entropy vs. time.
  - Enable individual particle selection/highlighting for trajectory comparison.