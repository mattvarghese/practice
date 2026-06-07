
# Python LeetCode Environment

This directory contains Python 3 implementations of LeetCode problems, using `pytest` for local unit testing and integrated VSCode debugging for real-time variable and call-stack inspection.

---

## Workspace Directory Structure

```text
leetcode/python/
├── .venv/                   # Isolated virtual environment (Git-ignored)
├── .vscode/
│   ├── launch.json          # Debugging configurations for pytest
│   └── settings.json        # Python path and test provider isolation
├── requirements.txt         # Project dependencies (pytest, etc.)
├── l0001_two_sum.py         # Problem implementation
├── l0001_two_sum_test.py    # Suffix-based pytest file
└── README.md                # This setup guide

```

---

## Initial Environment Setup

Run these commands from your terminal inside the `leetcode/python/` directory to provision your environment:

### 1. Create the Virtual Environment

```bash
python3 -m venv .venv

```

### 2. Activate the Environment & Upgrade Pip

```bash
source .venv/bin/bin/activate
pip install --upgrade pip

```

### 3. Install Dependencies

Create a `requirements.txt` file containing:

```text
pytest==8.2.2

```

Then install it:

```bash
pip install -r requirements.txt

```

---

## VSCode Integration Configurations

To ensure VSCode respects your virtual environment and seamlessly hooks into `pytest`, create a `.vscode/` directory inside `leetcode/python/` and populate the following two files.

### `.vscode/settings.json`

This file forces VSCode to use the local `.venv` interpreter and enables the native testing interface.

```json
{
    "python.terminal.activateEnvironment": true,
    "python.testing.pytestEnabled": true,
    "python.testing.unittestEnabled": false,
    "python.testing.pytestArgs": [
        "."
    ]
}
```

---

## Execution & Debugging Workflow

### Writing Problems

Always keep the implementation and test files lexicographically aligned:

* **Implementation:** `l00001_two_sum.py`
* **Test Suite:** `l00001_two_sum_test.py`

### Running Tests Via CLI

With your `.venv` activated, run all python tests using:

```bash
pytest

```
