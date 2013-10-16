#ifndef _CAT_PNG_H_

unsigned char* getPng(const char * filename,int *width,int *height);
void getFlip(unsigned char *src,int w,int h,int r1,int c1,int tw,int th, unsigned char *dst);
void freePng(unsigned char *p);

#endif
