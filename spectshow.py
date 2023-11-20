import re
import sys
import numpy as np
import matplotlib.pyplot as plt
from scipy.io.wavfile import read
#to import the function
fig = plt.figure(figsize=(20,8))
plt.subplot(2,1,1)
plt.title("WAVEFORM")
fs,y = read(sys.argv[2])
# to figure the plot
Namexticks = 5
firstx = np.linspace(0,len(y),Namexticks)
secondy = ["{:.2f}".format(i) for i in np.linspace(0,len(y)/fs,Namexticks)]
plt.xticks(firstx,secondy)
plt.ylabel("amplitude (strength) ")
plt.xlabel("time (second)")
#to label x y axis
plt.plot(y)
plt.subplot(2,1,2)
plt.title("spectrogram")
fp = open(sys.argv[1],'r')
#to open the file
long = fp.readlines()
a = re.split(' ',long[0])
# to cut the empty
spec = np.zeros((len(a),len(long)))
for i in range(len(long)):
    long[i] = long[i].strip()
    a = re.split(' ',long[i])
    for j in range(len(a)):
        if(int(a[j])>0):
            spec[j][i] = int(a[j])
        elif((int(a[j])<=0)):
            spec[j][i] = 0      
sampling = len(y)
samplingrate = fs
#to let samplerate
T=sampling/samplingrate
plt.imshow(np.transpose(spec),cmap='gray') # picture color,owing spectrogram color usually be gray
# to plot x label
Namexticks = 10
firstx = np.linspace(0,spec.shape[0],Namexticks)
secondx = ["{:.2f}".format(i) for i in np.linspace(0,T,Namexticks)]
plt.xticks(firstx,secondx)
plt.xlabel("time (second)")
Nameyticks = 6
# frequencysample would be 8000 16000
if(fs==16000):
    N = 512                                                                     
elif(fs==8000):
    N = 256
firsty = np.linspace(N*0.5,0,Nameyticks)
secondy = ["{:.2f}".format(i) for i in np.linspace(0,samplingrate*0.5,Nameyticks)]
plt.yticks(firsty,secondy)
plt.ylabel("frequency (hertz)")
fig.figure.savefig(sys.argv[3])

#make sure unit
# make by liu-chia-wei 411086030
