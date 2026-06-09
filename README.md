# practice
Lifelong coding practice repo

---

# Configuring CI pipeline with reject on failure

This section summarizes the setup for an automated C++23 CI pipeline that enforces strict code quality and prevents the merging of code that breaks builds or falls below coverage thresholds.

---

## 1. Define the CI Pipeline

Create the file `.github/workflows/ci.yml` at the root of your repository. To ensure the pipeline runs on every branch, use the `` wildcard in your triggers:

```yaml
name: C++23 CI Pipeline

on:
  push:
    branches: [ '**' ]
  pull_request:
    branches: [ '**' ]

...

```

---

## 2. Enforce the "Hard Gate" (Branch Protection)

To prevent bad code from reaching your `main` branch:

1. Navigate to your repository on **GitHub.com**.
2. Go to **Settings > Branches > Branch protection rules**.
3. Create a rule for `main`.
4. Enable **Require status checks to pass before merging**.
5. Select `build-and-test` as a required status check.
6. Save the changes.

---

## 3. Development Workflow

Following this setup, adopt the following professional workflow:

* **Create a Feature Branch:** Always work on a separate branch: `git checkout -b feature/my-work`.
* **Breaking Commits:** If you push a commit that breaks the build, the CI will fail. Because you have branch protection, you cannot merge this code.
* **Restoration:** To fix the build, commit the corrected code to the same feature branch: `git commit -m "fix: restore working state" && git push`.
* **Pull Request:** Open a PR via the GitHub web interface from your feature branch to `main`.
* **Verification:** The CI runner will automatically execute the workflow on the PR. You must wait for the "Green Checkmark" indicating all tests passed and coverage is met.
* **Merge and Cleanup:** Once the CI passes, click **Merge pull request** on the web interface. Finally, delete the feature branch locally (`git branch -d feature/my-work`) and on the remote (`git push origin --delete feature/my-work`).

---

# Squashing Commits (Interactive Rebase)

When you need to clean up your commit history by rolling multiple commits into one (e.g., combining a "work-in-progress" commit with a "fix" commit), use an **interactive rebase**.

# Steps to combine the last 3 commits:

1. **Start the Rebase:**
Run the following command to open your text editor with the last 3 commits:
```bash
git rebase -i HEAD~3

```
2. **Squash the Commits:**
In the text editor, you will see a list of your 3 commits. Keep the first one as `pick` and change the word `pick` to `squash` (or `s`) for the remaining two.
*Example:*
```text
pick a1b2c3d First commit
squash e4f5g6h Second commit
squash i7j8k9l Third commit

```
3. **Refine the Message:**
Save and close the file. A second editor window will open, allowing you to combine or replace the previous commit messages with a single, clear summary of the work.
4. **Force Push:**
Because you have rewritten the local history, you must force-push the changes to your branch:
```bash
git push --force

```

> **Warning:** Only use `--force` on your own feature branches. **Never** use this on the `main` branch or any shared team branch, as it will disrupt history for others.


