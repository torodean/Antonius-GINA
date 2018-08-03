#============================================================================
# Name        : MIAMain.cpp
# Author      : Antonius Torode
# Copyright   : This file can be used under the conditions of Antonius' 
#				 General Purpose License (AGPL).
# Description : GINA plotter.
#============================================================================
# 
# This file will plot data from a GINA output file.
# You must remove the first line of the GINA output file for this code to work.
# 
#============================================================================

from __future__ import division
import numpy as np
import pylab as plt
import math as mth
from scipy.constants import pi

inputFile = '42S(1.03sec)-_42Cl(6.08sec)-_42Ar(32.9yr)-_(stable).txt'

# Creates arrays for storing data.
t = []
N0 = []
N1 = []
N2 = []
N3 = []
D0 = []
D1 = []
D2 = []
c = []
l = []
li = [] #100-l
xaxisLimit = 300 #cutoff for plotting data

# Reads in the input file and stores the relavent data.
with open(inputFile) as file:
	for line in file:
		line.replace(" ", "")
		t.append(float(line.split('|')[1]))
		N0.append(float(line.split('|')[2]))
		N1.append(float(line.split('|')[3]))
		N2.append(float(line.split('|')[4]))
		N3.append(float(line.split('|')[5]))
		D0.append(float(line.split('|')[6]))
		D1.append(float(line.split('|')[7]))
		D2.append(float(line.split('|')[8]))
		c.append(float(line.split('|')[9]))
		l.append(float(line.split('|')[10]))
		li.append(100.0-float(line.split('|')[10]))

#Plots N
fig, p = plt.subplots()
p.plot(t[0:xaxisLimit],N0[0:xaxisLimit],'k',label='Mother')
p.plot(t[0:xaxisLimit],N1[0:xaxisLimit],'k--',label='Daughter')
p.plot(t[0:xaxisLimit],N2[0:xaxisLimit],'k:',label='Granddaughter')
p.set_xlabel('Time (seconds)')
p.set_ylabel('Number of Nuclei')
legend = p.legend(loc='upper left', shadow=True, fontsize='x-large')

plt.show()	

#Plots D0
fig, p = plt.subplots()
p.plot(t[0:xaxisLimit],D0[0:xaxisLimit],'k',label='Mother')
p.plot(t[0:xaxisLimit],D1[0:xaxisLimit],'k--',label='Daughter')
p.set_xlabel('Time (seconds)')
p.set_ylabel('Decay Rate of Nuclei (Decays per Second)')
legend = p.legend(loc='lower right', shadow=True, fontsize='x-large')

plt.show()	

#Plots D0
fig, p = plt.subplots()
p.plot(t[0:xaxisLimit],c[0:xaxisLimit],'k',label='Contamination')
p.plot(t[0:xaxisLimit],l[0:xaxisLimit],'k--',label='Loss')
p.plot(t[0:xaxisLimit],li[0:xaxisLimit],'k:',label='100-Loss')
p.set_xlabel('Time (seconds)')
p.set_ylabel('Percentage')
legend = p.legend(loc='right', shadow=True, fontsize='x-large')

plt.show()	