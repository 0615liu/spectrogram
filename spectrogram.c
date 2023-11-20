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

struct RIfunction
{
    double realpart;
    double imaginepart;
    double sigma;
};
//create real imagine part
struct RIfunction multipler(struct RIfunction x, struct RIfunction y) //x for real y for imagine part
{
    struct RIfunction cmp;
    cmp.realpart = x.realpart * y.realpart - x.imaginepart * y.imaginepart;
    cmp.imaginepart = x.realpart * y.imaginepart + x.imaginepart * y.realpart;
    //cmp.sigma=x.real* y.real * x.imagine * y.imagine;
    return cmp;
}
// in order to real imagine multipler and sigma
struct RIfunction adder(struct  RIfunction x, struct RIfunction y) 
{
    struct RIfunction cmp;
    cmp.realpart = x.realpart + y.realpart;
    cmp.imaginepart = x.imaginepart + y.imaginepart;
    //cmp.sigma=x.real+ y.real + x.imagine + y.imagine;
    return cmp;
}

/*calculate multipler adder in real and imagine*/
double absfunction(struct RIfunction x);
void discreteforuiertransform(struct RIfunction* x, int N);
void ShortTimeFT(struct RIfunction* input, int input_size, int analysis_size,int window_size, int hop_size,int **X,char *windowtype,float *hamwnd);

int main(int argc, char *argv[])
{
    
    Headerwav MMSP;  
    FILE *headerfile;
    headerfile=fopen(argv[5],"rb");  
    fread(MMSP.chunkID,sizeof(char),4,headerfile);                        
    fread(&MMSP.ChunkSize,sizeof(int),1,headerfile);
    fread(MMSP.Format,sizeof(char),4,headerfile);
    fread(MMSP.SubChunk1ID,sizeof(char),4,headerfile);
    fread(&MMSP.SubChunk1Size,sizeof(int),1,headerfile);
    fread(&MMSP.AudioFormat,sizeof(short),1,headerfile);
    fread(&MMSP.numChannels,sizeof(short),1,headerfile);
    fread(&MMSP.SampleRate,sizeof(int),1,headerfile);
    fread(&MMSP.ByteRate,sizeof(int),1,headerfile);
    fread(&MMSP.BlockAlign,sizeof(short),1,headerfile);
    fread(&MMSP.BitsPerSample,sizeof(short),1,headerfile);
    fread(MMSP.SubChunk2ID,sizeof(char),4,headerfile);
    fread(&MMSP.SubChun2Size,sizeof(short),1,headerfile);

    fseek(headerfile, 44, SEEK_SET);

    int N = (MMSP.ChunkSize)/2-18;
    struct RIfunction* input = malloc(sizeof(struct RIfunction) * N);
    for (int i = 0; i < N; i++) 
    {
        short tmp;
        fread(&tmp,sizeof(short),1,headerfile);
        input[i].realpart = tmp;
    }

    int hammingsize;
    int sizeestimate = MMSP.SampleRate * atof(argv[1]);
    int sizewindow = MMSP.SampleRate * atof(argv[3]); 
    int hanningsize; 
    int sizejump = MMSP.SampleRate * atof(argv[4]);  

    FILE *spectrogram = fopen(argv[6],"w");
    int  frames = (N - sizewindow) / sizejump + 1;
    int **X = (int**) malloc(  frames * sizeof(int*));
    float *hammingwindow = (float *) calloc(sizeof(float), sizewindow) ;

    float rad;
    if (X == NULL) 
    {
        printf("Memory distribute unsuccess.\n");
    }
    else
    {
        printf("Memory distribute success.\n");
    }
    int indexnumber;
    if(MMSP.SampleRate==16000)
    {
       indexnumber=512;
    }
    else if(MMSP.SampleRate==8000)
    {
        indexnumber=256;
    }

    for (int i=0;i<frames;i++)
    {
        X[i] = (int*) malloc( indexnumber* sizeof(int));
    }    

    
    for(int i=0;i<=sizewindow-1;i++) 
    {
        rad  = 2.0 * PI * ((float) i) / ((float) (sizewindow-1) );
        hammingwindow[i] = 0.54 - 0.46 * cos( rad );//hamming function formula
    }

    ShortTimeFT(input, N, sizeestimate,sizewindow, sizejump,X,argv[2],hammingwindow);
    if(MMSP.SampleRate==16000)    //two case for samplerate 16000 8000
    {
        for (int j=255;j>=0;j--)  //256-1
        {
          for (int i=0;i< frames;i++)
          {
            fprintf(spectrogram,"%d ",X[i][j]);
        }
        fprintf(spectrogram,"\n");
        }
    }
    else if(MMSP.SampleRate==8000)
    {
        for (int j=127;j>=0;j--)  //128-1
        {
          for (int i=0;i< frames;i++)
          {
            fprintf(spectrogram,"%d ",X[i][j]);
          }
        fprintf(spectrogram,"\n");
        }
    }
    fclose(spectrogram);
}



void discreteforuiertransform(struct RIfunction* x, int N) 
{
    struct RIfunction* result = calloc(N, sizeof(struct RIfunction));
    if (result == NULL) 
    {
        printf("Memory distribute failed.\n");
    }

    for (int i = 0; i <= N-1; i++) 
    {
        for (int j = 0; j <= N-1; j++) 
        {
            double phase = -2 * (PI * i * j )/ N;
            struct RIfunction cs;
            cs.imaginepart = sin(phase);
            cs.realpart = cos(phase);
            result[i] = adder(result[i], multipler(x[j], cs));
        }
    }

    for (int i = 0; i <=N-1; i++) 
    {
        x[i] = result[i];
    }
    free(result);
}

double absfunction(struct RIfunction x) 
{
    return sqrt( x.imaginepart * x.imaginepart + x.realpart * x.realpart);  //square roots to calculate the abs
}

void ShortTimeFT(struct RIfunction* input, int sizeinput, int sizeestimate,int sizewindow, int sizejump,int **X,char *windowtype,float *hamming)
{
    int fragments = ((sizeinput - sizewindow) / sizejump)+ 1; 
    if (sizewindow > sizeinput) 
    {
        printf("Window to big.\n");
    }
    int hammingrate;
    int windowhamminsize;
    for (int i = 0; i <= fragments-1; i++) 
    {
        struct RIfunction* interval = malloc(sizeof(struct RIfunction) * sizewindow);

        if (interval == NULL) 
        {
            printf("Memory distribute error.\n");
        }

        for (int j = 0; j < sizeestimate; j++)
        {
            interval[j] = input[i * sizejump + j];
        }
        for (int j = sizeestimate; j < sizewindow; j++) 
        {
            interval[j].realpart = 0.0;
            interval[j].imaginepart = 0.0;
        }

        if (strcmp(windowtype,"hamming")==0)
        {
            for (int j = 0; j < sizewindow; j++) 
            {
                interval[j] = input[i * sizejump + j];
                interval[j].realpart *=hamming[j];
            }
        }

        discreteforuiertransform(interval, sizewindow);
        for (int j = 0; j < sizewindow; j++) 
        {
            double strength = absfunction(interval[j]);
            double strengthsize = 20*log(strength);
            X[i][j] = (int)strengthsize;
        }
        free(interval);
    }
}

// make by liu-chia-wei 411086030