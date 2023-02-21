//
// Created by annag on 16/04/2022.
//

#ifndef RLELIST_ASCIIARTTOOL_H
#define RLELIST_ASCIIARTTOOL_H

#include <stdio.h>
#include "/home/mtm/public/2122b/ex1/RLEList.h"

/**
 * asciiArtRead: receives *FILE containing ascii art image, returns RLEList containing
 * the chars that make up the ascii art by their order of appearance.
 *
 * @param in_stream - *FILE containing an ascii art image.
 *
 * @return
 *NULL if a NULL was sent as a parameter
 * A new RLEList
 */
RLEList asciiArtRead(FILE* in_stream);

/**
 *asciiArtPrint: receives RLE list containing chars that make up an ascii art image
 * and print the image into a given *FILE
 *
 * @param list the RLE list that will be printed into a *FILE
 * @param out_stream *FILE the function will print into
 * @return RLE_LIST_ERROR if there was an error getting a characters from the RLE list
 * RLE_LIST_SUCCESS if printing was finished successfully
 */
RLEListResult asciiArtPrint(RLEList list, FILE *out_stream);

/**
 *asciiArtPrintEncoded: receives RLE list containing chars that make up an ascii art image,
 * encodes them and prints the result into a given *FILE
 *
 * @param list the RLE list to encode and print the result into a *FILE
 * @param out_stream the *FILE the function will print into
 * @return RLE_LIST_ERROR if there was an error while encoding the list or printing into the *FILE
 * RLE_LIST_SUCCESS if printing was finished successfully
 */
RLEListResult asciiArtPrintEncoded(RLEList list, FILE *out_stream);





#endif //RLELIST_ASCIIARTTOOL_H
