# Contributing to PriveX

Thank you for your interest in contributing! Here's how to get started.

## Getting Started

1. **Fork** this repository
2. **Clone** your fork: `git clone https://github.com/YOUR_USERNAME/privex.git`
3. **Create a branch**: `git checkout -b feature/your-feature-name`
4. **Install dependencies**: `npm run setup`
5. **Make your changes** and ensure tests pass: `npm test`
6. **Commit** with a clear message: `git commit -m "feat: add group expiry support"`
7. **Push** your branch and open a **Pull Request**

## Commit Message Format

We follow [Conventional Commits](https://www.conventionalcommits.org/):

```
feat: add new feature
fix: fix a bug
docs: update documentation
refactor: refactor code without feature change
test: add or update tests
chore: build or tooling changes
```

## Pull Request Guidelines

- Keep PRs focused — one feature or fix per PR
- Include a clear description of what you changed and why
- Make sure `npm test` passes (all 17 tests green)
- Update the README if your change affects usage or setup

## Code Style

- Use `const` / `let`, no `var`
- Keep functions small and focused
- Avoid unnecessary comments — write self-documenting code
- Use descriptive variable names

## Reporting Bugs

Open a GitHub Issue with:
- Steps to reproduce
- What you expected vs. what happened
- Your OS, browser, and MetaMask version

## Questions?

Open a GitHub Discussion or an Issue tagged `question`.
