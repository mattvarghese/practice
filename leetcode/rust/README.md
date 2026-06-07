
# Rust LeetCode Environment

This directory contains Rust implementations of LeetCode problems. The workspace leverages **Cargo** for compilation and native unit testing, combined with **CodeLLDB** for real-time visual breakpoint debugging and stack evaluation.

---

## Workspace Directory Structure

This setup assumes you open VSCode directly inside this directory (`cd leetcode/rust && code .`):

```text
leetcode/rust/
├── .vscode/
│   └── launch.json          # Debugging targets for Cargo binary outputs
├── src/
│   ├── lib.rs               # Central module declaration tree
│   ├── l00001_two_sum.rs    # Target algorithm implementation
│   └── l00001_two_sum_test.rs # Suffix-aligned unit validation suite
├── Cargo.toml               # Package manifest (dependencies and metadata)
└── README.md                # This onboarding configuration manual

```

---

## Core Software Required (Host System)

Before opening VSCode, ensure the native Rust toolchain manager (**`rustup`**) and a suitable system debugger backend are provisioned on your Ubuntu machine.

Run these commands in your integrated terminal:

```bash
# 1. Update your local package index repositories
sudo apt-get update

# 2. Install the complete native Rust development toolchain
sudo apt-get install -y rustc cargo

```

To verify the tools are active, check their versions:

```bash
rustc --version
cargo --version

```

---

## Core VSCode Extensions Required

To enable real-time type tracking, automatic formatting on save, and visual breakpoint targets, install these two extensions:

1. **rust-analyzer** (`rust-lang.rust-analyzer`)
* *The definitive, incredibly powerful language server protocol engine for Rust codebases. Provides deep structural tracking and error highlights.*


2. **CodeLLDB** (`vadimcn.vscode-lldb`)
* *An ultra-high-performance debugger extension built specifically to coordinate compilation frames from languages like C++ and Rust straight back into VSCode.*



---

## Initial Environment Provisioning

Execute this single setup pipeline inside the `leetcode/rust` folder to automatically map out your package tree blueprint:

```bash
# Initializes an idiomatic Rust library package structure
cargo init --lib .

```

---

## Configuration Profiles

Ensure your project properties match the modern Cargo structure by populating these files at your root context layer:

#### `Cargo.toml`

Open your generated manifest profile and ensure it mirrors this clean dependency layout. Rust has its own robust, built-in benchmarking and unit testing harnesses, so no extra heavy dependencies are required:

```toml
[package]
name = "leetcode_rust"
version = "0.1.0"
edition = "2021"

[dependencies]
# No external crates required for core LeetCode tracks!

```

#### `src/lib.rs`

In Rust, the compiler must explicitly know about files through a module tree. Open `src/lib.rs`, delete any boilerplate, and register your algorithm modules:

```rust
// Registers your code files into the compilation unit tree
pub mod l00001_two_sum;

```

---

## VSCode Step-Through Debugging Integration

To pause execution execution lines inside an algorithm context, create a `.vscode/` folder and drop in this configuration target:

### `.vscode/launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug Current Rust Test",
            "type": "lldb",
            "request": "launch",
            "cargo": {
                "args": [
                    "test",
                    "--no-run",
                    "--lib"
                ],
                "filter": {
                    "name": "leetcode_rust",
                    "kind": "lib"
                }
            },
            "args": [],
            "cwd": "${workspaceFolder}"
        }
    ]
}

```

---

## Execution & Debugging Workflow

### Writing Problems

Always maintain strict lexicographical consistency for implementation paths and assertions:

* **Implementation Path:** `src/l00001_two_sum.rs`
* **Test Harness Suite:** `src/l00001_two_sum_test.rs`

*Note: In Rust, tests can be written directly inside an isolated module within your code file, or placed in a dedicated suffix-aligned module included via the main implementation file.*

### Running Tests from CLI

Execute the complete testing suite directly via the cargo daemon engine:

```bash
cargo test

```

To isolate verification sweeps down to a single designated module:

```bash
cargo test l00001_two_sum

```

### Stepping Through Code in VSCode

1. Open your target implementation or unit verification file.
2. Left-click next to the line markers to register a red visual breakpoint.
3. Switch to the **Run and Debug View** (`Ctrl + Shift + D`).
4. Select **"Debug Current Rust Test"** from the drop-down menu layer and tap **F5**.
   * Or, the same is also available at the bottom.
5. CodeLLDB will quickly build the binary footprint and halt execution directly on your breakpoint line.

