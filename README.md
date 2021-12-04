# Introduction to SFML (simple fast media library)

This is an introductory course on SFML (simple fast media library) for C++. SFML is a library that makes drawing to the screen nice and easy using C++.

It's cross platform and if you know anything about `canvas` in `JavaScript` then you know why you want to use this.

I am personally working on MacOS and will be using Xcode to do this work.

## Installing SFML

In order to install SFML I used `brew`. If you don't know what `brew` is you can find more information here: [brew.sh](https://brew.sh).

In short `brew` is a package manager for Mac. Use this command to install sfml through brew:

```bash
brew search sfml
```

```
==> Formulae
csfml       sfml       shml
```

```bash
brew install sfml
```

This should install sfml in the cellar. The cellar is the location where brew keeps all installed packages. You can find out where this is by using the command:

```bash
brew --prefix
```

```
/opt/homebrew
```

```bash
ls $(brew --prefix)/Cellar/sfml
```

```
boost			libmpc			pcre
ca-certificates		libogg			pcre2
cairo			libpng			pixman
cmake			libpthread-stubs	pkg-config
flac			libtiff			python@3.9
fontconfig		libunistring		r
freetype		libvorbis		readline
gcc			libx11			sdl2
gdbm			libxau			sfml
gettext			libxcb			sqlite
giflib			libxdmcp		tcl-tk
glib			libxext			webp
gmp			libxrender		wget
htop			llvm			xorgproto
icu4c			lzo			xz
isl			mpdecimal		zlib
jpeg			mpfr			zsh-syntax-highlighting
libepoxy		ncurses			zstd
libffi			openblas
libidn2			openssl@1.1
```

Let's go there and explore to better understand what we will need.

```bash
ls $(brew --prefix)/Cellar/sfml
open .
```

Here you will find the following version `x.x.x`. An include folder, this holds the header files. 

<p align="center">
    <img src="./figures/sfml-location.png" width="1000">
</p>

