#include <stdio.h>
#include <stdlib.h>

/* If we are compiling on Windows compile these functions */
#if defined(WIN32) || defined(_WIN64)
#include <string.h>

static char buffer[2048];

/* Fake readline functions */
char* readline(char* prompt) {
	fputs(prompt, stdout);
	fgets(buffer, 2048, stdin);
	char* cpy = malloc(strlen(buffer)+1);
	strcpy(cpy, buffer);
	cpy[strlen(cpy)-1] = '\0';
	return cpy;
}

/* Fake add_history function */
void add_history(char* unused) {}


#else

#include <editline/readline.h>

#endif

int main(int argc, char** argv) {
	/* Print version and exit information */
    puts("Clisp version 0.0.0\n");
    puts("Press Ctrl+c to Exit\n");

    while(1) {
    	/*Output our prompt and get input */
        char* input = readline("Clisp> ");

        /*Add input to history */
        add_history(input);

        /* Echo input back to user*/
        printf("%s \n",input);

        /* Free retrieved input */
        free(input);
    }

    return 0;
}
