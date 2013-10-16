#include<png++/png.hpp>
#include<cstdlib>

unsigned char* getPng(const char * filename,int *width,int *height) {
    png::image< png::rgba_pixel > image(filename);
    int w = image.get_width();
    int h = image.get_height();
    unsigned char *buffer = (unsigned char *)malloc(w*h*4);

    int r,c,t,k;
    for(r=0;r<h;++r){
        t = r*w*4;
        for(c=0;c<w;++c){
            k = t+c*4;
            png::rgba_pixel pix = image.get_pixel(c,r);
            buffer[k] = pix.red;
            buffer[k+1] = pix.green;
            buffer[k+2] = pix.blue;
            buffer[k+3] = pix.alpha;
        }
    }

    *width = w;
    *height = h;

    return buffer;
}

#include<stdio.h>
void getFlip(unsigned char *src,int w,int h,int r1,int c1,int tw,int th, unsigned char *dst) {
    int r,c,t,k = 0;

    for(r=0;r<th;++r) {
        for(c=0;c<tw;++c) {
            t = ((r1+r)*w+c1+c)*4;
            dst[k++] = src[t];
            dst[k++] = src[t+1];
            dst[k++] = src[t+2];
            dst[k++] = src[t+3];
        } 
    }
} 

void freePng(unsigned char *p) {
    free(p);
}
