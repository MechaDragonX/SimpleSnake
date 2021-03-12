# Simple Snake

## What is this?
This is my code for my final project for the C++ class I took in winter quarter 2021, my freshman year of college.

## Why are there are so many comments saying where things should go?
Our teacher gave us starter code that invovled the primary main loop logic, a GUI class that abstracted out ncurses, and basic skeletons of classes used. Most of the code written is my own.

## What dependencies are there?
You need ncurses to compile the project.
### Installation Instructions
#### Debian-based Distributions
```shell
$ apt install libncurses-dev
```
#### Arch Linux
```shell
$ pacman -S ncurses
```
#### macOS
You need the [Homebrew package manager](https://brew.sh) to compile on macOS.
```shell
$ brew install ncurses
```
**Instructions for other distributions and Linux environments for Windows, such as Cygwin and MSYS2 can be found on their package listings.**

## How do I run this?
If you are on Linux, macOS, or a Linux environment on Windows (such as Cygwin, MSYS2, or Windows Subsystem for Linux), simply run the following commands:
```shell
$ make
$ ./snake
```
