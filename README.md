# Logic Design Simulator
A combinational logic circuit design and simulation application for Windows written in C++ using CMU graphics library.

# Table of Contents

1. [Overview](#Overview)
2. [How to Run](#How-to-Run-Using-Visual-Studio)
3. [User Manual](#User-Manual)\
3.1 [Add Component](#1-Add-Component)\
3.2 [Delete Component](#2-Delete-Component)\
3.3 [Copy/Cut Component](#3-Copy/Cut-Component)\
3.4 [Rename Component](#4-Rename-Component)\
3.5 [Connect Components](#5-Connect-Components)\
3.6 [Circuit Simulation](#6-Circuit-Simulation)\
3.7 [Save a Circuit](#7-Save-a-circuit)\
3.8 [Load a Circuit](#8-Load-a-circuit)
4. [Issues](#Issues)
5. [Contributers](#Contributers)
6. [License](#License)

## Overview 
This application allows user to design and simulate digital circuits; to see its output and behaviour. Simulator provides a graphical user interface (GUI) with tools for drawing circuit diagrams, simulating logic functions, and analyzing the behavior of the circuit. This was the project of the first programming course in Cairo University, Computer Engineering Department.


## How to Run Using Visual Studio 

 1. Download  all files on your local machine.
 2. Open "Project Code Framework" folder.
 3. Open "graphics_prj.sln" file, using Visual Studio.
 4. Run the code (F5).

 ## How to Run Using gcc
 &emsp; &ensp; Makefile will be added soon.

## User Manual 
 ### 1. Add Component:
 1. From the toolbar click on the component you want to add.
 <img src="https://iili.io/H7IEft9.png" width = 700px/>

 2. Click on the schema, wherever you want to place the component, the component will be added to the schema with "DefaultLabel".
  <img src="https://iili.io/H7Ir6zX.png" width = 700px/>
  
### 2. Delete Component:

 1. From the toolbar click on "Delete".
 2. Click on the component you want to delete.

 ### 3. Copy/Cut Component:
 1. From the toolbar click on "Copy"/"Cut".
 2. Click on the component you want to "Copy"/"Cut".
 3. From the toolbar click on "Paste".
 4.  Click on the schema, wherever you want to paste the component.

### 4. Rename Component:
1. From the toolbar click on "Label".
2. Click on the component you want to rename.
3. Write the new name, then press "Enter".

### 5. Connect Components:
1. From the toolbar click on "Wire".
2. Click on the first end the the wire will be connected to.
3. Click on the second end the the wire will be connected to.
4. Wire will appear between the two ends.

### 6. Simulate the Circuit:
1. Build your digital circuit.
<img src="https://iili.io/H7umdJt.png" alt="H7umdJt.png"/>

2. From the toolbar click on "Simulate".
<img src="https://iili.io/H7AJuxn.png" alt="H7AJuxn.png"/>

3. To change the switch state (on/off), click on "Switch" from the toolbar then click on the switch.
4. To return to the Design Mode, click on "Design" from the toolbar.

### 7. Save the Circuit:
1. From the toolbar click on "Save".
2. Enter the file name to be saved, then press Enter.

### 8. Load a Circuit:
1. From the toolbar click on "Load".
2. Enter the file name to be loaded, then press Enter.
**Make sure that the file is located inside "SavedFiles" directory.**

## Issues
1. XOR gate is functioning like NOR gate.
2. When switching to Simulate Mode, you should change the state of any switch to start the simulation. i.e simualtion does not start untill you change one of the switchs states.
3. Deleting a wire is a little bit challenging.
4. Truth Table and Probing is not implemtend.

## Contributers
Contributers in the project:
- [Ahmed Fathy](https://github.com/ahmed1234552)
- [Khalid Mamdouh](https://github.com/Khalidmamdou7)
- [Marwan Mostafa](https://github.com/Marwan-9)
- [Youssof Eldeeb](https://github.com/YoussofEldeeb)

## License
Copyright (c) [2021] [Ahmed Fathy, Khaled Mamdouh, Marwan Mostafa, Youssof Eldeeb]

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Mars Exploration Simulator"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE. 
