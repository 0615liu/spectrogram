#include <stdio.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#define PI 3.14159265359
typedef struct WAVE   
{
    char chunkID[4];
    int  ChunkSize;
    char Format[4];
    char SubChunk1ID[4];
    int SubChunk1Size;
    short AudioFormat;
    short numChannels;
    int SampleRate;
    int ByteRate;
    short BlockAlign;
    short BitsPerSample;
    char SubChunk2ID[4];
    int SubChun2Size;
} Headerwav;

int cascadingfunction(int filnums,short*datatmp)
{
    int total=0;    int end;    int tmpsize;
    for (int filptr = 1; filptr <= filnums; filptr++)
    {
        char min4name[100];
        sprintf(min4name, "s%d.wav", filptr); 
        FILE *input  = fopen(min4name, "rb");
        if (!input)
        {
            fprintf(stderr, "not open %s\n", min4name);
            continue;
        }

        fseek(input ,24,SEEK_SET);
        int tgee;
        fread(&end,1,sizeof(int),input); 
        int seeking;
        fseek(input ,44,SEEK_SET);

        for(int i=0;i<(end/10);i++)
        {
            short tmp;
            fread(&tmp,1,sizeof(short),input ); 
            datatmp[total]=tmp;
            total=total+1;
        }

        fclose(input);
    }
    return end;
}

int main(int argc, char *argv[])
{
    char cushion[128];
    getcwd(cushion,128);
    Headerwav MMSP;
    chdir(argv[1]);
    int cascadecalulating;
    int N = 64000; 
    short *datatmp = (short *)malloc(sizeof(short) * N);
    int fs = cascadingfunction(40,datatmp);
    N = 4*fs;

    MMSP.chunkID[0] = 'R';
    MMSP.chunkID[1] = 'I';
    MMSP.chunkID[2] = 'F';
    MMSP.chunkID[3] = 'F';
    MMSP.ChunkSize = (16/ 8)*N + 36;
    MMSP.Format[0] = 'W';
    MMSP.Format[1] = 'A';
    MMSP.Format[2] = 'V';
    MMSP.Format[3] = 'E';
    MMSP.SubChunk1ID[0] = 'f';
    MMSP.SubChunk1ID[1] = 'm';
    MMSP.SubChunk1ID[2] = 't';
    MMSP.SubChunk1ID[3] = ' ';
    MMSP.SubChunk1Size = 16;
    MMSP.AudioFormat = 1;
    MMSP.numChannels = 1;
    MMSP.SampleRate = fs;       
    MMSP.ByteRate = fs * 16 / 8; 
    MMSP.BlockAlign = 2;
    MMSP.BitsPerSample = 16;
    MMSP.SubChunk2ID[0] = 'd';
    MMSP.SubChunk2ID[1] = 'a';
    MMSP.SubChunk2ID[2] = 't';
    MMSP.SubChunk2ID[3] = 'a';
    MMSP.SubChun2Size = N * (16 / 8); 

    chdir(cushion);
    char *fn = argv[2];
    FILE *fp;
    
    fp = fopen(fn, "wb");
    if (!fp)
    {
        fprintf(stderr, "no saving for the data %s\n", fn);
    }

    fwrite(&MMSP.chunkID, sizeof(char), 4, fp);
    fwrite(&MMSP.ChunkSize, sizeof(int), 1, fp);
    fwrite(&MMSP.Format, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChunk1ID, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChunk1Size, sizeof(int), 1, fp);
    fwrite(&MMSP.AudioFormat, sizeof(short), 1, fp);
    fwrite(&MMSP.numChannels, sizeof(short), 1, fp);
    fwrite(&MMSP.SampleRate, sizeof(int), 1, fp);
    fwrite(&MMSP.ByteRate, sizeof(int), 1, fp);
    fwrite(&MMSP.BlockAlign, sizeof(short), 1, fp);
    fwrite(&MMSP.BitsPerSample, sizeof(short), 1, fp);
    fwrite(&MMSP.SubChunk2ID, sizeof(char), 4, fp);
    fwrite(&MMSP.SubChun2Size, sizeof(int), 1, fp);
    fwrite(datatmp, sizeof(short), N, fp);
}

// make by liu-chia-wei 411086030