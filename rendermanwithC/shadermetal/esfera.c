//
//  main.c
//  prueba
//
//  Created by Jorge Garcia on 07/10/16.
//  Copyright (c) 2016 Mugetsu. All rights reserved.
//

#include <ri.h>

int main(int argc, char *argv[])
{
	static RtFloat fov = 45, intensity = 0.5;
    static RtFloat Ka = 1.0, Ks = 1.0;
    static RtPoint from = {0,0,1}, to = {0,10,0};
    static RtColor blue = { .0, .0, .9};
    RiBegin(RI_NULL);
    RiDisplay ((RtToken)"Esfera.tiff",(RtToken) "file", (RtToken)"rgb", RI_NULL);
    RiProjection ((RtToken)"perspective", RI_NULL);
    RiWorldBegin();
    RiLightSource ((RtToken)"ambientlight", "intensity", &intensity,RI_NULL);
    RiLightSource ((RtToken)"distantlight", "from", from, "to", to, RI_NULL);
    RiSurface ((RtToken)"metal", "Ka", &Ka, "Ks", &Ks, RI_NULL);
    RiColor(blue);
    RiTranslate(0,0,2);
    RiSphere(1,-1,1,360,RI_NULL);
    RiWorldEnd();
    RiEnd();
    return 0;
}