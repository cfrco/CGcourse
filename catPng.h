#ifndef _CAT_PNG_H_

unsigned char* getPng(const char * filename,int *width,int *height);
void freePng(unsigned char *p);

#endif
