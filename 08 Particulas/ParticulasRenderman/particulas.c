#include <ri.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 1000
#define JITTER(SCALE) (((rand()%1000)/500.0-1)*SCALE)

int main(int argc, char *argv[]) {
	RtPoint position[COUNT];
	RtColor red={1,0,0};
	float fov=30; int i;
	/*Generate Particle Postions*/
	for(i = 0;i<COUNT;i++) 
	{
		position[i][0]= sin(i*0.5)*50 + JITTER(2); position[i][1]= cos(i*0.1)*50 + JITTER(2); position[i][2]= cos(i*0.5)*100 + JITTER(2); 
	}
RiBegin(RI_NULL);
RiDisplay ((RtToken)"point.tiff",(RtToken)"file",(RtToken)"rgba",RI_NULL); 
RiProjection ((RtToken)"perspective","fov",&fov,RI_NULL);
    RiWorldBegin();
		RiTranslate(0,0,300);
		RiColor(red);
		RiPoints(COUNT, "P", position, RI_NULL);
    RiWorldEnd();
RiEnd();
return 0; }