#include <cstdio>

#define BUFSIZE 1000

int check_fgets(char *fgets_status, char *line, FILE *fp) {
	if ( fgets_status == NULL ) {
		if ( feof(fp) ) {
			fprintf(stdout, "[ LOG ] End-of-File reached\n");
		} else if ( ferror(fp) ) {
			fprintf(stderr, "[ERROR] Error during fgets()\n");
			return 1;
		} else {
			fprintf(stderr, "[ERROR] Unexpected case with NULL status");
			return 1;
		}
	} else if ( fgets_status == line ) {
		fprintf(stdout, "Input line: %s\n", line);
	} else {
		fprintf(stderr, "[ERROR] Unexpected case with non-NULL status\n");
		return 1;
	}
	return 0;
}


int main() {
	FILE *fp = fopen("input.config", "r");
	if ( fp == NULL ) { 
		fprintf(stderr, "[ERROR] Failed to fopen()\n"); return 1; }
	
	char *fgets_status = NULL;
	char line[BUFSIZE];

//	fgets_status = fgets(line, BUFSIZE, fp);
//	if ( check_fgets(fgets_status, line, fp) != 0 ) {
//		fprintf(stdout, "[ERROR] Failed to fgets()\n");
//		return 1;
//	}

	do {
		fgets_status = fgets(line, BUFSIZE, fp);
		if ( check_fgets(fgets_status, line, fp) != 0 ) {
			fprintf(stdout, "[ERROR] Failed to fgets()\n"); return 1;	}
	} while ( feof(fp) == false ); 

	fclose(fp);
}
