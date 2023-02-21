//
// Created by annag on 16/04/2022.
//

#include <stdio.h>
#include <stdlib.h>

#include "/home/mtm/public/2122b/ex1/RLEList.h"
#include "AsciiArtTool.h"


RLEList asciiArtRead(FILE* in_stream)
{
    if(!in_stream){
        return NULL;
    }
    RLEList asciiList = RLEListCreate();
    if(!asciiList){
        return NULL;
    }
    char c = fgetc(in_stream);
    while (c != EOF){
        RLEListAppend(asciiList,c);
        c = fgetc(in_stream);
    }
    return asciiList;
}

RLEListResult asciiArtPrint(RLEList list, FILE *out_stream)
{
    if(!list || !out_stream){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEListResult result = RLE_LIST_SUCCESS ,*ptrResult = &result;
    int listLen = RLEListSize(list);
    for (int i = 0; i < listLen; ++i) {
        char c = RLEListGet(list,i,ptrResult);
        if(result != RLE_LIST_SUCCESS){
            return RLE_LIST_ERROR;
        }
        fputc(c, out_stream);
    }
    return RLE_LIST_SUCCESS;
}

RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream)
{
    if (!list || !out_stream) {
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEListResult result = RLE_LIST_SUCCESS , *ptrResult = &result;
    char* encodedList = RLEListExportToString(list,ptrResult);
    if(result != RLE_LIST_SUCCESS){
        return RLE_LIST_ERROR;
    }
    if(fputs(encodedList,out_stream) == EOF){
        free(encodedList);
        return RLE_LIST_ERROR;
    }
    free(encodedList);
    return RLE_LIST_SUCCESS;
}

