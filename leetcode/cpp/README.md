# C++ LeetCode Environment (Modern C++23)

This directory contains standalone, high-performance C++23 implementations of LeetCode problems. The workspace is built with **CMake**, tested via the **Catch2 (v2)** framework, and fully integrated with VSCode for rapid step-through debugging.

---

## Workspace Directory Structure

This setup assumes you open VSCode directly inside this directory (`cd leetcode/cpp && code .`):

```text
leetcode/cpp/
├── .vscode/
│   └── settings.json        # Maps workspace paths relative to this folder
├── build/                   # Compilation artifacts (Git-ignored)
├── .gitignore               # Ignores local build outputs
├── CMakeLists.txt           # Structural CMake project layout
├── l00001_two_sum.cpp       # Target implementation module
├── l00001_two_sum_test.cpp  # Suffix-aligned test validation suite
└── README.md                # This usage configuration guide

```

---

## Required Core Extensions

To enable linting, code parsing, automated CMake orchestration, and UI-driven debugging, install the following extensions in VSCode:

1. **C/C++ Extension Pack** (`ms-vscode.cpptools-extension-pack`)
* *Includes code intelligence (IntelliSense) and plumbing for underlying debuggers (`gdb`/`lldb`).*


2. **CMake Tools** (`ms-vscode.cmake-tools`)
* *Handles target generation, automatic background toolchain scanning, configuration caching, and workspace binaries management.*



---

## Local Pre-requisites (Linux Engine)

Ensure your host Ubuntu configuration has the standard compilation tools deployed:

```bash
sudo apt update
sudo apt install build-essential cmake gdb

```

---

## Compilation & Run Instructions

### 1. Project Initialization & Toolchain Selection

When you open this directory in VSCode via `code .`, the **CMake Tools** extension will read `CMakeLists.txt` and look at `.vscode/settings.json`.

* A prompt will drop down at the top of the window asking you to select a compiler kit.
* Select your local GNU Compiler Collection version (e.g., **`GCC /usr/bin/g++`**).

### 2. Building Targets

Look at the horizontal **VSCode Status Bar** running along the bottom edge of your IDE:

1. Click the **Build** button (or press `F7`).
2. On the initial build cycle, CMake will pull down Catch2 via `FetchContent` directly from its repository and compile the dependencies locally into the isolated `build/` workspace.

### 3. Executing Unit Test Suites

Click the **Play Icon (Launch Target)** on the bottom VSCode status bar. Alternatively, run the generated binary straight from your project terminal window:

```bash
./build/l00001_two_sum_test

```

---

## Step-Through Debugging Guide

To step through execution layers and check memory operations (stack assignments, local variables, object layout transitions) inside your problem solutions:

1. Open the file containing the logic you want to inspect (e.g., `l00001_two_sum_test.cpp`).
2. Hover your mouse to the left of the line numbers within the `solve()` algorithm function block. Click to drop a **Red Breakpoint Dot** (e.g., on line 18: `int diff = target - nums[i];`).
3. Look back at the bottom **VSCode Status Bar** and locate the **Bug Icon (Debug)**.
4. Click the **Bug Icon**.
5. The extension will automatically coordinate the target with `gdb`, build any modifications, launch the binary execution process, and cleanly halt processing directly on your designated breakpoint line.
6. Use the overlay floating controller block or short keys to execute actions:
* `F5`: **Continue** execution to the next breakpoint.
* `F10`: **Step Over** the current instruction line.
* `F11`: **Step Into** nested code layers or library methods.



---

## Troubleshooting Workspace Cache Conflicts

If your compiler toolchain caches paths incorrectly or throws directory errors:

1. Open the Command Palette (`Ctrl + Shift + P`).
2. Run: **`CMake: Reset CMake Tools Extension State`**
3. Run: **`CMake: Delete Cache and Reconfigure`**

