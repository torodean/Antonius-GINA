###################################
# Nuclear Decay Models
# Michigan State University - NSCL
# Created By: Antonius Torode
# Date: May 2017
###################################

######################
# Some general imports
######################

from __future__ import division 	#1)
import numpy as np			#2)
import pylab as plt			#3)
import math as mth			#4)
from scipy.constants import pi		#5)

#1) Import floating point division which allows python 2 compatibility.
#2) Imports the numerical library for performing simple calculations.
#3) Imports the plotting library for making graphs.
#4) ives math functions such as floor and ceil.
#5) Imports some constants as a variable.

######################
# End general imports
######################



###########################
# Declare Initial Variables
###########################

#HL_m = Half-life of mother nuclei.
#HL_d = Half-life of daughter nuclei.
#HL_gd = Half-life of granddaughter not yet implemented.

#Test Case 1:
#HL_m=2.6
#HL_d=38.4

#Test Case 2: Zn76 -> Ga76
HL_m=5
HL_d=60

R=1000 # Sets the constant rate of radioactive particles (particles/second).
T=100 # Sets the total time of the run (seconds).
T_cut = 10 #Sets the total time before resetting the particle count

# Sets the time to increment by (seconds) 
#Smaller values => more accurate data but slower runtimes.
del_t=.1

size=int(mth.ceil(T/del_t)) # Determines how many time steps will be used.

t=[] #Creates an empty list to increment time.
N_m=[] # Creates an empty list for the mother nuclei numbers.
N_d=[] # Creates an empty list for the daughter nuclei numbers.
N_gd=[] # Creates an empty list for the daughter-daughter nuclei numbers.

N_t=[] #keeps track of the total amount of particles implanted. 
B_l=[] #for recording the ratio of particles decayed to total implanted.
B_h=[] #Records the number of particles alive from the initial beam.

D_m=[] #Creates an empty list for storing the m decay values.
D_d=[] #Creates an empty list for storing the d decay values.
C=[] #Creates an empty list for storing the contamination values.

D2_m=[] #Creates an empty list for storing the m decay values.
D2_d=[] #Creates an empty list for storing the d decay values.
C2=[] #Creates an empty list for storing the contamination values.


#Fill the arrays created above.
for i in range(0,size):
       t.append(0)
for i in range(0,size):
       N_m.append(0)
for i in range(0,size):
       N_d.append(0)
for i in range(0,size):
       N_gd.append(0)

for i in range(0,size):
       N_t.append(0)
for i in range(0,size):
       B_l.append(0)
for i in range(0,size):
       B_h.append(0)

for i in range(0,size):
       D_m.append(0)
for i in range(0,size):
       D_d.append(0)
for i in range(0,size):
       C.append(0)

for i in range(0,size):
       D2_m.append(0)
for i in range(0,size):
       D2_d.append(0)
for i in range(0,size):
       C2.append(0)

#Sets the initial conditions.
N_m[0]=0
N_m[1]=R*del_t
N_d[0]=0
N_d[1]=0
N_gd[0]=0
N_gd[1]=0
N_t[0]=0
N_t[1]=N_m[1]

###########################
# End Initial Variables
###########################



#############
# Program
#############

#See documentation for explanation of these equations.

#Calculation of particle number
for n in range(2,size):
	N_t[n]=n*R*del_t
	N_m[n]=N_m[1]+N_m[n-1]*np.exp(-del_t*np.log(2)/HL_m)
	N_d[n]=N_m[n-1]*(1-np.exp(-del_t*np.log(2)/HL_m))+N_d[n-1]*np.exp(-del_t*np.log(2)/HL_d)
	N_gd[n]=N_gd[n-1]+N_d[n-1]*(1-np.exp(-del_t*np.log(2)/HL_d))

#Calculation of decay rate (devided by del_t to make the units per second)
for n in range(0,size):
	D_m[n]=N_m[n]*(1-np.exp(-del_t*np.log(2)/HL_m))/del_t
	D_d[n]=N_d[n]*(1-np.exp(-del_t*np.log(2)/HL_d))/del_t
	if D_m[n] > 0:
		C[n]=D_d[n]/D_m[n]*100
	t[n]=n*del_t

#Alternate calculation of decay rate
for n in range(0,size):
	D2_m[n]=N_m[n]*np.log(2)/HL_m
	D2_d[n]=N_d[n]*np.log(2)/HL_d
	if D2_m[n] > 0:
		C2[n]=D2_d[n]/D2_m[n]*100	

#Determines the Beam loss and Health
for n in range(1,size):
	B_l[n] = 100*(N_d[n]+N_gd[n])/(N_t[n])
	B_h[n]=100-B_l[n]

#############
# End Program
#############



##############
# Analysis
##############

#Plots Radioactive Particle # vs Time
plt.title('Radioactive Particle # vs Time')
plt.plot(t, N_m, '-b', label='Mother (%s)'%HL_m)
plt.plot(t, N_d, '-r', label='Daughter (%s)'%HL_d)
plt.plot(t, N_gd, '-g', label='Granddaughter')
plt.xlabel("time (seconds)")
plt.ylabel("Radioactive particle #")
plt.legend(loc='upper left')
plt.show()

#Plots Decay Rate vs Time  (Method I)
#plt.title('Decay Rate vs Time')
#plt.plot(t, D_m, '-b', label='Mother')
#plt.plot(t, D_d, '-r', label='Daughter')
#plt.xlabel("time (seconds)")
#plt.ylabel("Radioactive Decay # per second")
#plt.legend(loc='right')
#plt.show()

#Plots Decay Rate vs Time (Method II)
plt.title('Decay Rate (%s) vs Time'%R)
plt.plot(t, D2_m, '-b', label='Mother (%s)'%HL_m)
plt.plot(t, D2_d, '-r', label='Daughter (%s)'%HL_d)
plt.xlabel("time (seconds)")
plt.ylabel("Radioactive Decays per second")
plt.legend(loc='lower right')
plt.show()

#Plots Contamination vs Time (Method I)
#plt.title('Contamination vs Time')
#plt.plot(t, C, '-b', label='Contamination')
#plt.xlabel("time (seconds)")
#plt.ylabel("Contamination %")
#plt.show()

#Plots Contamination & Beam Health vs Time (Method II)
plt.title('Contamination & Beam Health % vs Time')
plt.plot(t, C2, '-b', label='Contamination')
plt.plot(t, B_l, '-r', label='Beam Loss')
plt.plot(t, B_h, '-g', label='Beam Health')
plt.xlabel("time (seconds)")
plt.ylabel("Contamination %")
plt.legend(loc='center right')
plt.show()

##############
# End Analysis
##############








