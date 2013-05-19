# Lab 09 &mdash; Graphical Animation with Qt

## Lab Goal
Gain familiarity with Qt graphics and animation, and how to work with slots and signals through a timer and with buttons.

#### Design Document
There is no design writeup due with this lab.

#### Grading
This lab is worth 10 points. There is two points of extra credit possible.

## Introduction
First, get the code &ndash; see below &ndash; and run it to see a red square that moves around the Qt window. The borders of the space the square moves in are 250 pixels by 250 pixels. The window itself is 500 x 500 pixels.

You are to enhance the provided code in two ways: Parts 1 and 2 below.

## Preliminaries
In order to develop Qt applications on the [course vm](https://github.com/usc-csci102-spring2013/programming_assignments/wiki/Course-VM), you would need to install the the Qt development packages. If you have yet to do so,  download and run [Update 2](https://github.com/usc-csci102-spring2013/programming_assignments/wiki/Course-VM) from the VM Updates section in the [course vm](https://github.com/usc-csci102-spring2013/programming_assignments/wiki/Course-VM) wiki page.

### Qt Tutorial & Sample Code
The Qt documentation provides a good set of tutorials and example code that you can use as the basis of your development in this lab and any future work.

The following tutorial should serve as a starting point in particular chapters 9 through 12:
>http://doc.qt.digia.com/4.3/tutorial.html

### Lab 09 Code
A new commit was pushed to your private lab repository. Your repo now includes a new directory named `lab09/` with the base code for this lab.

To update the local copy of your private lab repository, you would need to perform a `git pull`.

```shell
#Change directory to the home directory
#   If you have your repos somewhere else,
#   cd to that location
cd

#Change directory to your private lab repository
#   Replace ttrojan with your actual USC username
cd lab_ttrojan

#Fetch all the updates from the GitHub server to your local copy
git pull

#Check the code for this lab
cd lab09/
ls -l
```

#### Compile a Qt Project
There are three steps to compile a Qt project:

  1. Create a Qt project file. A project file is named `dirctory_name.pro`, e.g. `lab09.pro` and holds the list of cpp and header files used in your project. You generate a project file by:
```shell
qmake -project
```

  1. Generate a `Makefile` for your project based on the project file in (1):
```shell
qmake
```

  1. Now, compile your code as usual using the `make` command
```shell
make
```

By default, the executable holds the name of the project which in this case is `lab09`. You should note:
  + To compile your project after editing _existing_ files, you just need to call `make`
  + When adding new files to your project, you should re-generate the project file and `Makefile` by repeating the process.

## Part 1 &ndash; Add a Button to Stop/Start the Timer (4 points)
The timer is started when the program first begins &ndash; and does not stop. Add a button that will stop the timer if the timer is on, and will start the timer if the timer is off. The `QTimer` class has an `isActive()` method that is _true_ if the timer is running, and _false_ if the timer is not running. You will have to use the `connect()` method to link the `clicked()` signal function to your new function. Be sure to declare the function under the _public slots_ section of your `MainWindow` class.

Here is a link to the `QTimer` class reference documentation:
>http://qt-project.org/doc/qt-4.8/qtimer.html


## Part 2 &ndash; Create Rectangles at Random Locations, Color, and Speed (6 points)
The provided code only creates a single rectangle that moves. Change this so that rectangles get created every so often &ndash; say every 50 executions of the `handleTimer()` function. Create a new rectangle at a random location &ndash; not to exceed the 250x250 size of the animation window &ndash; and with a random velocity in the x- and y-directions. Assign a color randomly. You can do this by having a `switch` statement with at least 4 colors of your choice.

~~You don't have to store the new rectangles in a list, as adding them to the scene will cause the scene to keep track of them. You would only have to store them in a list if you wanted to delete them at some point in the program execution &ndash; like something being killed in a game.~~

You do need to keep track of all the newly created rectangles as you need to call `move` on each one of them.

## Extra Credit &ndash; Use an Image Instead of a Rectangle (2 points)
Change your program so that it displays a small image, instead of a rectangle. Nothing else should change from parts 1, or 2.

A simple way to display images in Qt is with the `QLabel` class. `QLabel`s can display text, or images. A link to the reference documentation is:
>http://qt-project.org/doc/qt-4.8/qlabel.html

