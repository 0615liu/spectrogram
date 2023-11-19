#!/bin/bash
mkdir scp
gcc -o sinegen sinegen.c -lm  

./sinegen "16000" "16" "sine" "0" "100" "0.1" s1.wav
mv s1.wav scp

./sinegen 16000 16 sine 31.25 2000 0.1 s2.wav
mv s2.wav scp

./sinegen 16000 16 sine 500 1000 0.1 s3.wav
mv s3.wav scp 

./sinegen 16000 16 sine 2000 500 0.1 s4.wav
mv s4.wav scp

./sinegen 16000 16 sine 4000 250 0.1 s5.wav
mv s5.wav scp

./sinegen 16000 16 sine 44 100 0.1 s6.wav
mv s6.wav scp

./sinegen 16000 16 sine 220 2000 0.1 s7.wav
mv s7.wav scp

./sinegen 16000 16 sine 440 1000 0.1 s8.wav
mv s8.wav scp

./sinegen 16000 16 sine 1760 500 0.1 s9.wav
mv s9.wav scp

./sinegen 16000 16 sine 3960 250 0.1 s10.wav
mv s10.wav scp

./sinegen 16000 16 sawtooth 0 100 0.1 s11.wav
mv s11.wav scp

./sinegen 16000 16 sawtooth 31.25 2000 0.1 s12.wav
mv s12.wav scp

./sinegen 16000 16 sawtooth 500 1000 0.1 s13.wav
mv s13.wav scp 

./sinegen 16000 16 sawtooth 2000 500 0.1 s14.wav
mv s14.wav scp

./sinegen 16000 16 sawtooth 4000 250 0.1 s15.wav
mv s15.wav scp

./sinegen 16000 16 sawtooth 44 100 0.1 s16.wav
mv s16.wav scp

./sinegen 16000 16 sawtooth 220 2000 0.1 s17.wav
mv s17.wav scp

./sinegen 16000 16 sawtooth 440 1000 0.1 s18.wav
mv s18.wav scp

./sinegen 16000 16 sawtooth 1760 500 0.1 s19.wav
mv s19.wav scp

./sinegen 16000 16 sawtooth 3960 250 0.1 s20.wav
mv s20.wav scp

./sinegen 16000 16 square 0 100 0.1 s21.wav
mv s21.wav scp

./sinegen 16000 16 square 31.25 2000 0.1 s22.wav
mv s22.wav scp

./sinegen 16000 16 square 500 1000 0.1 s23.wav
mv s23.wav scp 

./sinegen 16000 16 square 2000 500 0.1 s24.wav
mv s24.wav scp

./sinegen 16000 16 square 4000 250 0.1 s25.wav
mv s25.wav scp

./sinegen 16000 16 square 44 100 0.1 s26.wav
mv s26.wav scp

./sinegen 16000 16 square 220 2000 0.1 s27.wav
mv s27.wav scp

./sinegen 16000 16 square 440 1000 0.1 s28.wav
mv s28.wav scp

./sinegen 16000 16 square 1760 500 0.1 s29.wav
mv s29.wav scp

./sinegen 16000 16 square 3960 250 0.1 s30.wav
mv s30.wav scp

./sinegen 16000 16 sine 0 100 0.1 s31.wav
mv s31.wav scp

./sinegen 16000 16 sine 31.25 2000 0.1 s32.wav
mv s32.wav scp

./sinegen 16000 16 sine 500 1000 0.1 s33.wav
mv s33.wav scp 

./sinegen 16000 16 sine 2000 500 0.1 s34.wav
mv s34.wav scp

./sinegen 16000 16 sine 4000 250 0.1 s35.wav
mv s35.wav scp

./sinegen 16000 16 sine 44 100 0.1 s36.wav
mv s36.wav scp

./sinegen 16000 16 sine 220 2000 0.1 s37.wav
mv s37.wav scp

./sinegen 16000 16 sine 440 1000 0.1 s38.wav
mv s38.wav scp

./sinegen 16000 16 sine 1760 500 0.1 s39.wav
mv s39.wav scp

./sinegen 16000 16 sine 3960 250 0.1 s40.wav
mv s40.wav scp


gcc -o cascade cascade.c -lm 
./cascade scp s-16k.wav
rm -r scp
mkdir scp

./sinegen 8000 16 sine 0 100 0.1 s1.wav
mv s1.wav scp

./sinegen 8000 16 sine 31.25 2000 0.1 s2.wav
mv s2.wav scp

./sinegen 8000 16 sine 500 1000 0.1 s3.wav
mv s3.wav scp 

