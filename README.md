# Introduction to SFML (simple fast media library)

This is an introductory course on SFML (simple fast media library) for C++. SFML is a library that makes drawing to the screen nice and easy using C++.

It's cross platform and if you know anything about `canvas` in `JavaScript` then you know why you want to use this.

I am personally working on MacOS and will be using Xcode to do this work.

## Installing SFML

In order to see if our installation is working, I give you a small sample of code a small sfml hello world. Use this as a simple test for now and we will cover more on what each part does in the following sections:

```Cpp
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "Hello world!", sf::Style::Close | sf::Style::Titlebar);

	while (window.isOpen()) {
		sf::Event evnt;
		while (window.pollEvent(evnt)) {
			if(evnt.type == evnt.Closed) {
				window.close();
			}
		}
	}

    return 0;
}
```

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

Here you will find the following version `x.x.x`. An include folder, this holds the header files. As you can see there is also a lib directory this holds the `.dylib` files.

<p align="center">
    <img src="./figures/sfml-location.png" width="100%">
</p>

We need to link these to our project or else you will get an error that looks something like this:

<p align="center">
    <img src="./figures/unlinked-library.png" width="100%">
</p>

The way we do this is by telling our project in Xcode where these files are. First we have to tell it the search path for the header files. Then we have to tell it for the paths for `.dylib`s with which it will link our project.

Click on your project in the explorer pane: 

<p align="center">
    <img src="./figures/xcode-project.png" width="100%">
</p>

Go to the "Build Settings" tab; and find the option called "Header Search Paths". Fill this path out with the location of our library include folder. As we saw previously ours is: `/opt/homebrew/Cellar/sfml/2.5.1_1/include`

<p align="center">
    <img src="./figures/header-search-path.png" width="100%">
</p>

Now go to the "Build Phases" tab. There look for the "Link Binary With Libraries" option. Open that and we now need to add five separate libraries from sfml. Add these using the explorer:

<p align="center">
    <img src="./figures/dylib-libraries-path.png" width="100%">
</p>

Now you might think that's all; if we try to compile and run our code now you will find we get an error. It should look something like this:

<p align="center">
    <img src="./figures/library-signing-erorr.png" width="100%">
</p>

This is because the library we're using is signed by a different developer than us and when linking two separate signatures are on these. We need to turn off signature validation or re-sign the library. Here I show you how to turn off this validation as a short-term fix:

<p align="center">
    <img src="./figures/turn-off-library-validation.png" width="100%">
</p>

As you can see under "Signing & Capabilities" check "Disable Library Validation". Once done our code should work now:

<p align="center">
    <img src="./figures/sfml-hello-world.png" width="100%">
</p>
