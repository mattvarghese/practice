
# Polyglot LeetCode Practice

This directory serves as a continuous execution and maintenance playground for algorithmic mastery and multi-language fluency. 

The goal is to maintain a rigorous, long-term habit of solving problems across a diverse spectrum of languages concurrently. This approach enforces deep familiarity with different runtime architectures, memory management paradigms, and language-specific design patterns (e.g., manual memory management in C++, ownership in Rust, type systems in TypeScript, object-oriented principles in C#, and rapid prototyping primitives in Python).

---

## Architecture & Scalability

The repository is structured to scale seamlessly along two dimensions:

1. **Horizontal Scaling (Languages):** Adding a new language simply requires provisioning a top-level directory (e.g., `leetcode/go/` or `leetcode/zig/`) with its respective toolchain configuration.
2. **Vertical Scaling (Problems):** Problems are added as individual source modules within each language directory. 

### Suffix-Based Naming Convention

To optimize local navigation within your IDE, file pairs (the implementation and its accompanying unit tests) **must** use a suffix-based naming scheme instead of a prefix-based one. This ensures that the source code and its validation suite sit immediately next to each other lexicographically in the workspace tree.

#### Target Structure Reference:
```text
leetcode/
├── cpp/
│   ├── 0001_two_sum.cpp
│   └── 0001_two_sum_test.cpp
├── python/
│   ├── q0001_two_sum.py
│   └── q0001_two_sum_test.py

```

---

## Supported Ecosystems & Tooling

Every language workspace here is configured for local execution, comprehensive step-through debugging via VSCode, and native unit testing frameworks:

| Language | Extension / Standard | Test Framework | Primary Debugger / Engine |
| --- | --- | --- | --- |
| **C++** | C++17 / C++20 | Native / Catch2 | `gdb` / `lldb` via GCC/Clang |
| **Python** | Python 3.10+ | `pytest` | Native VSCode Python Debugger |
| **TypeScript** | ECMAScript Next | `jest` | `ts-node` + Node.js V8 Inspector |
| **C#** | .NET 8.0+ | `xUnit` / `NUnit` | .NET Core Debugger (`vsdbg`) |
| **Rust** | Edition 2021 | Built-in (`cargo test`) | `CodeLLDB` |

---

## Execution Workflow

1. **Design:** Map the algorithmic approach conceptually.
2. **Implement:** Author the solution sequentially across all targeted runtimes to reinforce structural and syntactic shifts.
3. **Validate:** Execute the local unit test suites to ensure edge-case conformity.
4. **Profile & Step-Through:** Utilize the native VSCode debugger setups to step through variables, inspecting memory layouts (stack/heap allocations in C++ and Rust vs. reference-heavy runtimes like Python and TypeScript).
