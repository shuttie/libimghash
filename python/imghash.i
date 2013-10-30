%module imghash
%{
#define SWIG_FILE_WITH_INIT
#include "imghash_c.h"
%}

extern unsigned long long imghash_buffer(char* buffer, int bufferSize);
extern unsigned long long imghash_file(char* fileName);
extern char* imghash_file_hex(char* fileName);
