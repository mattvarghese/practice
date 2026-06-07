
# TypeScript LeetCode Environment

This directory contains TypeScript implementations of LeetCode problems. The workspace uses **Jest** for rapid unit testing and integrates directly with the native VSCode Node.js debugging engine for real-time variable inspection.

---

## Workspace Directory Structure

This setup assumes you open VSCode directly inside this directory (`cd leetcode/typescript && code .`):

```text
leetcode/typescript/
├── .vscode/
│   └── launch.json          # Debugging runner mappings for Jest
├── node_modules/            # Local dependencies (Git-ignored)
├── package.json             # Scripts and dependency versions
├── tsconfig.json            # Strict TypeScript compilation rules
├── jest.config.ts           # Jest runner environment definitions
├── l00001_two_sum.ts        # Target implementation module
├── l00001_two_sum_test.ts   # Suffix-aligned Jest validation suite
└── README.md                # This configuration manual

```

---

## Core Extensions Required

To ensure full syntax intelligence, auto-imports, and inline error reporting, verify that this extension is active:

* **JavaScript and TypeScript Nightly** (`ms-vscode.vscode-typescript-next`) or the built-in VSCode TypeScript language features.

---

## Initial Environment Provisioning

Run these commands in your terminal inside the `leetcode/typescript` folder to initialize your environment:

### 1. Initialize Node Project & Install Dependencies

```bash
npm init -y
npm install -D typescript jest ts-jest @types/jest ts-node

```
Then update `type` in `package.json` to `module`. Also note the overrides remove `npm install` warnings.

### 2. Generate Configuration Profiles

Create the following two files in the root of your `typescript` directory:

#### `tsconfig.json`

```json
{
  "compilerOptions": {
    "target": "ES2022",
    "module": "commonjs",
    "lib": ["ES2022"],
    "strict": true,
    "esModuleInterop": true,
    "skipLibCheck": true,
    "forceConsistentCasingInFileNames": true,
    "outDir": "./dist",
    "types": ["jest"]
  },
  "include": ["**/*.ts"]
}

```

#### `jest.config.ts`

```typescript
import type { Config } from 'jest';

const config: Config = {
  preset: 'ts-jest',
  testEnvironment: 'node',
  testMatch: ['**/*_test.ts'], // Keeps your suffix-aligned scheme intact
};

export default config;

```

#### Add a Test Script to `package.json`

Open your generated `package.json` and update the `"scripts"` field:

```json
"scripts": {
  "test": "jest"
}

```

---

## VSCode Step-Through Debugging Integration

To allow debugging individual test modules using visual breakpoints, create a `.vscode/` directory inside this folder and populate it with the following configuration:

### `.vscode/launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug Current TS Test",
            "type": "node",
            "request": "launch",
            "program": "${workspaceFolder}/node_modules/.bin/jest",
            "args": [
                "${file}",
                "--config",
                "${workspaceFolder}/jest.config.ts",
                "--runInBand"
            ],
            "console": "integratedTerminal",
            "internalConsoleOptions": "neverOpen"
        }
    ]
}

```

---

## Execution Workflow

### Running Tests from CLI

Execute the entire test suite via npm:

```bash
npm test

```

To run or target a specific file:

```bash
npx jest l00001_two_sum_test.ts

```

### Stepping Through Code in VSCode

1. Open your implementation file (`l00001_two_sum.ts`) or test file (`l00001_two_sum_test.ts`).
2. Left-click to the side of the line numbers to set a red breakpoint inside your algorithm logic.
3. Switch to the **Run and Debug View** (`Ctrl + Shift + D`).
4. Ensure **"Debug Current TS Test"** is chosen in the configuration drop-down menu, then hit **F5**.
5. The execution layout will halt directly on your breakpoint, allowing you to trace stack properties and look at runtime scopes.
