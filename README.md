# BlitRPG

## What is this?
This is an intentionally ambitious project aimed to help push myself to learn game dev. This is *not* an attempt to build a game and there is no gaurantee that half of the features outlined below will ever get made. That being said, I would very much like to see that completion eventually, even if it's something that I do on-and-off over the new few years.

I've already started working on some of the concepts outlined below and have uploaded a couple of videos to Youtube to demonstrate. The code used to show this working is hacked into a copy of the 32Blit project itself and so is not suitable to be shared at this time. I intend to pull the code out into *this* repository and continue development from there.

* [32Blit - Progress Update #1](https://www.youtube.com/watch?v=iS36iDcxn4E)
* [32Blit - Progress Update #2](https://www.youtube.com/watch?v=cCzTzIE_fMI)

## Goals
Create a some-what modular library of features, It should, in theory, be possible to add and remove features with little effort. There will be a number of core features that will exist inside of the core. I'll do my best to keep all other features outside and in stand-alone modules. Please note that the following lists are subject to change

Core Features:
- [ ] Tile based maps
- [ ] Animated player movement
- [ ] Mobs
- [ ] Mele and Sword based combat
- [ ] Player Health (and death)

Modular Features:
- [ ] Fishing
- [ ] Mining
- [ ] Smithing
- [ ] Crafting
- [ ] Magic (skills and combat)

## 32Blit
I am building this mostly to play around with my beta unit of the 32Blit. This That does not mean that this is strictly a project for the Blit, however it is the only device that I will be supporting or testing on. I encourage you to follow along with the 32Blit project and when they become available to purchase, I encourage you to buy one. It's a neat device.

Links:

* [Website](https://32blit.com/)
* [Kickstarter](https://www.kickstarter.com/projects/pimoroni/32blit-retro-inspired-handheld-with-open-source-fi/description)
* [Source](https://github.com/pimoroni/32blit-beta)

## Before You Begin
_Note: I am developing on OSX 10.15. I do not currently intend to provide any assistance / instructions for developers working in other environments._

You will need build tools and CMAKE. Assuming you have [homebrew](https://docs.brew.sh/Installation) installed:

``` shell
xcode-select --install
brew install cmake
```

You will also need to build and install SDL2:

``` shell
wget https://www.libsdl.org/release/SDL2-2.0.10.zip
unzip SDL2-2.0.10.zip
cd SDL2-2.0.10
mkdir build
cd build
../configure
make
sudo make install
```

You will need `dfu-util` for flashing code to the 32Blit

```
brew install dfu-util
```

## Getting Started
After cloning this project to your machine, you will need to install the dependencies. These are managed using GIT submodules, so you can install them with the following command:

```
git submodule update --init --recursive
```

Build for 32Blit

```
make prepare-build
make compile
```

Flash to 32Blit. Your device should be in DFU mode and connected via usb before running the following

```
make flash
```

## Dependency Management
At this moment in time, i'm not really sure what is the best way to manage dependencies within the C++ eco system. With that in mind, I am currently intending to pull in dependencies using GIT sub modules, it will allow for easy control over the version of external code used and is very easy to manage.

## Author
I'm a professional programmer with experience in quite a few high level languages. Most recently i've been spending a lot of time in the Javascript world. I'm very new to C++ and as a result, there will be a lot of situations where I make mistakes. I am very open to help and guidance. If you spot an issue with my code, or feel that you could do a much better job. I encourage you to raise a pull request to let me know! Please :)
