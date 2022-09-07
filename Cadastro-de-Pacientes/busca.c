#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *cadastro_path = "build/cadastro.txt";

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

int isNumeric(const char *str)
{
    while(*str != '\0')
    {
        if(*str < '0' || *str > '9')
            return 0; // falso
        str++;
    }
    return 1; //verdadeiro
}

char* get_name(char *st, char *nome) //Retorna uma string, sendo validado se contém números
{
    char* tmp_nome = get_string(st);
    if (isNumeric(tmp_nome) == 0)
    {
        return tmp_nome;
    }
    else
    {   
        printf("%s inválido.\n", nome);
        get_name(st, nome);
    }    
}

char* get_cpf(char *st)
{
    char* cpf = get_string(st);
    char* cpf_= (char*)malloc(100);

    if (isNumeric(cpf) == 0)
    { 
        printf("CPF inválido: Não utilizar letras.\n");        
        get_cpf(st);
    }
    else if (strlen(cpf) < 11 || strlen(cpf) > 11)
    {
        printf("CPF inválido: Quantidade de dígitos incorreta.\n");       
        get_cpf(st);
    }
    else
    {
       sprintf(cpf_, "%c%c%c.%c%c%c.%c%c%c-%c%c", cpf[0],cpf[1],cpf[2],cpf[3],cpf[4],cpf[5],
        cpf[6],cpf[7],cpf[8],cpf[9],cpf[10],cpf[11]);      
        free(cpf);  
        return(cpf_);
    }
}

char *busca_em_arquivo(char *fname, char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char *temp = (char*)malloc(512);
	
	//gcc users
	if((fp = fopen(fname, "r")) == NULL) {
		return("-1");
    }

	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			printf("A match found on line: %d\n", line_num);
			printf("\n%s\n", temp);
            return temp;
			find_result++;
		}
		line_num++;
	}

	if(find_result == 0) {		
        return ("Paciente não cadastrado.");
	}
	
	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}   	
}

void nova_busca()
{
    char *nome = (char*)malloc(100);
    char *cpf = (char*)malloc(100);
    nome = get_name("Nome: ", "Nome");
    cpf = get_cpf("CPF (apenas números): ");
    char *dados_pac  = (char*)malloc(100);
    
    sprintf(dados_pac, "Nome: %s, CPF: %s,", nome, cpf);
    char *paciente = busca_em_arquivo(cadastro_path, dados_pac);

    free(nome);
    free(cpf);
    free(dados_pac);

    if (strcmp(paciente, "Paciente não cadastrado.") != 0)
    {        
        printf("Dados do paciente: %s", paciente);
        char *n_b = get_string("Nova busca? (y/n): ");
        if(strcmp(n_b,"y") == 0)
        {
            nova_busca();
        }
        else
        {
            printf("Encerrando programa...\n");            
        }
        
    }
    else
    {
        printf("Paciente não cadastrado. \n");        
        nova_busca();
    }   
}

int main()
{   
    printf("======================================\n");
    printf("===========PÁGINA DE BUSCA============\n");
    printf("======================================\n");
    
    nova_busca();

    return 0;
}