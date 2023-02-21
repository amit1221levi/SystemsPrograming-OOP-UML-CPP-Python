//
// Created by annag on 16/04/2022.
//
#include <string.h>
#include <stdio.h>
#include "AsciiArtTool.h"


#define FLAGS 1
#define SOURCE 2
#define TARGET 3
#define NUM_OF_FLAGS 2
#define INVERTED_FLAG "-i"
#define ENCODED_FLAG "-e"

char mapFunction(char c)
{
    if(c == '@'){
        return ' ';
    }
    else if(c == ' '){
        return '@';
    }
    else{
        return c;
    }
}

int main(int argc, char** argv)
{
    if (argc != 4){
        fprintf(stdout, "Usage: AsciiArtTool <flags> <source> <target>\n");
        return -1;
    }
    FILE* in_stream = fopen(argv[SOURCE],"r");
    if(!in_stream){
        fprintf(stderr, "SOURCE FILE ERROR\n");
        return -1;
    }
    FILE* out_stream = fopen(argv[TARGET],"w");
    if(!out_stream){
        fprintf(stderr, "TARGET FILE ERROR\n");
        fclose(in_stream);
        return -1;
    }
    char* flags[NUM_OF_FLAGS] = {INVERTED_FLAG,ENCODED_FLAG};

    RLEList asciiArtList = asciiArtRead(in_stream);

    if (!strcmp(argv[FLAGS], flags[0])) {
        RLEListMap(asciiArtList,mapFunction);
        asciiArtPrint(asciiArtList,out_stream);
    }
    else if(!strcmp(argv[FLAGS],flags[1])){
        asciiArtPrintEncoded(asciiArtList,out_stream);
    }
    fclose(in_stream);
    fclose(out_stream);
    RLEListDestroy(asciiArtList);
    return 0;
}
