#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

void file(){
	printf("syntax : add-nbo <file1> <file2>\n");
	printf("sample : add-nbo a.bin c.bin\n");
}

uint32_t fileRead(char* filename){
	FILE* fp = fopen(filename, "rb");

	uint32_t n;
	size_t readLen = fread(&n, 1, sizeof(n), fp);
	n = ntohl(n);
	fclose(fp);
	return n;
}

int main(int argc, char* argv[]){
	if(argc != 3){
		file();
		exit(EXIT_FAILURE);
	}

	uint32_t n1 = fileRead(argv[1]);
	uint32_t n2 = fileRead(argv[2]);
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", n1, n1, n2, n2, n1 + n2, n1 + n2);
}
