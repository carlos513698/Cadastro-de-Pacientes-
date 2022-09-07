//Arquivo contendo código referente ao PIM04
//Aqui será criado o código conforme sugerido.

//TODO: Anotar principais comandos do Git e GitHub
//Para poder manipular branches locais e remotos.

//Para iniciar o trabalho, é preciso fazer um pull
//a partir do GitHub, então criar um novo branch local,
//fazer um push de volta pra o GitHub, fazer as alteracões
//nesse branch e, por fim, fazer um merge de volta
//para o GitHub. Por fim, é necessário deletar os
//branches não utilizados.

//É necessário também buscar um tamplate para o
//Overleaf com as regras ABNT e buscra no AVA
//quais as exigências e recomendacões para o 
//PIM01.

//Para trabalhar com arquivos, utilizamos:
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *cadastro = "build/cadastro.txt";
const char *grupo_risco = "build/grupo_de_risco.txt";

char *limparbuffer(char *st)
{
    char *p;
    if(p=strchr(st, '\n'))
    {//check exist newline
        *p = 0;
    } else {
        scanf("%*[^\n]");
        scanf("%*c");//clear upto newline
    }        
    return st;
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

int *get_int(char *st)
{
    int *i = malloc(100*sizeof(int));
    printf(st);
    scanf("%d", &i);    
    fflush(stdin);
    return i;
}

typedef struct endereco
{
    char* rua;
    char* num;
    char* bairro;
    char* cidade;
    char* estado;
    char* cep;
}Endereco;

typedef struct paciente 
{    
    char *nome;
    char *cpf;
    char *telefone;
    Endereco *end;
    char *nasc;
    char *email;
    char *datadiag;
    char *comorbidade;
}Paciente;

char* get_date(char *st)
{    
    char* str = (char*)malloc(100);
    int *dd = malloc(2*sizeof(int));
    int *mm = malloc(2*sizeof(int));
    int *yy = malloc(4*sizeof(int));
    printf(st);
    scanf("%d/%d/%d",dd,mm,yy);
    
    //check year
    if(*yy>=1900 && *yy<=9999)
    {     
        //check month
        if(*mm>=1 && *mm<=12)
        {
            //check days
            if((*dd>=1 && *dd<=31) && (*mm==1 || *mm==3 || *mm==5 || *mm==7 || *mm==8 || *mm==10 || *mm==12))
            {
                
            }
            else if((*dd>=1 && *dd<=30) && (*mm==4 || *mm==6 || *mm==9 || *mm==11))
            {
                
            }
            else if((*dd>=1 && *dd<=28) && (*mm==2))
            {
               
            }
            else if(*dd==29 && *mm==2 && (*yy%400==0 ||(*yy%4==0 && *yy%100!=0)))
            {
               
            }
            else
            {
                printf("\n erro DIA \n");
                get_date(st);
            }
        }
        else
        {
            printf("\n erro MÊS \n");
            get_date(st);
        }
    }
    else
    {
        printf("\n erro ANO \n");
        get_date(st);
    }

    sprintf(str, "%d/%d/%d", *dd, *mm, *yy);     

    str = limparbuffer(str);

    return str;
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

char* get_fone(char *st)
{
    char* fone = get_string(st);
    char* fone_ = (char*)malloc(100);
    if (isNumeric(fone) == 0)
    { 
        printf("Número inválido: Não utilizar letras.\n");        
        get_fone(st);
    }
    else if (strlen(fone) != 11)
    {        
        printf("Telefone inválido: Número de dígitos: %d \n", strlen(fone));
        printf("O númeor deve conter 11 dígitos, por ex: (45) 9 1234-5678.\n");       
        get_cpf(st);
    }
    else
    {
       sprintf(fone_, "(%c%c) %c %c%c%c%c-%c%c%c%c"
       , fone[0],fone[1],fone[2],fone[3],fone[4],fone[5],
        fone[6],fone[7],fone[8],fone[9],fone[10],fone[11]);                
        return(fone_);
    }


}

char* get_email(char *st)
{
    char *pos_a = (char*)malloc(15);
    char *pos_b = (char*)malloc(20);
    char *email = (char*)malloc(20);

    printf(st);
    scanf("%s", email);

    for (int i = 0; i < 9; i++)
    {
        pos_a[i]=email[strlen(email)-9+i];
    }
    for (int i = 0; i < 11; i++)
    {
        pos_b[i]=email[strlen(email)-11+i];
    }

    if(strcmp(pos_a, "gmail.com") == 0 ||
        strcmp(pos_b, "hotmail.com") == 0 ||
        strcmp(pos_b, "outlook.com") == 0)
    {        
        return email;
    }
    else
    {
        printf("E-mail inválido: ");
        printf("Utilize `gmail.com/hotmail.com/outlook.com'");
        get_email(st);
    }
    
}

char* get_comorbidade(char *st)
{
    int c;
    printf(st);
    scanf("%1d", &c);

    switch (c)
    {
    case 1:
        return "diabetes";
        break;

    case 2:
        return "obesidade";
        break;

    case 3:
        return "hipertensão";
        break;

    case 4:
        return "tuberculose";
        break;

    case 5:
        return "outros;";
        break;

    case 6:
        return "não";
        break;
    
    default:
        printf("Opcão inválida.\n");
        get_comorbidade(st);
        break;
    }
}

char* get_cep(char *st)
{
    char* cp = get_string(st);
    char* cp_= (char*)malloc(100);

    if (isNumeric(cp) == 0)
    { 
        printf("CEP inválido: Não utilizar letras.\n");        
        get_cep(st);
    }
    else if (strlen(cp) < 8 || strlen(cp) > 8)
    {
        printf("CEP inválido: Quantidade de dígitos incorreta.\n");       
        get_cep(st);
    }
    else
    {
        sprintf(cp_, "%c%c%c%c%c-%c%c%c", cp[0],cp[1],cp[2],cp[3],cp[4],cp[5],
        cp[6],cp[7],cp[8]); 
        free(cp);
        return(cp_);
    }
}

char* get_num(char *st)
{
    char* num = get_string(st);

    if (isNumeric(num) == 0)
    { 
        printf("Número inválido: Não utilizar letras.\n");        
        get_num(st);
    }
    else
    {        
        return(num);
    }
}

int is_g_risc(char *comorb, char *nasc)
{
    char *aux = (char*)malloc(4*sizeof(char));
    int n;
    sprintf(aux, "%c%c%c%c", nasc[6], nasc[7], nasc[8], nasc[9]);
    sscanf(aux, "%d",&n);
    free(aux);
    if (strcmp(comorb, "não") == 0 && 2020 - n < 65)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

Endereco* get_end(char *st)
{
    printf("%s\n", st);
    Endereco* e = (Endereco*)malloc(sizeof(Endereco));
    e->rua = get_name("Rua: ", "Nome da rua");
    e->num = get_num("Número: ");
    e->bairro = get_name("Bairro: ", "Nome do bairro");
    e->cidade = get_name("Cidade: ", "Nome da cidade");
    e->estado = get_name("Estado: ", "Nome do estado");
    e->cep = get_cep("CEP: ");
    return e;
}

Paciente* novo_cadastro(void)
{
    Paciente* p = (Paciente*)malloc(sizeof(Paciente));      
    p->nome = get_name("Nome: ", "Nome");    
    p->cpf = get_cpf("CPF (apenas números): ");
    p->telefone = get_fone("Telefone com DD e apenas números: ");
    p->end = get_end("Preencha o endereco: ");
    p->nasc = get_date("Data de nascimento no formato (DD/MM/AAAA) ");
    p->email = get_email("E-mail: ");
    p->datadiag = get_date("Data do diagnóstico no formato (DD/MM/AAAA): ");
    p->comorbidade = get_comorbidade("Possui alguma comorbidade?\n 1. diabetes;\n 2. obesidade;\n 3. hipertensão;\n 4. tuberculose;\n 5. outros;\n 6. não.\n");
    return p;
}

void salva_cadastro(Paciente* p, const char *cadastro, const char *grisco)
{        
    int g_r = is_g_risc(p->comorbidade, p->nasc);
    if (g_r == 1)
    {
        FILE *gr = fopen(grisco, "a"); 
        fprintf(gr, "Nome: %s, CPF: %s, CEP: %s\n", p->nome, p->cpf, p->end->cep);
        fclose(gr);

    }
    FILE *cad = fopen(cadastro, "a");
    fprintf(cad, "Nome: %s, CPF: %s, Telefone: %s, Endereco:[rua: %s, número: %s, bairro: %s, cidade: %s, estado: %s, CEP: %s], Data de nascimento: %s, E-mail: %s, Data do diagnóstico: %s, Comorbidade: %s\n",        
        p->nome,
        p->cpf,
        p->telefone,
        p->end->rua,
        p->end->num,
        p->end->bairro,
        p->end->cidade,
        p->end->estado,
        p->end->cep,
        p->nasc,
        p->email,
        p->datadiag,
        p->comorbidade
    );
    fclose(cad);
}

int criar_cadastro(char *st)
{
    char *n_c = get_string(st);
    if (strcmp(n_c, "y") == 0)
    { 
        Paciente *nc = novo_cadastro();
        salva_cadastro(nc, cadastro, grupo_risco);
        printf("Cadastro salvo com sucesso!.\n");        
        criar_cadastro(st);
    }
    else if (strcmp(n_c, "n") == 0)
    {   
        printf("Fechando programa...\n");
        return 0;
    }
    else
    {
        printf("Dígito inválido. Digite 'y' para sim ou 'n' para não.\n");
        criar_cadastro(st);
    }   
}

int main(void)
{
    printf("======================================\n");
    printf("=========CADASTRO DE PACIENTE=========\n");
    printf("======================================\n");
    
    criar_cadastro("Novo cadastro? (y/n): \n");

    return 0;
    }