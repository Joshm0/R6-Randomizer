#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ATTACK 38
#define DEFENCE 37
#define NAMELEN 20

int main() {
    
    char input[20] = {'\0'}, att[ATTACK][NAMELEN] = {'\0'},
        def[DEFENCE][NAMELEN] = {'\0'};
    int randnum = 0, i;
    FILE *att_file, *def_file;

    // Reads in ops and stores names within local array

    att_file = fopen("Att.txt", "r");
    def_file = fopen("Def.txt", "r");

    if (att_file == NULL || def_file == NULL) {
        printf("Check for Att.txt or Def.txt\n");
        return 1;
    }

    for (i = 0; i <= ATTACK; i++) {

        fgets(att[i], NAMELEN, att_file);

    }

    for (i = 0; i <= DEFENCE; i++) {

        fgets(def[i], NAMELEN, def_file);

    }

    fclose(att_file);
    fclose(def_file);

    // Starts psudorandom function based on user input
    srand(time(NULL));

    while(1) {

        fgets(input, 20, stdin);
        
        input[1] = '\0';

        if (!strcmp(input, "D") || !strcmp(input, "d")) {

            randnum = (rand() % (DEFENCE + 1));
            printf("Defence Operator: %s", def[randnum]);

        } else if (!strcmp(input, "A") || !strcmp(input, "a")) {

            randnum = (rand() % (ATTACK + 1));
            printf("Attack Operator: %s", att[randnum]);

        } else {

            printf("Input either \"A\" for attack or \"D\" for defense.\n");

        }
    }
    return 0;
}