#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int f[7][7]={0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,
                0,0,0,0,0,0,0};

    int kernel[3][3];
    int g[5][5]={0,0,0,0,0,
				0,0,0,0,0,
				0,0,0,0,0,
				0,0,0,0,0,
				0,0,0,0,0};
    int x,y;
	srand(time(NULL));

    for(x=1;x<=5;x++)
    for(y=1;y<=5;y++)
    f[x][y]=rand()%255;


    for(x=1;x<=7;x++){
        for(y=1;y<=7;y++){
            printf("%6d",f[x-1][y-1]);
        }
        printf("\n");
    }


    printf("\n***  kernel **\n");

    for(x=0;x<3;x++)
    for(y=0;y<3;y++)
    scanf("%d",&kernel[x][y]);

    int fSatir=0 , fSutun=0, sa1=3, su1=3 , i=0, r=0, z=0;
    int toplam=0;

    while(z<=7 && sa1<=7){
    	i=0;
    	while(i<7){
    		i=su1;

    		for(fSatir=z;fSatir<sa1; fSatir++){
    			for(fSutun=r;fSutun<su1;fSutun++){
    				toplam+=f[fSatir][fSutun]*kernel[fSatir][fSutun];
                    }
                }
                r++;
                g[z][r-1]=toplam;
                su1++;
                toplam=0;
            }
		z++;
		sa1++;
		su1=3;
		r=0;
	}

    int m;
    printf("\n");
    for(r=0;r<5;r++){
    	for(m=0;m<5;m++){
    		printf("%8d",g[r][m]);
		}
		printf("\n\n");
	}
}
