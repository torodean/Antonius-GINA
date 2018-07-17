GINA (Generations of Implanted Nuclear Activity)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~ IMPORTANT ~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
My computer died shortly after creating a working version of GINA.
I was able to recover my data but I no longer have a working linux development laptop.
Therefore further changes have not been made.

Release version 1.013

Author: Antonius Torode
Created: June 2017

How to remove unneccessary files from build directory.
find \( -name "moc_*" -or -name "*.o" -or -name "qrc_*" -or -name "Makefile*" -or -name "*.a" \) -exec rm {} \;

Compiled and created using Qt5.9 then deployed (made self-contained) using linuxdeployqt.
sudo ./linuxdeployqt-continuous-x86_64.AppImage <PATH TO GINA EXECUTABLE>/GINA

	For some reason this does not work when <PATH TO GINA EXECUTABLE> == "bin"

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Compiling using utilities/GINARelease.sh
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1) First, you must have Qt installed and working
2) Build and run the program through Qt into a bin/build-GINA-Desktop_Qt_5_9_0_GCC_64bit-Debug folder within the Antonius-GINA folder. 
3) navigate to the utilities folder and run 

	sudo ./GINARelease.sh

4) The release folder should now contain everything you need for a release version.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Compiling Program from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1) First, you must have Qt installed and working
2) Build and run the program through Qt
3) Copy the build directory to another location and put linuxdeployqt-continuous-x86_64.AppImage in the same directory as the build directory.
4) While in the build directory, run the following commands (leave the name of the build directory as the default created by qt or the linuxdeployqt... may not work)

find \( -name "moc_*" -or -name "*.o" -or -name "qrc_*" -or -name "Makefile*" -or -name "*.a" \) -exec rm {} \;
rm -r Analysis Images
cd ../
./linuxdeployqt-continuous-x86_64.AppImage <NAME OF BUILD DIRECTORY>/GINA
mv <NAME OF BUILD DIRECTORY> bin

5) Copy bin folder to where you want GINA to be, transfer source code over into a folder named src, and documentation/other files accordingly.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Program Features/Help
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

-----------------------------------------------
The nuclear ion generations is incremented from 0 to n with 0 representing the primary ion, 1 representing the daughter ion, and so forth...
-----------------------------------------------
-- Nuclei Count: These are the total number of each ion present on the target after a certain amount of time.
-----------------------------------------------
-- Decay rates: These are the total decays per second that each ion is undergoing.
-----------------------------------------------
-- Contamination: This represents the total contamination of primary ion decays with respect to the other ions decaying.
-----------------------------------------------
-- Loss: This shows the percentage of the implanted ions that are not of the primary ion.
-----------------------------------------------
-- Health: This shows the percentage of the implanted ions that are of the primary ion.
-----------------------------------------------
To change graph settings and display, go to program > Graph Settings.
-----------------------------------------------
Hover over any label to get extended tool-tip information about the field.
-----------------------------------------------
For extended explanations and derivations of the equations used, see the program documentation.
-----------------------------------------------
 -- The advanced > Show Data feature determines whether data is printed to the debugger window.
 -- Disabling this option will speed up the creation of the graphs but provide less information.
-----------------------------------------------
 -- The advanced > Hide Graphs feature determines whether graphs are produced by GINA upon analysis.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
damageControl.py
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
This file calculates the particle numbers and decays rates of a target point after it has been rotated away from the implantation point. See the file for more information.
