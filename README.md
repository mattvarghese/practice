# practice
Lifelong coding practice repo



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

