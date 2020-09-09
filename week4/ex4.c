#include <stdlib.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	char com[1000];
	while(1){
		fgets(com, 1000, stdin);
		char *args[1000];
		for(int i = 0; i < 1000; i++){
			args[i]=NULL;
		}
		args[0] = malloc(1000 * sizeof(char));	
        int argnum = 0;
        int j = 0;
		for (int i = 0; i < 1000; i++){
            if (com[i] == '\n' || com[i] == '\0'){
                break;
            }
            else if (com[i] == ' '){
				j = 0;
                argnum += 1;
				args[argnum] = malloc(1000 * sizeof(char));
			}
			else{
				args[argnum][j] = com[i];
			}
		}
        if (strcmp(args[argnum], "&") == 0){
            int parentpid = (int)getpid();
            fork();
            if(parentpid != getpid()){
                execve(args[0], args, NULL);
            }
        }
        else{
            system(com);
        }
	}
	return 0;
}