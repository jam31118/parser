#include <cstdio>
#include <cstring>
#include <cctype>

#define BUFSIZE 1000

bool hasOnlyWhitespaces(char *str) {
	int len = strlen(str);
//	fprintf(stdout, "len: %d\n", len);
	char *p = NULL;
	char *p_max = str + len;
	for (p=str; p<p_max; p++) {
//		fprintf(stdout, "char: %c\n", *p);
		if ( isspace(*p) == false ) { return false; }
	}
	return true;
}

const char *comment_str = "//";


bool hasCommentCharacter(char *str) {
	if ( strstr(str, comment_str) == NULL ) {
		return false;
	} else {
		return true;
	}
};

bool isComment(char *str) {
	char str_copy[BUFSIZE];
	strcpy(str_copy, str);

	if ( hasCommentCharacter(str_copy) ) {
		char *str_before_comment_str = strtok(str_copy, comment_str);
		if ( hasOnlyWhitespaces(str_before_comment_str) ) { return true; } 
	}
	return false;
}

int main() {
	char s[BUFSIZE] = " \t  // hihi ";
	
	if ( strstr(s, comment_str) == s ) {
		fprintf(stdout, "first is comment str\n");
	} else {
		fprintf(stdout, "first is not comment str\n"); }

	char *tok = strtok(s, comment_str);
	fprintf(stdout, "tok: %s\n", tok);
	return 1;

	if (isComment(s)) { fprintf(stdout, "this is a comment: %s\n", s); }
	else { fprintf(stdout, "this isn't a comment: %s\n", s); }

	char *token = NULL;
	token = strtok(s, "#");
	printf("token: %s\n",token);
	if ( strcmp(token, s) == 0 ) {
		fprintf(stdout, "same!\n");
		fprintf(stdout, "s1: %s\n", token);
		fprintf(stdout, "s2: %s\n", s);
	} else { fprintf(stdout, "not same!\n"); }

	while ( token != NULL ) {
	if ( hasOnlyWhitespaces(token) == true ) {
		fprintf(stdout, "hehe\n");
	} else {
		fprintf(stdout, "hihi\n");
	}
	token = strtok(NULL, "a");
	}
	return 0;
}
