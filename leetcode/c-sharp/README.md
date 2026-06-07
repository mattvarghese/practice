
# C# LeetCode Environment

This directory contains C# implementations of LeetCode problems. The workspace uses **xUnit** for high-performance unit testing and integrates with the native .NET debugger engine for real-time variable and stack layout inspection.

---

## Workspace Directory Structure

This setup assumes you open VSCode directly inside this directory (`cd leetcode/c-sharp && code .`):

```text
leetcode/c-sharp/
├── .vscode/
│   └── launch.json          # Debugging profile runner targets for xUnit
├── bin/ / obj/              # Managed compilation targets (Git-ignored)
├── leetcode_csharp.csproj   # XML manifest mapping dependencies and .NET framework
├── l00001_two_sum.cs        # Target implementation algorithm module
├── l00001_two_sum_test.cs   # Suffix-aligned xUnit validation suite
└── README.md                # This usage configuration guide

```

---

## Core Extensions Required

To enable syntax tree generation, automated type checking, and native IDE test execution, install this specific extension pack:

* **C# Dev Kit** (`ms-dotnettools.csdevkit`)
* *Includes the official C# language engine, background project management pipelines, and visual test runner integrations.*

---

## Install .NET 10.0 SDK if required
```bash
# 1. Pull down fresh package references from your repositories
sudo apt-get update

# 2. Install the complete .NET 10 Software Development Kit (includes the runtime)
sudo apt-get install -y dotnet-sdk-10.0
```

---

## Initial Environment Provisioning

Run these commands in your terminal inside the `leetcode/c-sharp` folder to provision your environment using the .NET CLI:

### 1. Initialize Project Files

```bash
# Creates an xUnit test library project, which sets up compilation plumbing automatically
dotnet new xunit

# Delete unnecessary files
rm GlobalUsings.cs UnitTest1.cs

```

### 2. Rename Project File (Optional Alignment)

By default, the CLI will name the project file based on your parent folder name. Rename it if you want to explicitly enforce matching layouts:

```bash
mv c-sharp.csproj leetcode-csharp.csproj

```

---

## Configuration Profiles

Ensure your project configuration matches modern C# standards by validating your project manifest:

### `leetcode-csharp.csproj`

Open the file and verify it looks clean and matches this layout. We use a recent modern .NET target framework (like `.NET 8.0` or `.NET 10.0`) to give you access to rapid collection types and pattern matching:

```xml
<Project Sdk="Microsoft.NET.Sdk">

  <PropertyGroup>
    <TargetFramework>net10.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <IsPackable>false</IsPackable>
  </PropertyGroup>

  <ItemGroup>
    <PackageReference Include="Microsoft.NET.Test.Sdk" Version="17.11.1" />
    <PackageReference Include="xunit" Version="2.9.2" />
    <PackageReference Include="xunit.runner.visualstudio" Version="2.8.2" />
  </ItemGroup>

</Project>

```

### Optionally, also make `leetcode.slnx' 
```xml
<Solution>
  <Project Path="leetcode-csharp.csproj" />
</Solution>
```

---

## VSCode Step-Through Debugging Integration

To click a breakpoint inside your algorithm logic and step through it using **F5**, populate a `.vscode/` directory inside this folder with the following configuration:

### `.vscode/launch.json`

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "Debug Current C# Test",
            "type": "dotnet",
            "request": "launch",
            "projectPath": "${workspaceFolder}/leetcode-csharp.csproj"
        }
    ]
}

```

---

## Execution Workflow

### Running Tests from CLI

Execute the entire suite dynamically from the integrated terminal window:

```bash
dotnet test leetcode.slnx

# Or 
dotnet test leetcode-csharp.csproj

# NOTE: if there was only one, then we can skip the .slnx/.csproj param

```

To limit evaluation scopes down to a single chosen test module:

```bash
dotnet test --filter l00001_two_sum_test

```

### Stepping Through Code in VSCode

1. Open your implementation code block (`l00001_two_sum.cs`) or test file (`l00001_two_sum_test.cs`).
2. Set a red breakpoint marker directly on a logic transition layer inside the code.
3. Use the **Testing Panel (Beaker Icon)** on the side menu bar to see the xUnit tree populated automatically.
4. Right-click the specific test case profile row inside the UI panel tree and click **"Debug"**, or select **"Debug Current C# Test"** via `Ctrl + Shift + D` and tap **F5**.
5. Execution hooks will halt processing exactly at your breakpoint marker!

