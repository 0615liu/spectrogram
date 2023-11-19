# mini-project-4 spectrogram
#DFT
void dft(int N,int table, float *x_re, float *x_im, float *X_re, float *X_im)
{

	int n, k;
	float tmp;

	int c,s;
	int TAB_N;
    float cos_t[1000];
    float sin_t[1000];

    //定義查表的點數
    if(table==16000)
    	TAB_N = 512;
    else if(table==8000)
    	TAB_N = 256;

    //make cos table
    for(c=0;c<=TAB_N;c++)
    	cos_t[c]=cos(2*PI*c/TAB_N);

    //make sin table
    for(s=0;s<=TAB_N;s++)
    	sin_t[s]=sin(2*PI*s/TAB_N);

	for(k=0;k<N/2+1;k++) {
		X_re[k] = 0;
		X_im[k] = 0;
		for(n=0;n<N;n++) {
			//real part of x[k]
			tmp = x_re[n] * cos_t[k*n%N];
			X_re[k] += tmp;

			//imaginary part of x[k]
			tmp = -x_re[n] * sin_t[k*n%N];
			X_im[k] += tmp;

			count+=8;
		}
		X_re[k] /= ((float)N);//縮小值的差距，讓圖變好看
		X_im[k] /= ((float)N);//
		count+=2;
	}
}
