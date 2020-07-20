#include "add-nbo.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdint.h>
#include <stddef.h>

typedef union data{
	uint32_t uint32;
	uint8_t uint8[17];
}Data;

FILE* open(char *argv){
	FILE* f;

	f=fopen(argv,"rb");
	if(f==NULL){
		fputs("File Error", stderr);
		exit(1);
	}

	return f;
}

void extract(uint8_t *uint8, FILE* f){
	long size;
	size_t rsize;

	fseek(f,0,SEEK_END);
	size=ftell(f);
	rewind(f);

	rsize=fread(uint8,sizeof(unsigned char),17,f);
	if(rsize!=size){
		fputs("Reading Error", stderr);
		exit(3);
	}
}

uint32_t sum(uint32_t num1, uint32_t num2){
	return num1+num2;
}
