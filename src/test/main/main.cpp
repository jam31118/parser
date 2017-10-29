#include "parser.hpp"

#include <cstdio>

int stripTrailingComment(char *strWithComment);

typedef struct ConfigStringTuple {
	char name[BUFSIZE];
	char value_str[BUFSIZE];
	char type_str[BUFSIZE];
} ConfigStringTuple;

int parseLine(char *line, ConfigStringTuple *configStringTuple) {
	// [ DOC ] //
	// 
	
	if ( isComment(line) ) {
	
	} else {
		stripTrailingComment(line);
	}
	return 0;
}

int main() {
	FILE *fp = fopen("input.config", "r");
	if ( fp == NULL ) { fprintf(stderr, "[ERROR] Failed to fopen()\n"); }

	char *fgets_status = NULL;
	char line[BUFSIZE];

	do {
		fgets_status = fgets(line, BUFSIZE, fp);
		if ( check_fgets(fgets_status, line, fp) != 0 ) {
			fprintf(stdout, "[ERROR] Failed to fgets()\n"); return 1;	}

		if ( isComment(line) ) {
			fprintf(stdout, "It is comment: %s\n", line);
		} else {
			fprintf(stdout, "It isn't comment: %s\n", line);
		}
	} while ( feof(fp) == false ); 
}
