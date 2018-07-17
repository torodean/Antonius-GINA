#============================================================================
# Name        : MIAMain.cpp
# Author      : Antonius Torode
# Copyright   : This file can be used under the conditions of Antonius' 
#				 General Purpose License (AGPL).
# Description : MIA main Program Interface and Runner.
#============================================================================
# 
# This file is designed to be used with an output file of GINA.
# The GINA output file should have the first line removed for proper functionality.
# The outputs of this file are the values left on the implantation point after
# a full rotation of the tape. 
# 
#============================================================================

from __future__ import division
import numpy as np
import pylab as plt
import math as mth
from scipy.constants import pi

inputFile = 'input.txt'
outputFile = open('./output.txt', 'w+')

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

Thalf0 = 5.84            # halflife of the mother isotope.
Thalf1 = 7.43*60         # halflife of the daughter isotope.
Thalf2 = 10.18*60*60     # halflife of the granddaughter isotope.
threshold = 1.0e-15      # cutoff value for output file numbers.

lengthOfTape = 200.0     # length of total tape in tape station.
lengthOfRotation = 0.2   # lenght it takes for one rotation.

# Different thresholds to gather information about (must exist in the GINA output file).
contaminationThresholds = [0.909, 1.0,2.5, 3.389, 5.0,7.5,10.0,12.5,15.0,17.5,20.0,25.0,30.0,35.0,40.0,45.0,50.0,60.0]

i = 0 #i for index of wanted value

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

# Creates an output file and gives it a header.		
outputFile.write('c\tt\tN0\tN1\tN2\tD0\tD1\tD2\n')

# Loops over the different thresholds defined above.
for cont in contaminationThresholds:
	for element in c:
		if element < cont:
			i+=1
	print('Analysis for contamination threshold < {0:.3g}'.format(cont))
	
	# Print the starting values.
	print('\nStarting values...\n')
	print('t0 = {0:.3g}'.format(t[i]))
	print('N0 = {0:.3g}'.format(N0[i]))
	print('N1 = {0:.3g}'.format(N1[i]))
	print('N2 = {0:.3g}'.format(N2[i]))
	print('D0 = {0:.3g}'.format(D0[i]))
	print('D1 = {0:.3g}'.format(D1[i]))
	print('D2 = {0:.3g}'.format(D2[i]))

	# Defines the final time after rotating about itself.
	tf = lengthOfTape/lengthOfRotation*t[i]
	
	# Defines a step size to perform calculations over the time of the tape rotation.
	steps = 100
	stepSize = tf/steps
	
	# Performs the calculation step by step.
	for deltaT in range(1,steps):
		rN0 = N0[i]*np.exp(-np.log(2)*stepSize/Thalf0)
		rN1 = ((N0[i]-rN0) + N1[i])*np.exp(-np.log(2)*stepSize/Thalf1)
		rN2 = ((N1[i]-rN1) + (N0[i]-rN0) + N2[i])*np.exp(-np.log(2)*stepSize/Thalf2)
		rD0 = rN0*np.log(2)/Thalf0
		rD1 = rN1*np.log(2)/Thalf1
		rD2 = rN2*np.log(2)/Thalf2
		if deltaT == steps:
			break
		N0[i] = rN0
		N1[i] = rN1
		N2[i] = rN2
		N0[i] = rD0
		D1[i] = rD1
		D2[i] = rD2
	
	# Applies the threshold cutoff.
	if rN0 < threshold:
		rN0 = 0.0
	if rN1 < threshold:
		rN1 = 0.0
	if rN2 < threshold:
		rN2 = 0.0
	if rD0 < threshold:
		rD0 = 0.0
	if rD1 < threshold:
		rD1 = 0.0
	if rD2 < threshold:
		rD2 = 0.0

	# Prints the final results.
	print('\nFull rotation residue...\n')
	print('tf = {0:.3g}'.format(tf))
	print('rN0 = {0:.3g}'.format(rN0))
	print('rN1 = {0:.3g}'.format(rN1))
	print('rN2 = {0:.3g}'.format(rN2))
	print('rD0 = {0:.3g}'.format(rD0))
	print('rD1 = {0:.3g}'.format(rD1))
	print('rD2 = {0:.3g}'.format(rD2))
	
	#Saves the results to the output file.
	outputFile.write('{0:.3g}\t{1:.3g}\t{2:.3g}\t{3:.3g}\t{4:.3g}\t{5:.3g}\t{6:.3g}\t{7:.3g}\n'.format(cont,tf,rN0,rN1,rN2,rD0,rD1,rD2))
	i = 0

# Closes the output file.
outputFile.close()