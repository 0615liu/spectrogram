#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979

typedef struct WAVEHEADER  //creatr structure 
{
    char ChunkID[4];
    int ChunkSize;
    char Format[4];
    char SubChunk1ID[4];
    int SubChunk1Size;
    short AudioFormat;
    short NumChannels;
    int SampleRate;
    int ByteRate;
    short BlockAlign;
    short BitsPerSample;
    char SubChunk2ID[4];
    int SubChun2Size;
} WavHeader;
 
int main(int argc, char *argv[])
{
    WavHeader MMSP;
    char *endptr;
    int i;
    int fs = atoi(argv[1]);
    int m = atoi(argv[2]);
    char *wavetype = argv[3];
    int f = atoi(argv[4]);
    double A = atof(argv[5]); //amplitude from 0 to 1 ->decimal
    double T = atof(argv[6]); // argc argv generate dynamic input
    size_t N = (size_t)(T * fs);
    /*-------------------------------------------------------------*/

    unsigned char *sinl8 = (unsigned char *)malloc(sizeof(unsigned char) * N);
    short *sinl16 = (short *)malloc(sizeof(short) * N);
    int *sinl32 = ( int *)malloc(sizeof(int) * N);
    double *a = (double *)malloc(sizeof(double) * N);

    int sampleRate = fs;  
    double frequency = f;
    int numSamples = N;

        if (strcmp(wavetype, "sine") == 0) // m=16 sine
        {
            for (int i = 0; i < N; i++)
            {
                double tmp = A * sin(2 * PI * f * i / fs);  
                sinl16[i] = (int)floor(tmp + 0.5); //quantize
                a[i] = tmp;
                 // printf("%lf\n", tmp); //try to print the value of sine
            }
        }

        else if (strcmp(wavetype, "square") == 0) // m=16 square
        {
            for (int i = 0; i < N; i++)
            {
                double t = (double)i / sampleRate; //sampling
                double tmp = A * ((t * frequency - floor(0.5 + t * frequency) < 0.0) ? -1.0 : 1.0); //square formula
                sinl16[i] = (int)floor(tmp + 0.5); //quantize
                a[i] = tmp;
                // printf("%lf\n",tmp);  //try to print the value of square
            }
        }
        else if (strcmp(wavetype, "triangle") == 0) // m=16 triangle
        {
            for (int i = 0; i < N; i++)
            {
                double t = (double)i / sampleRate; //sampling
                double tmp = A * (1.0 - 4.0 * fabs(fmod(t * frequency + 0.75, 1.0) - 0.5));
                sinl16[i] = (int)floor(tmp + 0.5); //quantize
                a[i] = tmp;
                //  printf("%lf\n", tmp);  //try to print the value of triangle
            }
        }

        else if (strcmp(wavetype, "sawtooth") == 0) // m=16 sawtooth
        {
            for (int i = 0; i < N; i++)
            {
                double t = (double)i / sampleRate; //sampling
                double tmp = A * (2.0 * (t * frequency - floor(0.5 + t * frequency)));
                sinl16[i] = (int)floor(tmp + 0.5); //quantize
                a[i] = tmp;
                // printf("%lf\n", tmp); //try to print the value of sawtooth
            }
        }
    

    FILE *fp;
    char *fn = argv[7];
    fp = fopen(fn, "wb"); // open a file pointer to save a binary file
    if (!fp)
    {
        fprintf(stderr, "Cannot save %s\n", fn);
        return 0;
    }

    MMSP.ChunkID[0] = 'R';  //Resource Interchange File Format
    MMSP.ChunkID[1] = 'I';
    MMSP.ChunkID[2] = 'F';
    MMSP.ChunkID[3] = 'F';
    MMSP.ChunkSize = N * (m / 8) + 36;
    MMSP.Format[0] = 'W'; 
    MMSP.Format[1] = 'A';
    MMSP.Format[2] = 'V';
    MMSP.Format[3] = 'E';
    MMSP.SubChunk1ID[0] = 'f';
    MMSP.SubChunk1ID[1] = 'm';
    MMSP.SubChunk1ID[2] = 't';
    MMSP.SubChunk1ID[3] = ' ';
    MMSP.SubChunk1Size = 16;
    MMSP.AudioFormat = 1;       //PCM=1 means linearization
    MMSP.NumChannels = 1;       //mono
    MMSP.SampleRate = fs;       //SampleRate 8000、44100
    MMSP.ByteRate = fs * m / 8; //SampleRate*NumChannels*m/8
    MMSP.BlockAlign = 4;        //BlockAlign=NumChannels X BitsPerSample/8   could be 4
    MMSP.BitsPerSample = m;
    MMSP.SubChunk2ID[0] = 'd';
    MMSP.SubChunk2ID[1] = 'a';
    MMSP.SubChunk2ID[2] = 't';
    MMSP.SubChunk2ID[3] = 'a';
    MMSP.SubChun2Size = N * (m / 8);  //Samplesize*NumChannels*m/8
    fwrite(&MMSP.ChunkID, sizeof(char), 4, fp);
    fwrite(&MMSP.ChunkSize, sizeof(int), 1, fp);
    fwrite(&MMSP.Format, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChunk1ID, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChunk1Size, sizeof(int), 1, fp);
    fwrite(&MMSP.AudioFormat, sizeof(short), 1, fp);
    fwrite(&MMSP.NumChannels, sizeof(short), 1, fp);
    fwrite(&MMSP.SampleRate, sizeof(int), 1, fp);
    fwrite(&MMSP.ByteRate, sizeof(int), 1, fp);
    fwrite(&MMSP.BlockAlign, sizeof(short), 1, fp);
    fwrite(&MMSP.BitsPerSample, sizeof(short), 1, fp);
    fwrite(&MMSP.SubChunk2ID, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChun2Size, sizeof(int), 1, fp);
 
    fclose(fp);  //close file
}
 
 // make by liu-chia-wei 411086030