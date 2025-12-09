# armake — MBarkerUK fork

[![CI](https://github.com/MBarkerUK/armake/actions/workflows/ci.yml/badge.svg)](https://github.com/MBarkerUK/armake/actions/workflows/ci.yml)

This repository is a fork of the original `armake` project. The original project and full documentation remain available at: https://github.com/KoffeinFlummi/armake

This fork is maintained by MBarkerUK to keep a small, focused set of fixes and modern CI in place for reliable builds.

What this fork provides (summary)

- Build fixes:
  - Converted Makefile recipes to use tab-prefixed recipes (fixes "missing separator" on some systems).
  - Moved a few globals out of headers into a single `src/globals.c` to avoid multiple-definition linker errors.
  - Added missing standard includes so compilation is robust across toolchains.
- CI & maintenance:
  - GitHub Actions workflow to build and run the bundled tests on Ubuntu.
  - Dependabot configuration to keep GitHub Actions up to date.
- Release: tagged as `v0.6.3-patched` in this fork for reference.

If you want the upstream project to accept these changes, open an issue or PR on the original repository. For now, this fork will be kept up-to-date here.

Quick start

```
$ make
$ ./test/run.sh
```

If you want to install system dependencies (Ubuntu/Debian):

```
$ sudo apt-get update
$ sudo apt-get install build-essential flex bison pkg-config libssl-dev imagemagick
```

Changelog / Patch details

- See the `v0.6.3-patched` tag and recent commits for the exact diffs. The main changes are small and targeted to fix build/linker problems and add CI.

More details and full original README

This README intentionally keeps a short summary. For full documentation and feature details, see the original project's README:

https://github.com/KoffeinFlummi/armake/blob/master/README.md

License

This project is distributed under the same license as the original (GPLv2 or later). See `LICENSE`.
