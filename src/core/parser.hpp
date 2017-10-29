#ifndef _PARSER_H_
#define _PARSER_H_

#include <cstdio>
#include <cstdio>
#include <cstring>
#include <cctype>

#define BUFSIZE 256

int parse(const char *filename);

const char *comment_str = "#";

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

bool hasOnlyWhitespaces(char *str) {
	int len = strlen(str);
	char *p = NULL;
	char *p_max = str + len;
	for (p=str; p<p_max; p++) {
		if ( isspace(*p) == false ) { return false; }
	}
	return true;
}

bool isComment(char *str) {
	char *comment_str_position = strstr(str, comment_str);
	bool hasCommentChar = ( comment_str_position != NULL );
	
	if ( hasCommentChar ) {
		bool startsFromCommentChar = ( comment_str_position == str );
		if ( startsFromCommentChar ) { return true; }
		else {
			char str_copy[BUFSIZE];
			strcpy(str_copy, str);
			char *strBeforeCommentChar = strtok(str_copy, comment_str);
			if ( hasOnlyWhitespaces(strBeforeCommentChar) ) { return true; }
		}
	}
	return false;
}
#endif // _PARSER_H_
