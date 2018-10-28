#ifndef SELECTNOW_H
#define SELECTNOW_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

char *autoselect(char *file,char *directory)
{
	DIR *d = opendir(directory);
	struct dirent *dp;
	
	register char *go = malloc(strlen(file) + strlen(directory) + 1);
	strcpy(go,directory);
	strcat(go,"/index.html");

	printf(directory);
//	return go;
	register FILE *f = fopen(go, "rb");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  //same as rewind(f);
//	return "a";
	register char *string = malloc(fsize);
	fread(string, fsize, 1, f);
	fclose(f);
	return string;
	//string[fsize] = 0;
	
}
#endif

