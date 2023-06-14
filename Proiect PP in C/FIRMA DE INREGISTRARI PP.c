#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// structuri ============================================================================================
struct album
{
    char cod_album2[1024],titlu[1024],data[1024],copyright[1024],tip_format[1024];
};
struct instrument
{
    char nr_de_identificare[1024],nume[1024],cheie_muzicala[1024];
};
typedef struct muzician
{
    char cnp[1024],nume_si_prenume[1024],adresa[1024],telefon[1024];
    struct album album;
    struct instrument instrument;

}muzician;


void output_file(muzician *p,FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    fprintf(file_muzicieni,"\n%s | %s | %s | %s | %s | %s",p->cnp,p->nume_si_prenume,p->adresa,p->telefon,p->instrument.nume,p->album.cod_album2);
    fprintf(file_albume,"\n%s | %s | %s | %s | %s",p->album.cod_album2,p->album.titlu,p->album.data,p->album.copyright,p->album.tip_format);
    fprintf(file_instrumente,"\n%s | %s | %s",p->instrument.nr_de_identificare,p->instrument.nume,p->instrument.cheie_muzicala);
}


void afisare_node_muzicieni(muzician *p)
{
    printf("\n{--------------------");
    printf("\n CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
    printf("\n %s | %s | %s | %s | %s | %s\n",p->cnp,p->nume_si_prenume,p->adresa,p->telefon,p->instrument.nume,p->album.cod_album2);
    printf("\n Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
    printf("\n %s | %s | %s | %s | %s\n",p->album.cod_album2,p->album.titlu,p->album.data,p->album.copyright,p->album.tip_format);
    printf("\n Numar de identificare | Numele instrumentului | Cheie muzicala");
    printf("\n %s | %s | %s",p->instrument.nr_de_identificare,p->instrument.nume,p->instrument.cheie_muzicala);
    printf("\n{--------------------\n");
}
muzician citire_node_muzicieni(char *line_muzicieni,char *line_albume,char *line_instrumente)
{
    muzician *p = malloc(sizeof(muzician));
    sscanf(line_muzicieni,"%[^|] | %[^|] | %[^|] | %[^|] | %[^|] | %[^|\n]",p->cnp,p->nume_si_prenume,p->adresa,p->telefon,p->instrument.nume,p->album.cod_album2);
    sscanf(line_albume,"%[^|] | %[^|] | %[^|] | %[^|] | %[^|\n]",p->album.cod_album2,p->album.titlu,p->album.data,p->album.copyright,p->album.tip_format);
    sscanf(line_instrumente,"%[^|] | %[^|] | %[^|\n]",p->instrument.nr_de_identificare,p->instrument.nume,p->instrument.cheie_muzicala);
    return *p;
}


void afisare_node_muzicieni_solo(muzician *p)
{
    printf("\n%s - %s - %s - %s - %s - %s",p->cnp,p->nume_si_prenume,p->adresa,p->telefon,p->instrument.nume,p->album.cod_album2);
}
muzician citire_node_muzicieni_solo(char *line_muzicieni)
{
    muzician *p = malloc(sizeof(muzician));
    sscanf(line_muzicieni,"%[^|] | %[^|] | %[^|] | %[^|] | %[^|] | %[^|\n]",p->cnp,p->nume_si_prenume,p->adresa,p->telefon,p->instrument.nume,p->album.cod_album2);
    return *p;
}


void afisare_node_albume(struct album *a)
{
    printf("\n%s - %s - %s - %s - %s",a->cod_album2,a->titlu,a->data,a->copyright,a->tip_format);
}
struct album citire_node_albume(char *line_albume)
{
    struct album *a = malloc(sizeof(struct album));
    sscanf(line_albume,"%[^|] | %[^|] | %[^|] | %[^|] | %[^|\n]",a->cod_album2,a->titlu,a->data,a->copyright,a->tip_format);
    return *a;
}


void afisare_node_instrumente(struct instrument *i)
{
    printf("\n%s - %s - %s",i->nr_de_identificare,i->nume,i->cheie_muzicala);
}
struct instrument citire_node_instrumente(char *line_instrumente)
{
    struct instrument *i = malloc(sizeof(struct instrument));
    sscanf(line_instrumente,"%[^|] | %[^|] | %[^|\n]",i->nr_de_identificare,i->nume,i->cheie_muzicala);
    return *i;
}
// functii =============================================================================================
void proces_de_modificare(muzician *p,char *inlocuibil,char *modificare)
{
    if(strcmp(inlocuibil,"CNP")==0)
    {
        strcpy(p->cnp,modificare);
    }
    if(strcmp(inlocuibil,"NUME")==0)
    {
        strcpy(p->nume_si_prenume,modificare);
    }
    if(strcmp(inlocuibil,"ADRESA")==0)
    {
        strcpy(p->adresa,modificare);
    }
    if(strcmp(inlocuibil,"TELEFON")==0)
    {
        strcpy(p->telefon,modificare);
    }
    if(strcmp(inlocuibil,"NUME_INSTRUMENT")==0)
    {
        strcpy(p->instrument.nume,modificare);
    }
    if(strcmp(inlocuibil,"NR_DE_IDENTIFICARE")==0)
    {
        strcpy(p->instrument.nr_de_identificare,modificare);
    }
    if(strcmp(inlocuibil,"CHEIE_MUZICALA")==0)
    {
        strcpy(p->instrument.cheie_muzicala,modificare);
    }
    if(strcmp(inlocuibil,"TITLU_ALBUM")==0)
    {
        strcpy(p->album.titlu,modificare);
    }
    if(strcmp(inlocuibil,"COD_ALBUM")==0)
    {
        strcpy(p->album.cod_album2,modificare);
    }
    if(strcmp(inlocuibil,"COPYRIGHT")==0)
    {
        strcpy(p->album.copyright,modificare);
    }
    if(strcmp(inlocuibil,"DATA")==0)
    {
        strcpy(p->album.data,modificare);
    }
    if(strcmp(inlocuibil,"TIP_FORMAT")==0)
    {
        strcpy(p->album.tip_format,modificare);
    }
}


void creare_resetare(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
            int y=0,nr_input;
            printf("Cate input-uri avem?: ");
            scanf("%d", &nr_input);
            file_muzicieni = fopen("muzicieni.csv","w");
            file_albume = fopen("albume.csv","w");
            file_instrumente = fopen("instrumente.csv","w");
            fprintf(file_muzicieni, "CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
            fprintf(file_albume, "Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
            fprintf(file_instrumente, "Numar de identificare | Numele instrumentului | Cheie muzicala");
            muzician *muzicieni = malloc(sizeof(muzician)*nr_input);
            while(y<nr_input)
            {
                printf("CNP %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].cnp);

                printf("Nume si Prenume %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].nume_si_prenume);

                printf("Adresa %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].adresa);

                printf("Numarul de telefon %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].telefon);

                printf("Instrumentele folosite %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].instrument.nume);

                printf("Numarul de identificare a instrumentului %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].instrument.nr_de_identificare);

                printf("Cheia muzicala a instrumentului folosit %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].instrument.cheie_muzicala);

                printf("Titlul albumului %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].album.titlu);

                printf("Codul albumului %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].album.cod_album2);

                printf("Data aparitiei %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].album.data);

                printf("Detinatorul dreturilor de autor %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].album.copyright);

                printf("Tip format %d: ",y+1);
                getchar();
                scanf("%[^\n]",muzicieni[y].album.tip_format);

                fprintf(file_muzicieni, "\n%s | %s | %s | %s | %s | %s", muzicieni[y].cnp, muzicieni[y].nume_si_prenume, muzicieni[y].adresa, muzicieni[y].telefon, muzicieni[y].instrument.nume, muzicieni[y].album.cod_album2);
                fprintf(file_albume, "\n%s | %s | %s | %s | %s", muzicieni[y].album.cod_album2, muzicieni[y].album.titlu, muzicieni[y].album.data, muzicieni[y].album.copyright, muzicieni[y].album.tip_format);
                fprintf(file_instrumente, "\n%s | %s | %s", muzicieni[y].instrument.nr_de_identificare, muzicieni[y].instrument.nume, muzicieni[y].instrument.cheie_muzicala);
                y++;
            }
            fclose(file_muzicieni);
            fclose(file_albume);
            fclose(file_instrumente);
            printf("\n");
}
void afisare_generala(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        printf("=================================\n");
        for(int k=1 ; k<n ; k++)
        {
            afisare_node_muzicieni(&muzicieni[k]);
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
    printf("\n");
}
void append_general(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
            file_muzicieni = fopen("muzicieni.csv","a");
            file_albume = fopen("albume.csv","a");
            file_instrumente = fopen("instrumente.csv","a");
            if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
            {
                printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
            }
            else
            {
                int y=0,nr_input;
                printf("Cate input-uri avem?: ");
                scanf("%d", &nr_input);
                muzician *muzicieni = malloc(sizeof(muzician)*nr_input);
                while(y<nr_input)
                {
                    printf("CNP %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].cnp);

                    printf("Nume si Prenume %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].nume_si_prenume);

                    printf("Adresa %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].adresa);

                    printf("Numarul de telefon %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].telefon);

                    printf("Instrumentele folosite %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].instrument.nume);

                    printf("Numarul de identificare a instrumentului %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].instrument.nr_de_identificare);

                    printf("Cheia muzicala a instrumentului folosit %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].instrument.cheie_muzicala);

                    printf("Titlul albumului %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].album.titlu);

                    printf("Codul albumului %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].album.cod_album2);

                    printf("Data aparitiei %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].album.data);

                    printf("Detinatorul dreturilor de autor %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].album.copyright);

                    printf("Tip format %d: ",y+1);
                    getchar();
                    scanf("%[^\n]",muzicieni[y].album.tip_format);

                    fprintf(file_muzicieni, "\n%s | %s | %s | %s | %s | %s", muzicieni[y].cnp, muzicieni[y].nume_si_prenume, muzicieni[y].adresa, muzicieni[y].telefon, muzicieni[y].instrument.nume, muzicieni[y].album.cod_album2);
                    fprintf(file_albume, "\n%s | %s | %s | %s | %s", muzicieni[y].album.cod_album2, muzicieni[y].album.titlu, muzicieni[y].album.data, muzicieni[y].album.copyright, muzicieni[y].album.tip_format);
                    fprintf(file_instrumente, "\n%s | %s | %s", muzicieni[y].instrument.nr_de_identificare, muzicieni[y].instrument.nume, muzicieni[y].instrument.cheie_muzicala);
                    y++;
                }
                printf("\n");
            }
            fclose(file_muzicieni);
            fclose(file_albume);
            fclose(file_instrumente);
}
void cautare_generala(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        printf("Introduceti comanda: ");
        getchar();
        scanf("%[^\n]",input);
        sscanf(input,"%s %[^\t\n]",in1,in2);
        for(int k=1 ; k<n ; k++)
        {
            if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
            {
                afisare_node_muzicieni(&muzicieni[k]);
            }
            else
            {
                if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                {
                    afisare_node_muzicieni(&muzicieni[k]);
                }
                else
                {
                    if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                    {
                        afisare_node_muzicieni(&muzicieni[k]);
                    }
                    else
                    {
                        if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                        {
                            afisare_node_muzicieni(&muzicieni[k]);
                        }
                        else
                        {
                            if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                            {
                                afisare_node_muzicieni(&muzicieni[k]);
                            }
                            else
                            {
                                if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                {
                                    afisare_node_muzicieni(&muzicieni[k]);
                                }
                                else
                                {
                                    if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                    {
                                        afisare_node_muzicieni(&muzicieni[k]);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                        {
                                            afisare_node_muzicieni(&muzicieni[k]);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                            {
                                                afisare_node_muzicieni(&muzicieni[k]);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                {
                                                    afisare_node_muzicieni(&muzicieni[k]);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                    {
                                                        afisare_node_muzicieni(&muzicieni[k]);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                        {
                                                            afisare_node_muzicieni(&muzicieni[k]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);

}
void stergere_generala(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        char repetare;
        do
        {
            printf("Introduceti comanda: ");
            getchar();
            scanf("%[^\n]",input);
            sscanf(input,"%s %[^\t\n]",in1,in2);
            for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    afisare_node_muzicieni(&muzicieni[k]);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        afisare_node_muzicieni(&muzicieni[k]);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            afisare_node_muzicieni(&muzicieni[k]);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                afisare_node_muzicieni(&muzicieni[k]);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    afisare_node_muzicieni(&muzicieni[k]);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        afisare_node_muzicieni(&muzicieni[k]);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            afisare_node_muzicieni(&muzicieni[k]);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                afisare_node_muzicieni(&muzicieni[k]);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    afisare_node_muzicieni(&muzicieni[k]);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        afisare_node_muzicieni(&muzicieni[k]);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            afisare_node_muzicieni(&muzicieni[k]);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                afisare_node_muzicieni(&muzicieni[k]);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("Acesta este rezultatul cautat?(y/n): ");
            scanf(" %c",&repetare);
        }while(repetare == 'n');
        fclose(file_muzicieni);
        fclose(file_albume);
        file_muzicieni = fopen("muzicieni.csv","w");
        file_albume = fopen("albume.csv","w");
        file_instrumente = fopen("instrumente.csv","w");
        fprintf(file_muzicieni,"CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        fprintf(file_albume,"Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        fprintf(file_instrumente,"Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)==0)
                {
                    output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)==0)
                    {
                        output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)==0)
                        {
                            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)==0)
                            {
                                output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)==0)
                                {
                                    output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)==0)
                                    {
                                        output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)==0)
                                        {
                                            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)==0)
                                            {
                                                output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)==0)
                                                {
                                                    output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)==0)
                                                    {
                                                        output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)==0)
                                                        {
                                                            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)==0)
                                                            {
                                                                output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);

}
void modificare_generala(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        char repetare;
        do
        {
            printf("Introduceti comanda: ");
            getchar();
            scanf("%[^\n]",input);
            sscanf(input,"%s %[^\t\n]",in1,in2);
            for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    afisare_node_muzicieni(&muzicieni[k]);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        afisare_node_muzicieni(&muzicieni[k]);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            afisare_node_muzicieni(&muzicieni[k]);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                afisare_node_muzicieni(&muzicieni[k]);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    afisare_node_muzicieni(&muzicieni[k]);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        afisare_node_muzicieni(&muzicieni[k]);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            afisare_node_muzicieni(&muzicieni[k]);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                afisare_node_muzicieni(&muzicieni[k]);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    afisare_node_muzicieni(&muzicieni[k]);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        afisare_node_muzicieni(&muzicieni[k]);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            afisare_node_muzicieni(&muzicieni[k]);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                afisare_node_muzicieni(&muzicieni[k]);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("Acesta este rezultatul cautat?(y/n): ");
            scanf(" %c",&repetare);
        }while(repetare == 'n');
        char modificare[1024],inlocuibil[1024];
        printf("Ce inlocuim?: ");
        getchar();
        scanf("%[^\n]",inlocuibil);
        printf("Cu ce inlocuim optiunea aleasa?: ");
        getchar();
        scanf("%[^\n]",modificare);
        for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"TITLU_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        fclose(file_muzicieni);
        fclose(file_albume);
        fclose(file_instrumente);
        file_muzicieni = fopen("muzicieni.csv","w");
        file_albume = fopen("albume.csv","w");
        file_instrumente = fopen("instrumente.csv","w");
        fprintf(file_muzicieni,"CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        fprintf(file_albume,"Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        fprintf(file_instrumente,"Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
        {
            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
        }
        fclose(file_muzicieni);
        fclose(file_albume);
        fclose(file_instrumente);
    }
}


void afisare_muzicieni_solo(FILE *file_muzicieni)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    if(file_muzicieni == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni_solo(line_muzicieni);
        }
        printf("=================================");
        printf("\n CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        for(int k=1 ; k<n ; k++)
        {
            afisare_node_muzicieni_solo(&muzicieni[k]);
        }
    }
    fclose(file_muzicieni);
    printf("\n");
}
void cautare_muzicieni_solo(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        printf("Introduceti comanda: ");
        getchar();
        scanf("%[^\n]",input);
        sscanf(input,"%s %[^\t\n]",in1,in2);
        printf("=================================");
        printf("\n CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        for(int k=1 ; k<n ; k++)
        {
            if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
            {
                afisare_node_muzicieni_solo(&muzicieni[k]);
            }
            else
            {
                if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                {
                    afisare_node_muzicieni_solo(&muzicieni[k]);
                }
                else
                {
                    if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                    {
                        afisare_node_muzicieni_solo(&muzicieni[k]);
                    }
                    else
                    {
                        if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                        {
                            afisare_node_muzicieni_solo(&muzicieni[k]);
                        }
                        else
                        {
                            if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                            {
                                afisare_node_muzicieni_solo(&muzicieni[k]);
                            }
                            else
                            {
                                if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                {
                                    afisare_node_muzicieni_solo(&muzicieni[k]);
                                }
                                else
                                {
                                    if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                    {
                                        afisare_node_muzicieni_solo(&muzicieni[k]);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                        {
                                            afisare_node_muzicieni_solo(&muzicieni[k]);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                            {
                                                afisare_node_muzicieni_solo(&muzicieni[k]);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                {
                                                    afisare_node_muzicieni_solo(&muzicieni[k]);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                    {
                                                        afisare_node_muzicieni_solo(&muzicieni[k]);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                        {
                                                            afisare_node_muzicieni_solo(&muzicieni[k]);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
    printf("\n");
}
void modificare_muzicieni_solo(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        char repetare;
        do
        {
            printf("Introduceti comanda: ");
            getchar();
            scanf("%[^\n]",input);
            sscanf(input,"%s %[^\t\n]",in1,in2);
            for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    afisare_node_muzicieni_solo(&muzicieni[k]);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        afisare_node_muzicieni_solo(&muzicieni[k]);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            afisare_node_muzicieni_solo(&muzicieni[k]);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                afisare_node_muzicieni_solo(&muzicieni[k]);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    afisare_node_muzicieni_solo(&muzicieni[k]);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        afisare_node_muzicieni_solo(&muzicieni[k]);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            afisare_node_muzicieni_solo(&muzicieni[k]);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                afisare_node_muzicieni_solo(&muzicieni[k]);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    afisare_node_muzicieni_solo(&muzicieni[k]);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        afisare_node_muzicieni_solo(&muzicieni[k]);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            afisare_node_muzicieni_solo(&muzicieni[k]);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                afisare_node_muzicieni_solo(&muzicieni[k]);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("\n");
            printf("Acesta este rezultatul cautat?(y/n): ");
            scanf(" %c",&repetare);
        }while(repetare == 'n');
        char modificare[1024],inlocuibil[1024];
        printf("Ce inlocuim?: ");
        getchar();
        scanf("%[^\n]",inlocuibil);
        printf("Cu ce inlocuim optiunea aleasa?: ");
        getchar();
        scanf("%[^\n]",modificare);
        for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"TITLU_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        fclose(file_muzicieni);
        fclose(file_albume);
        fclose(file_instrumente);
        file_muzicieni = fopen("muzicieni.csv","w");
        file_albume = fopen("albume.csv","w");
        file_instrumente = fopen("instrumente.csv","w");
        fprintf(file_muzicieni,"CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        fprintf(file_albume,"Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        fprintf(file_instrumente,"Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
        {
            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
}


void afisare_albume(FILE *file_albume)
{
    file_albume = fopen("albume.csv","r");
    if(file_albume == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_albume,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_albume))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_albume,0,SEEK_SET);
        struct album *albume = malloc(sizeof(struct album)*n);
        char line_albume[1024];
        for(int k=0 ; fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && k<n ; k++)
        {
            albume[k]=citire_node_albume(line_albume);
        }
        printf("=================================");
        printf("\n Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        for(int k=1 ; k<n ; k++)
        {
            afisare_node_albume(&albume[k]);
        }
    }
    fclose(file_albume);
    printf("\n");
}
void cautare_albume(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        printf("Introduceti comanda: ");
        getchar();
        scanf("%[^\n]",input);
        sscanf(input,"%s %[^\t\n]",in1,in2);
        printf("=================================");
        printf("\n Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        for(int k=1 ; k<n ; k++)
        {
            if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
            {
                afisare_node_albume(&muzicieni[k].album);
            }
            else
            {
                if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                {
                    afisare_node_albume(&muzicieni[k].album);
                }
                else
                {
                    if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                    {
                        afisare_node_albume(&muzicieni[k].album);
                    }
                    else
                    {
                        if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                        {
                            afisare_node_albume(&muzicieni[k].album);
                        }
                        else
                        {
                            if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                            {
                                afisare_node_albume(&muzicieni[k].album);
                            }
                            else
                            {
                                if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                {
                                    afisare_node_albume(&muzicieni[k].album);
                                }
                                else
                                {
                                    if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                    {
                                        afisare_node_albume(&muzicieni[k].album);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                        {
                                            afisare_node_albume(&muzicieni[k].album);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                            {
                                                afisare_node_albume(&muzicieni[k].album);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                {
                                                    afisare_node_albume(&muzicieni[k].album);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                    {
                                                        afisare_node_albume(&muzicieni[k].album);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                        {
                                                            afisare_node_albume(&muzicieni[k].album);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
    printf("\n");
}
void modificare_albume(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        char repetare;
        do
        {
            printf("Introduceti comanda: ");
            getchar();
            scanf("%[^\n]",input);
            sscanf(input,"%s %[^\t\n]",in1,in2);
            for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    afisare_node_albume(&muzicieni[k].album);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        afisare_node_albume(&muzicieni[k].album);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            afisare_node_albume(&muzicieni[k].album);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                afisare_node_albume(&muzicieni[k].album);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    afisare_node_albume(&muzicieni[k].album);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        afisare_node_albume(&muzicieni[k].album);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            afisare_node_albume(&muzicieni[k].album);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                afisare_node_albume(&muzicieni[k].album);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    afisare_node_albume(&muzicieni[k].album);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        afisare_node_albume(&muzicieni[k].album);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            afisare_node_albume(&muzicieni[k].album);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                afisare_node_albume(&muzicieni[k].album);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("\n");
            printf("Acesta este rezultatul cautat?(y/n): ");
            scanf(" %c",&repetare);
        }while(repetare == 'n');
        char modificare[1024],inlocuibil[1024];
        printf("Ce inlocuim?: ");
        getchar();
        scanf("%[^\n]",inlocuibil);
        printf("Cu ce inlocuim optiunea aleasa?: ");
        getchar();
        scanf("%[^\n]",modificare);
        for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"TITLU_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        fclose(file_muzicieni);
        fclose(file_albume);
        fclose(file_instrumente);
        file_muzicieni = fopen("muzicieni.csv","w");
        file_albume = fopen("albume.csv","w");
        file_instrumente = fopen("instrumente.csv","w");
        fprintf(file_muzicieni,"CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        fprintf(file_albume,"Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        fprintf(file_instrumente,"Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
        {
            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
}


void afisare_instrumente(FILE *file_instrumente)
{
    file_instrumente = fopen("instrumente.csv","r");
    if(file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_instrumente,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_instrumente))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_instrumente,0,SEEK_SET);
        struct instrument *instrumente = malloc(sizeof(struct instrument)*n);
        char line_instrumente[1024];
        for(int k=0 ; fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            instrumente[k]=citire_node_instrumente(line_instrumente);
        }
        printf("=================================");
        printf("\n Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
        {
            afisare_node_instrumente(&instrumente[k]);
        }
    }
    fclose(file_instrumente);
    printf("\n");
}
void cautare_instrumente(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        printf("Introduceti comanda: ");
        getchar();
        scanf("%[^\n]",input);
        sscanf(input,"%s %[^\t\n]",in1,in2);
        printf("=================================");
        printf("\n Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        for(int k=1 ; k<n ; k++)
        {
            if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
            {
                afisare_node_instrumente(&muzicieni[k].instrument);
            }
            else
            {
                if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                {
                    afisare_node_instrumente(&muzicieni[k].instrument);
                }
                else
                {
                    if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                    {
                        afisare_node_instrumente(&muzicieni[k].instrument);
                    }
                    else
                    {
                        if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                        {
                            afisare_node_instrumente(&muzicieni[k].instrument);
                        }
                        else
                        {
                            if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                            {
                                afisare_node_instrumente(&muzicieni[k].instrument);
                            }
                            else
                            {
                                if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                {
                                    afisare_node_instrumente(&muzicieni[k].instrument);
                                }
                                else
                                {
                                    if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                    {
                                        afisare_node_instrumente(&muzicieni[k].instrument);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                        {
                                            afisare_node_instrumente(&muzicieni[k].instrument);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                            {
                                                afisare_node_instrumente(&muzicieni[k].instrument);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                {
                                                    afisare_node_instrumente(&muzicieni[k].instrument);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                    {
                                                        afisare_node_instrumente(&muzicieni[k].instrument);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                        {
                                                            afisare_node_instrumente(&muzicieni[k].instrument);
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
    printf("\n");
}
void modificare_instrumente(FILE *file_muzicieni,FILE *file_albume,FILE *file_instrumente)
{
    file_muzicieni = fopen("muzicieni.csv","r");
    file_albume = fopen("albume.csv","r");
    file_instrumente = fopen("instrumente.csv","r");
    if(file_muzicieni == NULL || file_albume == NULL || file_instrumente == NULL)
    {
        printf("!!!! Nu se poate gasi/deschide fila/filele !!!!\n");
    }
    int n=0;
    long size;
    fseek(file_muzicieni,0,SEEK_SET);
    char line_count[1024];
    while(fgets(line_count,sizeof(line_count),file_muzicieni))
    {
        n++;
    }
    if(n <= 1)
    {
        printf("!!!! Fila este goala !!!!\n");
    }
    else
    {
        fseek(file_muzicieni,0,SEEK_SET);
        muzician *muzicieni = malloc(sizeof(muzician)*n);
        char line_muzicieni[1024],line_albume[1024],line_instrumente[1024];
        for(int k=0 ; fgets(line_muzicieni,sizeof(line_muzicieni),file_muzicieni)!=NULL && fgets(line_albume,sizeof(line_albume),file_albume)!=NULL && fgets(line_instrumente,sizeof(line_instrumente),file_instrumente)!=NULL && k<n ; k++)
        {
            muzicieni[k]=citire_node_muzicieni(line_muzicieni,line_albume,line_instrumente);
        }
        char input[1024],in1[1024],in2[1024];
        char repetare;
        do
        {
            printf("Introduceti comanda: ");
            getchar();
            scanf("%[^\n]",input);
            sscanf(input,"%s %[^\t\n]",in1,in2);
            for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    afisare_node_instrumente(&muzicieni[k].instrument);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        afisare_node_instrumente(&muzicieni[k].instrument);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            afisare_node_instrumente(&muzicieni[k].instrument);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                afisare_node_instrumente(&muzicieni[k].instrument);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    afisare_node_instrumente(&muzicieni[k].instrument);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        afisare_node_instrumente(&muzicieni[k].instrument);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            afisare_node_instrumente(&muzicieni[k].instrument);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"NUME_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                afisare_node_instrumente(&muzicieni[k].instrument);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    afisare_node_instrumente(&muzicieni[k].instrument);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        afisare_node_instrumente(&muzicieni[k].instrument);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            afisare_node_instrumente(&muzicieni[k].instrument);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                afisare_node_instrumente(&muzicieni[k].instrument);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            printf("\n");
            printf("Acesta este rezultatul cautat?(y/n): ");
            scanf(" %c",&repetare);
        }while(repetare == 'n');
        char modificare[1024],inlocuibil[1024];
        printf("Ce inlocuim?: ");
        getchar();
        scanf("%[^\n]",inlocuibil);
        printf("Cu ce inlocuim optiunea aleasa?: ");
        getchar();
        scanf("%[^\n]",modificare);
        for(int k=1 ; k<n ; k++)
            {
                if(strcmp(in1,"CNP")==0 && strstr(muzicieni[k].cnp,in2)!=0)
                {
                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                }
                else
                {
                    if(strcmp(in1,"NUME")==0 && strstr(muzicieni[k].nume_si_prenume,in2)!=0)
                    {
                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                    }
                    else
                    {
                        if(strcmp(in1,"ADRESA")==0 && strstr(muzicieni[k].adresa,in2)!=0)
                        {
                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                        }
                        else
                        {
                            if(strcmp(in1,"TELEFON")==0 && strstr(muzicieni[k].telefon,in2)!=0)
                            {
                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                            }
                            else
                            {
                                if(strcmp(in1,"NUME_INSTRUMENT")==0 && strstr(muzicieni[k].instrument.nume,in2)!=0)
                                {
                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                }
                                else
                                {
                                    if(strcmp(in1,"NR_DE_IDENTIFICARE")==0 && strstr(muzicieni[k].instrument.nr_de_identificare,in2)!=0)
                                    {
                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                    }
                                    else
                                    {
                                        if(strcmp(in1,"CHEIE_MUZICALA")==0 && strstr(muzicieni[k].instrument.cheie_muzicala,in2)!=0)
                                        {
                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                        }
                                        else
                                        {
                                            if(strcmp(in1,"TITLU_ALBUM")==0 && strstr(muzicieni[k].album.titlu,in2)!=0)
                                            {
                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                            }
                                            else
                                            {
                                                if(strcmp(in1,"COD_ALBUM")==0 && strstr(muzicieni[k].album.cod_album2,in2)!=0)
                                                {
                                                    proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                }
                                                else
                                                {
                                                    if(strcmp(in1,"COPYRIGHT")==0 && strstr(muzicieni[k].album.copyright,in2)!=0)
                                                    {
                                                        proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                    }
                                                    else
                                                    {
                                                        if(strcmp(in1,"DATA")==0 && strstr(muzicieni[k].album.data,in2)!=0)
                                                        {
                                                            proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                        }
                                                        else
                                                        {
                                                            if(strcmp(in1,"TIP_FORMAT")==0 && strstr(muzicieni[k].album.tip_format,in2)!=0)
                                                            {
                                                                proces_de_modificare(&muzicieni[k],inlocuibil,modificare);
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        fclose(file_muzicieni);
        fclose(file_albume);
        fclose(file_instrumente);
        file_muzicieni = fopen("muzicieni.csv","w");
        file_albume = fopen("albume.csv","w");
        file_instrumente = fopen("instrumente.csv","w");
        fprintf(file_muzicieni,"CNP | Nume si Prenume | Adresa | Telefon | Instrumentele folosite | Cod album");
        fprintf(file_albume,"Cod album | Titlu | Data aparitiei | Detinatorul dreturilor de autor | Tip format");
        fprintf(file_instrumente,"Numar de identificare | Numele instrumentului | Cheie muzicala");
        for(int k=1 ; k<n ; k++)
        {
            output_file(&muzicieni[k],file_muzicieni,file_albume,file_instrumente);
        }
    }
    fclose(file_muzicieni);
    fclose(file_albume);
    fclose(file_instrumente);
}

// instructiuni ========================================================================================
void instructiuni()
{
    printf("=================================\n");
    printf(" ---------- Firma de inregistrari ---------- \n");
    printf("Instructiuni generale(1)\n");
    printf("Baza de date a muzicienilor(2)\n");
    printf("Baza de date a albumelor(3)\n");
    printf("Baza de date a instrumentelor(4)\n");
    printf("Iesire(0)\n");
    printf("Introduceti cifra corespunzatoare instructiunii dorite: ");
}
void instructiuni_case1()
{
    printf("=================================\n");
    printf(" ---------- Instructiuni generale ---------- \n");
    printf("Creare / Resetare a bazei de date(1)\n");
    printf("Afisare generala a datelor(2)\n");
    printf("Adaugare de date(3)\n");
    printf("Cautare generala a datelor(4)\n");
    printf("Stergere generala a datelor(5)\n");
    printf("Modificare de date(6)\n");
    printf("Iesire(0)\n");
    printf("Introduceti cifra corespunzatoare instructiunii dorite: ");
}
void instructiuni_case2()
{
    printf("=================================\n");
    printf(" ---------- Baza de date a muzicienilor ---------- \n");
    printf("Afisare(1)\n");
    printf("Editare a datelor(2)\n");
    printf("Cautare(3)\n");
    printf("Iesire(0)\n");
    printf("Introduceti cifra corespunzatoare instructiunii dorite: ");
}
void instructiuni_case3()
{
    printf("=================================\n");
    printf(" ---------- Baza de date a albumelor ---------- \n");
    printf("Afisare(1)\n");
    printf("Editare a datelor(2)\n");
    printf("Cautare(3)\n");
    printf("Iesire(0)\n");
    printf("Introduceti cifra corespunzatoare instructiunii dorite: ");
}
void instructiuni_case4()
{
    printf("=================================\n");
    printf(" ---------- Baza de date a instrumentelor ---------- \n");
    printf("Afisare(1)\n");
    printf("Editare a datelor(2)\n");
    printf("Cautare(3)\n");
    printf("Iesire(0)\n");
    printf("Introduceti cifra corespunzatoare instructiunii dorite: ");
}

// main ==============================================================================================================
int main()
{
    FILE *file_muzicieni,*file_albume,*file_instrumente;
    int alegere;
    do
    {
        instructiuni();
        scanf("%d",&alegere);
        switch(alegere)
        {


            case 0:
                printf("================================= Programul s-a inchis =================================");
                break;
//------------------------------------------------------------------------------------------------------------------
            case 1:
                instructiuni_case1();
                scanf("%d",&alegere);
                switch(alegere)
                {
                    case 0:
                        printf("================================= Programul s-a inchis =================================");
                        break;
                    case 1:
                        creare_resetare(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 2:
                        afisare_generala(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 3:
                        append_general(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 4:
                        cautare_generala(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 5:
                        stergere_generala(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 6:
                        modificare_generala(file_muzicieni,file_albume,file_instrumente);
                        break;
                    default:
                        printf("!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n");
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 2:
                instructiuni_case2();
                scanf("%d",&alegere);
                switch(alegere)
                {
                    case 0:
                        printf("================================= Programul s-a inchis =================================");
                        break;
                    case 1:
                        afisare_muzicieni_solo(file_muzicieni);
                        break;
                    case 2:
                        modificare_muzicieni_solo(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 3:
                        cautare_muzicieni_solo(file_muzicieni,file_albume,file_instrumente);
                        break;
                    default:
                        printf("!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n");
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 3:
                instructiuni_case3();
                scanf("%d",&alegere);
                switch(alegere)
                {
                    case 0:
                        printf("================================= Programul s-a inchis =================================");
                        break;
                    case 1:
                        afisare_albume(file_albume);
                        break;
                    case 2:
                        modificare_albume(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 3:
                        cautare_albume(file_muzicieni,file_albume,file_instrumente);
                        break;
                    default:
                        printf("!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n");
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------
            case 4:
                instructiuni_case4();
                scanf("%d",&alegere);
                switch(alegere)
                {
                    case 0:
                        printf("================================= Programul s-a inchis =================================");
                        break;
                    case 1:
                        afisare_instrumente(file_instrumente);
                        break;
                    case 2:
                        modificare_instrumente(file_muzicieni,file_albume,file_instrumente);
                        break;
                    case 3:
                        cautare_instrumente(file_muzicieni,file_albume,file_instrumente);
                        break;
                    default:
                        printf("!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n");
                        break;
                }
                break;
//------------------------------------------------------------------------------------------------------------------


            default:
                printf("!!!! Nu este o alegere valida. Introduceti numarul din paranteza corespunzatoare instructiunii !!!!\n");
                break;


//------------------------------------------------------------------------------------------------------------------
        }

    }while(alegere!=0);
}


