#include <ri.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 2000
#define JITTER(SCALE) (((rand()%1000)/500.0-1)*SCALE)

int main(int argc, char *argv[]) {
	RtPoint position[COUNT];
	RtColor red={1,0,0};
	RtColor green={0,1,0}; float width[COUNT]; float constantwidth = 0.5; float fov=30;
	int i;
	/*Generate Particle Postions*/ 
	for(i=0;i<COUNT;i++)
	{
	position[i][0]= sin(i*0.5)*50 + JITTER(2); position[i][1]= cos(i*0.1)*50 + JITTER(2); position[i][2]=cos(i*0.5)*100+JITTER(2); width[i]= JITTER(0.5)+ 0.5;
	}
	RiBegin(RI_NULL);
	RiDisplay ((RtToken)"width.tiff",(RtToken)"file",(RtToken)"rgba",RI_NULL); 
	RiProjection ((RtToken)"perspective",(RtToken)"fov",&fov,RI_NULL);
    RiWorldBegin();
        RiTranslate(0,0,300);
        RiColor(red);
        RiPoints(COUNT/2,"P",position,"constantwidth", &constantwidth,RI_NULL);
        RiColor(green);
		RiPoints(COUNT/2,"P",position+COUNT/2, "width",width + COUNT/2,RI_NULL);
    	RiWorldEnd();
	RiEnd();
return 0; 
}