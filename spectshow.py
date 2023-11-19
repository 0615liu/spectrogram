import re
import sys
import numpy as np
import matplotlib.pyplot as plt
from scipy.io.wavfile import read

fig = plt.figure(figsize=(20,8))
plt.subplot(2,1,1)
plt.title("waveform")
fs,y = read(sys.argv[2])
Nxticks = 5
x1 = np.linspace(0,len(y),Nxticks)
x2 = ["{:.2f}".format(i) for i in np.linspace(0,len(y)/fs,Nxticks)]
plt.xticks(x1,x2)
plt.xlabel("time (second)")
plt.ylabel("amplitude ")
plt.plot(y)
plt.subplot(2,1,2)
plt.title("spectrogram")
fp = open(sys.argv[1],'r')
line = fp.readlines()
a = re.split(' ',line[0])
spec = np.zeros((len(a),len(line)))
for i in range(len(line)):
    line[i] = line[i].strip()
    a = re.split(' ',line[i])
    for j in range(len(a)):
        if(int(a[j])>0):
            spec[j][i] = int(a[j])
        else:
            spec[j][i] = 0      
sample = len(y)
sample_rate = fs
time=sample/sample_rate
plt.imshow(np.transpose(spec),cmap='gray') # picture color
Nxticks = 10
x1 = np.linspace(0,spec.shape[0],Nxticks)
x2 = ["{:.2f}".format(i) for i in np.linspace(0,time,Nxticks)]
plt.xticks(x1,x2)
plt.xlabel("time (second)")
Nyticks = 6
if(fs==16000):
    N = 512                                                                     //頻率
elif(fs==8000):
    N = 256
y1 = np.linspace(N/2,0,Nyticks)
y2 = ["{:.2f}".format(i) for i in np.linspace(0,sample_rate/2,Nyticks)]
plt.yticks(y1,y2)
plt.ylabel("frequency (HZ)")
fig.figure.savefig(sys.argv[3])

# make by liu-chia-wei 411086030
