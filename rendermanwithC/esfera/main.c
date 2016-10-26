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
    RiBegin(RI_NULL);
    RiDisplay ("min.tiff", "framebuffer", "rgb", RI_NULL);
    RiProjection ("perspective", RI_NULL);
    RiWorldBegin();
    RiTranslate(0,0,2);
    RiSphere(1,-1,1,360,RI_NULL);
    RiWorldEnd();
    RiEnd();
    return 0;
}