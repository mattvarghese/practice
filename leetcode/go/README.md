# Go LeetCode Environment

This directory contains Go implementations of LeetCode problems. The workspace leverages Go's built-in `testing` package (`go test`) for fast, zero-dependency unit testing, combined with **Delve (`dlv`)** for real-time visual breakpoint debugging and stack inspection in VSCode.

---

## Workspace Directory Structure

This setup assumes you open VSCode directly inside this directory (`cd leetcode/go && code .`):

```text
leetcode/go/
├── .vscode/
│   ├── launch.json          # Debugging configuration for Go tests via Delve
│   └── settings.json        # Verbose test runner flags for VSCode
├── .gitignore               # Ignores compiled test binaries and coverage outputs
├── go.mod                   # Go module manifest
├── l00001_two_sum.go        # Target implementation module
├── l00001_two_sum_test.go   # Suffix-aligned Go test validation suite
└── README.md                # This onboarding configuration manual
```

---

## Core Software Required (Host System)

Before opening VSCode, ensure the Go toolchain is installed on your Ubuntu machine:

```bash
# 1. Update your local package index repositories
sudo apt-get update

# 2. Install Go (or download the latest release from https://go.dev/dl/)
sudo apt-get install -y golang-go
```

To verify the toolchain is active:

```bash
go version
```

Install the **Delve** debugger (also installable directly from VSCode via `Go: Install/Update Tools`):

```bash
go install github.com/go-delve/delve/cmd/dlv@latest
```

Make sure `$HOME/go/bin` is on your `PATH` (e.g., `export PATH="$PATH:$HOME/go/bin"` in `~/.bashrc`) so VSCode and your terminal can find `dlv` and `gopls`.

---

## Core VSCode Extensions Required

To enable real-time type checking, auto-formatting (`gofmt`), inline test lenses, and visual breakpoint debugging, install this official extension:

1. **Go** (`golang.go`)
   * *Official Go extension providing `gopls` language server intelligence, Test Explorer integration, and Delve debugger support.*
   * After installing, open the Command Palette (`Ctrl + Shift + P`) and run **`Go: Install/Update Tools`** (selecting `gopls` and `dlv` at minimum).

---

## Initial Environment Provisioning

Execute this single command inside the `leetcode/go` folder to initialize the Go module:

```bash
go mod init leetcode-go
```

---

## Configuration Profiles

### `go.mod`

Go includes a full-featured unit testing and benchmarking framework in its standard library, so no external dependencies are required:

```go
module leetcode-go

go 1.22
```

---

## VSCode Step-Through Debugging Integration

To pause execution inside an algorithm or test case, create a `.vscode/` folder with these configuration files:

### `.vscode/launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug Current Go Test",
            "type": "go",
            "request": "launch",
            "mode": "test",
            "program": "${fileDirname}"
        }
    ]
}
```

### `.vscode/settings.json`

```json
{
    "go.testFlags": [
        "-v"
    ]
}
```

---

## Execution & Debugging Workflow

### Writing Problems

Maintain strict lexicographical consistency for implementation and test files—Go's native `*_test.go` convention aligns directly with this repository's suffix-based scheme:

* **Implementation:** `l00001_two_sum.go`
* **Test Suite:** `l00001_two_sum_test.go`

Because all problem files share `package leetcode` in this directory, give each problem's entry function a descriptive, unique exported name (e.g., `TwoSum`, `AddTwoNumbers`) rather than a generic `Solve`.

### Running Tests from CLI

Execute the entire test suite with verbose subtest output:

```bash
go test -v ./...
```

To target a specific problem or subtest:

```bash
go test -v -run TestTwoSum ./...
```

### Stepping Through Code in VSCode

1. Open your implementation file (`l00001_two_sum.go`) or test file (`l00001_two_sum_test.go`).
2. Left-click to the left of the line numbers to place a red breakpoint inside your algorithm logic.
3. Either:
   * Click the inline **`debug test`** CodeLens directly above `func TestTwoSum(t *testing.T)`, or
   * Use the **Testing Panel (Beaker Icon)** on the sidebar to debug an individual test or subtest, or
   * Switch to the **Run and Debug View** (`Ctrl + Shift + D`), select **"Debug Current Go Test"**, and press **F5**.
4. Delve will compile the test binary and halt execution directly at your breakpoint.
