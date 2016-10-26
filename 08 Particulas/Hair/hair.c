#include <ri.h>
#include <math.h>
#include <stdlib.h>

#define COUNT 1000
#define JITTER(SCALE) (((rand()%1000)/500.0-1)*SCALE)

int main(int argc, char *argv[]) 
{
	RtPoint position[COUNT*4];
	RtInt nverts[COUNT];
	RtColor red={1,0,0}; float curveWidth=0.3; float fov=30;
	int i;
	/*Generate Curve Postions*/ 
	for(i=0;i<COUNT;i++)
	{
		float tx =(sin(i*0.3)*i*50)/COUNT + JITTER(5);
		float ty =(cos(i*0.3)*i*50)/COUNT + JITTER(5);
		position[i*4 + 0][0]= 0; position[i*4 + 0][1]= 0; position[i*4 + 0][2]= 50;
		position[i*4 + 1][0]= 0.1*tx; position[i*4 + 1][1]= 0.1*ty; position[i*4 + 1][2]= 25;
		position[i*4 + 2][0]= 0.4*tx; position[i*4 + 2][1]= 0.4*ty; position[i*4 + 2][2]= 0;
		position[i*4 + 3][0]= tx; position[i*4 + 3][1]= ty; position[i*4+3][2]=-25;
		nverts[i]= 4; 
	}
	RiBegin(RI_NULL);
	RiDisplay ((RtToken)"curves.tiff",(RtToken)"file",(RtToken)"rgba",RI_NULL); 
	RiProjection ((RtToken)"perspective","fov",&fov,RI_NULL);
    RiWorldBegin();
		RiTranslate(0,0,200); 
		RiColor(red); 
		RiRotate(45,1,0,0); 
		RiCurves((RtToken)"linear",COUNT,nverts,(RtToken)"nonperiodic","P",position,"constantwidth",&curveWidth,RI_NULL);
    RiWorldEnd();
RiEnd();
return 0; }