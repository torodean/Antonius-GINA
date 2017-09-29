GINA (Generations of Implanted Nuclear Atrophy)

Release version 1.013

Author: Antonius Torode
Created: June 2017

Remove unneccessary files.
find \( -name "moc_*" -or -name "*.o" -or -name "qrc_*" -or -name "Makefile*" -or -name "*.a" \) -exec rm {} \;

Compiled and created using Qt5.9 then deployed (made self-contained) using linuxdeployqt.
sudo ./linuxdeployqt-continuous-x86_64.AppImage <PATH TO GINA EXECUTABLE>/GINA

For some reason this does not work when <PATH TO GINA EXECUTABLE> == "bin"


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
