armake
======

[![](https://img.shields.io/travis/KoffeinFlummi/armake/master.svg?style=flat-square)](https://travis-ci.org/KoffeinFlummi/armake)
[![](https://img.shields.io/badge/license-GPLv2-red.svg?style=flat-square)](https://github.com/KoffeinFlummi/armake/blob/master/LICENSE)
[![](https://img.shields.io/github/tag/KoffeinFlummi/armake.svg?style=flat-square)](https://github.com/KoffeinFlummi/armake/releases)
[![](https://img.shields.io/badge/AUR-armake-blue.svg?style=flat-square)](https://aur.archlinux.org/packages/armake)
[![](https://img.shields.io/badge/PPA-koffeinflummi%2Farmake-orange.svg?style=flat-square)](https://launchpad.net/~koffeinflummi/+archive/ubuntu/armake)


A cross-platform, open-source C implementation of Arma modding tools (PAA conversion, binarization & rapification, PBO packing, key generation and signing). It aims to provide a complete reimplementation of the entire process, but is able to use the official BI tools on Windows for building P3Ds if it can find them, as P3D conversion is still incomplete (and most likely will never be fully complete). Terrains and RTMs are not supported at the moment (I recommend binarizing RTMs once and then using the binarized version in your repo for now).

> Note: This repository is a fork maintained by MBarkerUK containing a small, focused patch to fix build and linker issues in the original project. The fork keeps the original functionality and receives CI plus dependency updates here. If you want the upstream project to adopt this change, open an issue or PR on the original repo — otherwise this fork will continue to be maintained independently.


### Features

#### Designed for Automation

armake is designed to be used in conjunction with tools like make to build larger projects. It deliberately does not provide a mechanism for building entire projects - composed of multiple PBO files - in one call. armake itself also does not do any threading. However, it is safe to run multiple armake instances at the same time, so you can use make to run, say, 4 armake instances simultaneously with `make -j4`. For examples of Makefiles that use armake, check out [ACE3](https://github.com/acemod/ACE3/blob/armake/Makefile) and [ACRE2](https://github.com/IDI-Systems/acre2/blob/armake/Makefile).

#### Decent Errors & Warnings

armake aims to provide developers with expressive and useful error messages, without trying to be smarter than them. It allows disabling most warnings and tries to only error out if a complete build is impossible or impractical.

#### No P-drive

To enable armake to run on non-Windows systems without hacky workarounds, and because it's a terrible idea in general, armake does not make use of the P-drive for finding include files. Instead - like with other compilers - you provide the folders to search for includes in the armake call.

#### Determinism

Unlike other Arma modding tools, armake includes no timestamp information in the built files. This means that - given two identical source folders - armake will produce the exact same output, bit for bit. This means that your team doesn't have to distribute a single build to make sure you're each testing the same PBOs, you can simply build it in multiple places and compare file hashes. This doesn't include cryptographic operations of course.

Note that there can be newline differences in different instances of the same git repo, depending on your settings. While they don't matter for config rapification, files with weird newlines copied into the PBO directly might ruin your PBO's hash comparison.

#### Speed

<p align="center">
    <a href="https://i.imgur.com/PtOBaIK.png">
        <img src="https://i.imgur.com/PtOBaIK.png" style="max-width:100%;">
    </a><br/>
    (Tests ran on a 2 core Windows VM using PboProject v2.24.6.43 and armake commit <code>54079138</code>)
</p>

### Setup

#### From Source

```
$ make
$ sudo make install
```

**Dependencies:**
- GCC
- OpenSSL development libraries (`libssl-dev` on Ubuntu)

#### Arch Linux

[PKGBUILD](https://aur.archlinux.org/packages/armake/) or [PKGBUILD (development)](https://aur.archlinux.org/packages/armake-git/)
```
$ pacaur -S armake      # or use yaourt or whatever AUR helper you use
$ pacaur -S armake-git
```

#### Ubuntu & Other Debian Derivatives

[PPA](https://launchpad.net/~koffeinflummi/+archive/ubuntu/armake)

```
$ sudo add-apt-repository ppa:koffeinflummi/armake
$ sudo apt-get update
$ sudo apt-get install armake
```


### Usage

```
armake

Usage:
    armake binarize [-f] [-w <wname>] [-i <includefolder>] <source> [<target>]
    armake build [-f] [-p] [-w <wname>] [-i <includefolder>] [-x <xlist>] [-k <privatekey>] [-s <signature>] [-e <headerextension>] <folder> <pbo>
    armake inspect <pbo>
    armake unpack [-f] [-i <includepattern>] [-x <excludepattern>] <pbo> <folder>
    armake cat <pbo> <name>
    armake derapify [-f] [-d <indentation>] [<source> [<target>]]
    armake keygen [-f] <keyname>
    armake sign [-f] [-s <signature>] <privatekey> <pbo>
    armake paa2img [-f] <source> <target>
    armake img2paa [-f] [-z] [-t <paatype>] <source> <target>
    armake (-h | --help)
    armake (-v | --version)
````markdown
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

````
