#include "add-nbo.h"
#include "add-nbo.cpp"
#include <arpa/inet.h>

int main(int argc, char* argv[]){

	if(argc<2){
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
                return 0;
	}
	
	FILE* f1;
	FILE* f2;
	Data data1;
	Data data2;
	uint32_t result;

	f1=open(argv[1]);
	f2=open(argv[2]);

	extract(data1.uint8, f1);
	extract(data2.uint8, f2);

	fclose(f1);
	fclose(f2);

	data1.uint32 = ntohl(data1.uint32);
	data2.uint32 = ntohl(data2.uint32);

	result = sum(data1.uint32, data2.uint32);

	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", data1.uint32, data1.uint32, data2.uint32, data2.uint32, sum, sum);

}
