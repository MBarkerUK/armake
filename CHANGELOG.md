# Changelog

All notable changes to this fork are recorded here. This file summarizes recent commits made to the `MBarkerUK/armake` fork — primarily focused on build fixes, CI, and maintenance updates.

## v0.6.3-patched (2025-12-09)

- 924a6fd: patch: fix Makefile recipes + move globals to single source
  - Converted space-indented Makefile recipes to tabs and removed an invalid `.RECIPEPREFIX`.
  - Declared globals `args`, `current_target`, and `include_stack` as `extern` in headers.
  - Added `src/globals.c` to provide single definitions for the globals.
  - Fixed missing includes (`stddef.h`, `stdio.h`) in headers to ensure clean compilation.

- f39c2a3: ci: add GitHub Actions workflow and Dependabot config
  - Added `.github/workflows/ci.yml` (build+test matrix on Ubuntu) and `.github/dependabot.yml`.

- 30ac094: ci: use ubuntu-latest in matrix to improve runner availability

- 9593a18: ci: install ImageMagick so PAA compare test can run
  - Ensure `compare` from ImageMagick is available for `test/paa/test.sh`.

- 9031d29 / c4a4a16: docs: simplify README and note this fork
  - Added a short fork-focused README linking to the original project and summarizing the patch + CI.

## Notes

- This fork is intended to remain small and focused: fix build/linker issues and keep CI running so the tool continues to build reliably across modern runners.
- For full usage and upstream documentation, see: https://github.com/KoffeinFlummi/armake/blob/master/README.md

