# Bot-Script
provides you with the means to click, type and compare screen states

## Step1:

* Make
* ./setup
* set up relative cursor position
* create as many location or reference files as you need for your script

## Step2:

* cd script_dir
* edit main.cpp and write your script in myScript();
* cd ..
* Make
* ./script
* set up relative cursor position and let your script run

## What is a REF?

A REF stores your relative cursor position and a small screenshot around your cursor.
When you use `Screen::CheckRef` it will compare the image your reference has of the screen with the image currently on your screen at your cursor location.
REFs are useful for deciding what state your script should be in. You should always pick high contrast areas of the screen when picking
areas to store as a REF.

## What is a LOC?

A LOC just stores your relative cursor position and allows access to them with a string identifier. `Screen::GetLoc`
is used to exctract the cursor location, which you can then use to click on a specific area of the screen.

___

note: this is MacOS exclusive since is uses Objective C for events.
