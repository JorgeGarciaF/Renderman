//
//  main.c
//  prueba
//
//  Created by Jorge Garcia on 07/10/16.
//  Copyright (c) 2016 Mugetsu. All rights reserved.
//

#include <ri.h>
#if INTPTR_MAX == INT64_MAX
// 64-bit
#elif INTPTR_MAX == INT32_MAX
// 32-bit
#else
#error Unknown pointer size or missing size macros!
#endif


int main(int argc, char *argv[])
{
	static RtFloat fov = 45, intensity = 0.5;
    static RtFloat Ka = 1.0, Kd = 0.5, Ks = 0.5;
    static RtPoint from = {0,0,1}, to = {0,10,0};
    static RtColor color = { .6, .9, .3};
    RiBegin(RI_NULL);
    RiDisplay ((RtToken)"Esfera.tiff",(RtToken) "file", (RtToken)"rgb", RI_NULL);
    RiProjection ((RtToken)"perspective", RI_NULL);
    RiWorldBegin();
    RiLightSource ((RtToken)"ambientlight", "intensity", &intensity,RI_NULL);
    RiLightSource ((RtToken)"distantlight", "from", from, "to", to, RI_NULL);
    RiSurface ((RtToken)"paintedplastic", "Ka", &Ka, "Kd", &Kd, "Ks", &Ks, RI_NULL);
    RiColor(color);
    RiTranslate(0,0,2);
    RiSphere(1,-1,1,360,RI_NULL);
    RiWorldEnd();
    RiEnd();
    return 0;
}