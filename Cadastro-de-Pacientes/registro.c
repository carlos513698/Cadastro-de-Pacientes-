#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *login_path = "build/registro.txt";

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

void novo_registro()
{
    char *login = (char*)malloc(128);
    char *senha = (char*)malloc(128);

    login = get_string("Login: ");
    senha = get_string("Senha: ");

    if (Search_in_File(login_path, login) == 1)
    {
        FILE *login_file = fopen(login_path, "a"); 
    
        fprintf(login_file, "l%s, s%s\n", login, senha);
        free(login);
        free(senha);
        fclose(login_file);
        printf("Cadastro realizado com sucesso!\n");
        system("build/menu");
    }
    else
    {
        printf("O usuário já existe. \n");
        free(login);
        free(senha);
        novo_registro();
    }
    
}

int main()
{   
    printf("======================================\n");
    printf("===============REGISTRO===============\n");
    printf("======================================\n");
    
    novo_registro();

    return 0;
}