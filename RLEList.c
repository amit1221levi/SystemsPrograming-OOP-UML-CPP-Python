#include <stdlib.h>
#include "RLEList.h"


typedef enum {
    FIRST_ELEMENT = 0,
    SECOND_ELEMENT = 1,
    THIRD_ELEMENT = 2,
    NUM_OF_ELEMENTS = 3,
}dataElements;

struct RLEList_t{
    char character;
    int repetitions;
    struct RLEList_t* next;
};

static int log10Helper(int num)
{
    int log = 0;
    while (num >= 10){
        num /= 10;
        log += 1;
    }
    return log;
}

RLEList RLEListCreate()
{
    RLEList ptr = malloc(sizeof(*ptr));
    if (!ptr) {
        return NULL;
    }
    ptr->character = '\0';
    ptr->repetitions = 0;
    ptr->next = NULL;
    return ptr;
}

void RLEListDestroy(RLEList list)
{
    while(list){
        RLEList toDelete = list;
        list = list->next;
        free(toDelete);
    }
}

RLEListResult RLEListAppend(RLEList list, char value)
{
    if(!list){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList end = list;
    while(end->next){
        end = end->next;
    }
    if (end->character == value){
        end->repetitions++;
        return RLE_LIST_SUCCESS;
    }
    else{
        RLEList ptr = malloc(sizeof(*ptr));
        if (!ptr){
            return RLE_LIST_OUT_OF_MEMORY;
        }
        ptr->character = value;
        ptr->repetitions = 1;
        ptr->next = NULL;
        end->next = ptr;
        return RLE_LIST_SUCCESS;
    }
}

int RLEListSize(RLEList list)
{
    if(!list){
        return -1;
    }
    int totalNum = 0;
    RLEList end = list;
    while(end){
        totalNum += end->repetitions;
        end = end->next;
    }
    return totalNum;
}


RLEListResult RLEListRemove(RLEList list, int index)
{
    if(!list){
        return RLE_LIST_NULL_ARGUMENT;
    }
    else if(index < 0 || RLEListSize(list) == 0){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    RLEList currentNode = list->next, previousNode = list, PrePreviousNode = list;
    int currentIndex = 0;
    while(currentIndex < index && currentNode && currentNode->next){
        currentIndex += currentNode->repetitions;
        PrePreviousNode = previousNode;
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    if (currentIndex + currentNode->repetitions < index){
        return RLE_LIST_INDEX_OUT_OF_BOUNDS;
    }
    else if(index + 1 <= currentIndex){
        currentNode = previousNode;
        previousNode = PrePreviousNode;
    }
    if(currentNode->repetitions > 1){
        currentNode->repetitions--;
        return RLE_LIST_SUCCESS;
    }
    else{
        if(!currentNode->next || previousNode->character != currentNode->next->character){
            previousNode->next = currentNode->next;
            free(currentNode);
            return RLE_LIST_SUCCESS;
        }
        else{
            previousNode->repetitions += currentNode->next->repetitions;
            previousNode->next = currentNode->next->next;
            free(currentNode->next);
            free(currentNode);
            return RLE_LIST_SUCCESS;
        }
    }
}

char RLEListGet(RLEList list, int index, RLEListResult *result)
{
    RLEListResult temp = RLE_LIST_ERROR, *tempPtr = &temp, **ptr = &result;
    if(!result) {
        *ptr = tempPtr;
    }
    else if(!list){
        **ptr = RLE_LIST_NULL_ARGUMENT;
        return '\0';
    }
    RLEList currentNode = list->next;
    int i = -1;
    while(i < index && currentNode){
        if (index <= i + currentNode->repetitions){
            i += currentNode->repetitions;
            break;
        }
        else{
            i += currentNode->repetitions;
            currentNode = currentNode->next;
        }
    }
    if(index < 0 || i < index ){
        **ptr = RLE_LIST_INDEX_OUT_OF_BOUNDS;
        return '\0';
    }
    else {
        **ptr = RLE_LIST_SUCCESS;
        return currentNode->character;
    }
}

RLEListResult RLEListMap(RLEList list, MapFunction mapFunction)
{
    if(!list || !mapFunction){
        return RLE_LIST_NULL_ARGUMENT;
    }
    RLEList previousNode = list ,currentNode = list->next;
    while(currentNode) {
        char newCharacter = mapFunction(currentNode->character);
        if(previousNode->character == newCharacter){
            previousNode->repetitions += currentNode->repetitions;
            previousNode->next = currentNode->next;
            RLEList toDelete = currentNode;
            currentNode = currentNode->next;
            free(toDelete);
        }
        else{
            currentNode->character = newCharacter;
            previousNode = currentNode;
            currentNode = currentNode->next;
        }
    }

    return RLE_LIST_SUCCESS;
}

char* RLEListExportToString(RLEList list, RLEListResult* result)
{
    RLEListResult temp = RLE_LIST_ERROR, *tempPtr = &temp, **ptr = &result;
    if(!result) {
        *ptr = tempPtr;
    }
    if(!list){
        **ptr = RLE_LIST_NULL_ARGUMENT;
        return NULL;
    }
    list = list->next;
    int sizeOfMemory = 1;
    char* listToString = malloc(sizeOfMemory);
    if (!listToString){
        **ptr = RLE_LIST_ERROR;
        return NULL;
    }
    int numOfDigits = 0, i = 0;
    while(list){
        numOfDigits = log10Helper(list->repetitions);
        sizeOfMemory += numOfDigits + NUM_OF_ELEMENTS;
        listToString = realloc(listToString, sizeOfMemory);
        listToString[i + FIRST_ELEMENT] = list->character;
        sprintf((listToString + i + SECOND_ELEMENT),"%d",list->repetitions);
        listToString[i + numOfDigits + THIRD_ELEMENT] = '\n';
        i += numOfDigits + NUM_OF_ELEMENTS;
        list = list->next;
    }
    listToString[sizeOfMemory-1] = '\0';
    **ptr = RLE_LIST_SUCCESS;
    return listToString;
}

