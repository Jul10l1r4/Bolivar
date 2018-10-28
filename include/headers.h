#ifndef HEADERS_H
#define HEADERS_H
#include <stdlib.h>
#include <string.h>
#include "mimetypes.h"

// Here is default for all headers
// errors, redirects and all responses http
// #########  For all arguments   ##########
// #1 - mimetype
// #2 - content

char *header(char *arg,char *arg1){
				// For initial part of response HTTP
				register char *begin = "HTTP/1.1 200 OK\r\nAccept-Ranges: bytes\r\nTransfer-Encoding: chunked\r\nCharset: UTF-8\r\nContent-Type: ";

				// Allocation space of memory
				register char *output = malloc(strlen(arg) + strlen(arg1) + strlen(begin));
				strcpy(output, begin);// HTTP ...
				strcat(output, arg);  // Content-type: ...
				strcat(output, arg1); // <!Doctype ...
				return output; // result of junction

				// Clearning memory allocated
				free(output);
				free(arg);
				free(arg1);
				free(begin);
}

// Function for get value mimetype
static const char *get_mime_type(char *filename){
    register char *dot = strrchr(filename, '.');
    if(dot){ // strrchar Locate last occurrence of character in string
        register mime_map *map = meme_types;
        while(map->extension){
            if(strcmp(map->extension, dot) == 0){
                return map->mime_type;
            }
            map++;
        }
    }
    return default_mime_type;
		// put here expression for free allocation of memory
}
#endif