./sinegen 8000 16 sine 2000 500 0.1 s4.wav
mv s4.wav scp

./sinegen 8000 16 sine 4000 250 0.1 s5.wav
mv s5.wav scp

./sinegen 8000 16 sine 44 100 0.1 s6.wav
mv s6.wav scp

./sinegen 8000 16 sine 220 2000 0.1 s7.wav
mv s7.wav scp

./sinegen 8000 16 sine 440 1000 0.1 s8.wav
mv s8.wav scp

./sinegen 8000 16 sine 1760 500 0.1 s9.wav
mv s9.wav scp

./sinegen 8000 16 sine 3960 250 0.1 s10.wav
mv s10.wav scp

./sinegen 8000 16 sawtooth 0 100 0.1 s11.wav
mv s11.wav scp

./sinegen 8000 16 sawtooth 31.25 2000 0.1 s12.wav
mv s12.wav scp

./sinegen 8000 16 sawtooth 500 1000 0.1 s13.wav
mv s13.wav scp 

./sinegen 8000 16 sawtooth 2000 500 0.1 s14.wav
mv s14.wav scp

./sinegen 8000 16 sawtooth 4000 250 0.1 s15.wav
mv s15.wav scp

./sinegen 8000 16 sawtooth 44 100 0.1 s16.wav
mv s16.wav scp

./sinegen 8000 16 sawtooth 220 2000 0.1 s17.wav
mv s17.wav scp

./sinegen 8000 16 sawtooth 440 1000 0.1 s18.wav
mv s18.wav scp

./sinegen 8000 16 sawtooth 1760 500 0.1 s19.wav
mv s19.wav scp

./sinegen 8000 16 sawtooth 3960 250 0.1 s20.wav
mv s20.wav scp

./sinegen 8000 16 square 0 100 0.1 s21.wav
mv s21.wav scp

./sinegen 8000 16 square 31.25 2000 0.1 s22.wav
mv s22.wav scp

./sinegen 8000 16 square 500 1000 0.1 s23.wav
mv s23.wav scp 

./sinegen 8000 16 square 2000 500 0.1 s24.wav
mv s24.wav scp

./sinegen 8000 16 square 4000 250 0.1 s25.wav
mv s25.wav scp

./sinegen 8000 16 square 44 100 0.1 s26.wav
mv s26.wav scp

./sinegen 8000 16 square 220 2000 0.1 s27.wav
mv s27.wav scp

./sinegen 8000 16 square 440 1000 0.1 s28.wav
mv s28.wav scp

./sinegen 8000 16 square 1760 500 0.1 s29.wav
mv s29.wav scp

./sinegen 8000 16 square 3960 250 0.1 s30.wav
mv s30.wav scp

./sinegen 8000 16 sine 0 100 0.1 s31.wav
mv s31.wav scp

./sinegen 8000 16 sine 31.25 2000 0.1 s32.wav
mv s32.wav scp

./sinegen 16000 16 sine 500 1000 0.1 s33.wav
mv s33.wav scp 

./sinegen 8000 16 sine 2000 500 0.1 s34.wav
mv s34.wav scp

./sinegen 8000 16 sine 4000 250 0.1 s35.wav
mv s35.wav scp

./sinegen 8000 16 sine 44 100 0.1 s36.wav
mv s36.wav scp

./sinegen 8000 16 sine 220 2000 0.1 s37.wav
mv s37.wav scp

./sinegen 8000 16 sine 440 1000 0.1 s38.wav
mv s38.wav scp

./sinegen 8000 16 sine 1760 500 0.1 s39.wav
mv s39.wav scp

./sinegen 8000 16 sine 3960 250 0.1 s40.wav
mv s40.wav scp
rm -r scp
gcc -o cascade cascade.c -lm 
./cascade scp s-8k.wav
mkdir tmp
gcc -o spectrogram spectrogram.c -lm  
 
# setting1 s-8k
./spectrogram 0.032 rectangular 0.032 0.01 s-8kHz.wav s-8kHz.set1.txt
python3 spectshow.py s-8kHz.set1.txt s-8kHz.wav s-8kHz.set1.pdf
mv tmp s-16kHz.set1.txt 

# setting1 s-16k
./spectrogram 0.032 rectangular 0.032 0.01 s-16kHz.wav s-16kHz.set1.txt
python3 spectshow.py s-16kHz.set1.txt s-16kHz.wav s-16kHz.set1.pdf
mv tmp s-16kHz.set1.txt

