
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *login_path = "build/registro.txt";

char *get_string(char *st)
{
    char *s = malloc(100);
    printf(st);
    if (fgets(s, 99, stdin))
    {
            char *p;
            if(p=strchr(s, '\n'))
            {//check exist newline
                *p = 0;
            } else {
                scanf("%*[^\n]");
                scanf("%*c");//clear upto newline
            }
        return s;
    }
    return s;
} 

int Search_in_File(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	
	//gcc users
	if((fp = fopen(fname, "r")) == NULL) {
		return(-1);
    }

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			//printf("A match found on line: %d\n", line_num);
			//printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if(find_result == 0) {		
        return(1);     
	}
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return(0);
}

void autenticacao()
{
    char *login = (char*)malloc(128);
    char *senha = (char*)malloc(128);

    login = get_string("Login: ");
    senha = get_string("Senha: ");

    char str[128];
    
    sprintf(str, "l%s, s%s", login, senha);
    
    
    if(Search_in_File(login_path, str) == 0)
    { 
        printf("Usuário autenticado com sucesso!.\n");
        system("build/PIM01");
    }
    else
    {
        printf("Usuário nào encontrado. \nInsira Login e Senha novamente.\n");
        autenticacao();
    }
    
    free(login);
    free(senha);
}

int main()
{
    printf("======================================\n");
    printf("=============AUTENTICACÃO=============\n");
    printf("======================================\n");

    autenticacao();
    return (0);
}