# setting1 aeueo-8kHz
./spectrogram 0.032 rectangular 0.032 0.01 aeueo-8kHz.wav aeueo-8kHz.set1.txt
python3 spectshow.py aeueo-8kHz.set1.txt aeueo-8kHz.wav aeueo-8kHz.set1.pdf
mv tmp s-16kHz.set1.txt

# setting1 aeueo-16kHz
./spectrogram 0.032 rectangular 0.032 0.01 aeueo-16kHz.wav aeueo-16kHz.set1.txt
python3 spectshow.py aeueo-16kHz.set1.txt aeueo-16kHz.wav aeueo-16kHz.set1.pdf
mv tmp s-16kHz.set1.txt

# setting2 s-16k
./spectrogram 0.032 hamming 0.032 0.01 s-16kHz.wav s-16kHz.set2.txt
python3 spectshow.py s-16kHz.set2.txt s-16kHz.wav s-16kHz.set2.pdf
mv tmp s-16kHz.set2.txt

# setting2 s-8k
./spectrogram 0.032 hamming 0.032 0.01 s-8kHz.wav s-8kHz.set2.txt
python3 spectshow.py s-8kHz.set2.txt s-8kHz.wav s-8kHz.set2.pdf
mv tmp s-16kHz.set2.txt
 
# setting2 aeueo-16kHz
./spectrogram 0.032 hamming 0.032 0.01 aeueo-16kHz.wav aeueo-16kHz.set2.txt
python3 spectshow.py aeueo-16kHz.set2.txt aeueo-16kHz.wav aeueo-16kHz.set2.pdf
mv tmp s-16kHz.set2.txt

# setting2-aeueo-8kHz
./spectrogram 0.032 hamming 0.032 0.01 aeueo-8kHz.wav aeueo-8kHz.set2.txt
python3 spectshow.py aeueo-8kHz.set2.txt aeueo-8kHz.wav aeueo-8kHz.set2.pdf
mv tmp s-16kHz.set2.txt

# setting3 s-16k
./spectrogram 0.03 rectangular 0.032 0.01 s-16kHz.wav s-16kHz.set3.txt
python3 spectshow.py s-16kHz.set3.txt s-16kHz.wav s-16kHz.set3.pdf
mv tmp s-16kHz.set3.txt

# setting3 s-8k
./spectrogram 0.03 rectangular 0.032 0.01 s-8kHz.wav s-8kHz.set3.txt
python3 spectshow.py s-8kHz.set3.txt s-8kHz.wav s-8kHz.set3.pdf
mv tmp s-16kHz.set3.txt

# setting3 aeueo-16kHz
./spectrogram 0.03 rectangular 0.032 0.01 aeueo-16kHz.wav aeueo-16kHz.set3.txt
python3 spectshow.py aeueo-16kHz.set3.txt aeueo-16kHz.wav aeueo-16kHz.set3.pdf
mv tmp s-16kHz.set3.txt

# setting3 aeueo-8kHz
./spectrogram 0.03 rectangular 0.032 0.01 aeueo-8kHz.wav aeueo-8kHz.set3.txt
python3 spectshow.py aeueo-8kHz.set3.txt aeueo-8kHz.wav aeueo-8kHz.set3.pdf
mv tmp s-16kHz.set3.txt

# setting4 s-16k
./spectrogram 0.03 hamming 0.032 0.01 s-16kHz.wav s-16kHz.set4.txt
python3 spectshow.py s-16kHz.set4.txt s-16kHz.wav s-16kHz.set4.pdf
mv tmp s-16kHz.set4.txt

# setting4 s-8k
./spectrogram 0.03 hamming 0.032 0.01 s-8kHz.wav s-8kHz.set4.txt
python3 spectshow.py s-8kHz.set4.txt s-8kHz.wav s-8kHz.set4.pdf
mv tmp s-16kHz.set4.txt

# setting4 aeueo-16kHz
./spectrogram 0.03 hamming 0.032 0.01 aeueo-16kHz.wav aeueo-16kHz.set4.txt
python3 spectshow.py aeueo-16kHz.set4.txt aeueo-16kHz.wav aeueo-16kHz.set4.pdf
mv tmp s-16kHz.set4.txt

# setting4 aeueo-8kHz
./spectrogram 0.03 hamming 0.032 0.01 aeueo-8kHz.wav aeueo-8kHz.set4.txt
python3 spectshow.py aeueo-8kHz.set4.txt aeueo-8kHz.wav aeueo-8kHz.set4.pdf
mv tmp s-16kHz.set4.txt

rm -r tmp
