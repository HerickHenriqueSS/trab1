#include<stdio.h>
#include<stdlib.h>

int main()
{

    int lin, col, i, j, k, l, vmax, num, choice;
    char buffer[250];

    FILE *source;
    FILE *target;
    FILE *target1;
    FILE *target2;

    do
    {
        printf("\n==============================     M E N U     =================================\n");
        printf("\n   1. Converter uma imagem colorida para escala de cinza.");
        printf("\n   2. Espelhar uma imagem horizontalmente.");
        printf("\n   3. Espelhar uma imagem verticalmente.");
        printf("\n   4. Dividir uma imagem em dois arquivos (um arquivo com a metade esquerda,");
        printf("\n      e outro arquivo com a metade direita.");
        printf("\n   5. Dividir uma imagem em dois arquivos (um arquivo com a metade superior,");
        printf("\n      e outro arquivo com a metade inferior.");
        printf("\n   0. Sair.\n");
        printf("\n      Escolha a opcao desejada: ");

        scanf("%d", &choice);

        if(choice == 1)
        {
            source = fopen("owl1.ppm", "r");
            target = fopen("owl1gray.ppm", "w");

            if(source == NULL)
            {
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            else
            {
                // LENDO OS DADOS DO TAMANHO DA FIGURA DA ORIGEM E CRIANDO A MATRIZ DE DADOS DE ORIGEM COM A MÉDIA DOS VALORES DOS PIXELS COLORIDOS
                printf("\n\nEscolha: %d", choice);
                fgets(buffer, 250, source); //P3 - linha1
                fgets(buffer, 250, source); //Comentário- linha 2
                fscanf(source, "%d %d", &col, &lin); // sei o padrão da linha, dois inteiros separados por espaço
                fscanf(source, "%d", &vmax); // quarta linha = sei o padrão da linha, um inteiro
                int mat[lin][col][3];

                fprintf(target, "P3\n");
                fprintf(target, "#Feito por Herick\n");
                fprintf(target, "%d %d\n", col, lin);
                fprintf(target, "%d\n", vmax);

                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        num = 0;
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fscanf(source,"%d", &mat[i][j][k]);
                            num = num + mat[i][j][k];
                            //printf("%d", matriz[i][j][k]);
                        }
                        num = num / 3; // Calculando a média de n = valores de r, g e b tem q ser igual
                        fprintf(target, "%d %d %d ", num, num, num);
                    }

                }
            }
            fclose(source);
            fclose(target);
            printf("\n                   =====> A imagem foi convertida para escala de cinza!\n\n");

        }
        else if( choice == 2)
        {
            source = fopen("owl1.ppm", "r");
            target = fopen("owl1Mirrorh.ppm", "w");

            if(source == NULL)
            {
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            else
            {
                // LENDO OS DADOS DO TAMANHO DA FIGURA DA ORIGEM E CRIANDO A MATRIZ DE DADOS DE ORIGEM
                fgets(buffer, 250, source); //P3 - linha1
                fgets(buffer, 250, source); //Comentário- linha 2
                fscanf(source, "%d %d", &col, &lin); // sei o padrão da linha, dois inteiros separados por espaço
                fscanf(source, "%d", &vmax); // quarta linha = sei o padrão da linha, um inteiro
                int mat[lin][col][3];

                fprintf(target, "P3\n");
                fprintf(target, "#Feito por Herick\n");
                fprintf(target, "%d %d\n", col, lin);
                fprintf(target, "%d\n", vmax);


                // FAZENDO A INVERSÃO E SALVANDO NO ARQUIVO DESTINO
                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        ;
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fscanf(source,"%d", &mat[i][j][k]);
                        }
                    }
                }

                for(i=0; i<lin; i++)
                {
                    for(j=col; j>0; j--)
                    {
                        ;
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target, "%d ", mat[i][j][k]);
                            fprintf(target, "\n");

                        }
                    }
                }

            }
            fclose(source);
            fclose(target);
            printf("\n                     =====> A imagem foi invertida horizontalmente!\n\n");

        }
        else if( choice == 3 )
        {
            source = fopen("owl1.ppm", "r");
            target = fopen("owl1Mirrorv.ppm", "w");

            if(source == NULL)
            {
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            else
            {
                // LENDO OS DADOS DO TAMANHO DA FIGURA DA ORIGEM E CRIANDO A MATRIZ DE DADOS DE ORIGEM
                fgets(buffer, 250, source); //P3 - linha1
                fgets(buffer, 250, source); //Comentário- linha 2
                fscanf(source, "%d %d", &col, &lin); // sei o padrão da linha, dois inteiros separados por espaço
                fscanf(source, "%d", &vmax); // quarta linha = sei o padrão da linha, um inteiro
                int mat[lin][col][3];

                fprintf(target, "P3\n");
                fprintf(target, "#Feito por Herick\n");
                fprintf(target, "%d %d\n", col, lin);
                fprintf(target, "%d\n", vmax);


                // FAZENDO A INVERSÃO E SALVANDO NO ARQUIVO DESTINO
                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        ;
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fscanf(source,"%d", &mat[i][j][k]);
                        }
                    }
                }

                for(i=lin; i>0; i--)
                {
                    for(j=col; j>0; j--)
                    {
                        ;
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target, "%d ", mat[i][j][k]);
                            fprintf(target, "\n");

                        }
                    }
                }
            }
            fclose(source);
            fclose(target);
            printf("\n                         =====> A imagem foi invertida verticalmente!\n\n");

        }else if(choice == 4)
        {
            source = fopen("owl1.ppm", "r");
            target1 = fopen("owl1halfv1.ppm", "w");
            target2 = fopen("owl1halfv2.ppm", "w");


            if(source == NULL)
            {
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            else
            {
                // LENDO OS DADOS DO TAMANHO DA FIGURA DA ORIGEM
                printf("\n\nEscolha: %d", choice);
                fgets(buffer, 250, source); //P3 - linha1
                fgets(buffer, 250, source); //Comentário- linha 2
                fscanf(source, "%d %d", &col, &lin); // sei o padrão da linha, dois inteiros separados por espaço
                fscanf(source, "%d", &vmax); // quarta linha = sei o padrão da linha, um inteiro
                int mat[lin][col][3];

                // GRAVANDO OS DADOS DO TAMANHO NO ARQUIVO DESTINO
                fprintf(target1, "P3\n");
                fprintf(target1, "#Feito por Herick\n");
                fprintf(target1, "%d %d\n", col/2, lin);
                fprintf(target1, "%d\n", vmax);

                fprintf(target2, "P3\n");
                fprintf(target2, "#Feito por Herick\n");
                fprintf(target2, "%d %d\n", col/2, lin);
                fprintf(target2, "%d\n", vmax);

                // LENDO OS DADOS DOS PIXELS DA FIGURA DE ORIGEM E SALVANDO NA MATRIZ
                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fscanf(source,"%d", &mat[i][j][k]);
                        }
                    }
                }

                // GRAVANDO APENAS OS DADOS VERTICAIS DA PRIMEIRA METADE DA MATRIZ SALVA NO PRIMEIRO ARQUIVO
                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col/2; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target1, "%d ", mat[i][j][k]);
                        }
                    }
                }

                // GRAVANDO APENAS OS DADOS VERTICAIS DA SEGUNDA METADE DA MATRIZ SALVA NO SEGUNDO ARQUIVO
                for(i=0; i<lin; i++)
                {
                    for(j=col/2; j<col; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target2, "%d ", mat[i][j][k]);
                        }
                    }
                }
            }
            fclose(source);
            fclose(target1);
            fclose(target2);
            printf("\n                      =====> A imagem foi dividida em duas metades verticais!\n\n");

        }else if(choice == 5)
        {   printf("\n ***** -> OPcao 5 selecionada");
            source = fopen("owl1.ppm", "r");
            target1 = fopen("owl1halhf1.ppm", "w");
            target2 = fopen("owl1halhf2.ppm", "w");

            if(source == NULL)
            {
                printf("Erro ao abrir o arquivo.");
                return 1;
            }
            else
            {
                // LENDO OS DADOS DO TAMANHO DA FIGURA DA ORIGEM
                printf("\n\nEscolha: %d", choice);
                fgets(buffer, 250, source); //P3 - linha1
                fgets(buffer, 250, source); //Comentário- linha 2
                fscanf(source, "%d %d", &col, &lin); // sei o padrão da linha, dois inteiros separados por espaço
                fscanf(source, "%d", &vmax); // quarta linha = sei o padrão da linha, um inteiro
                int mat[lin][col][3];

                // GRAVANDO OS DADOS DO TAMANHO NO ARQUIVO DESTINO
                fprintf(target1, "P3\n");
                fprintf(target1, "#Feito por Herick\n");
                fprintf(target1, "%d %d\n", col, lin/2);
                fprintf(target1, "%d\n", vmax);

                fprintf(target2, "P3\n");
                fprintf(target2, "#Feito por Herick\n");
                fprintf(target2, "%d %d\n", col, lin/2);
                fprintf(target2, "%d\n", vmax);

                // LENDO OS DADOS DOS PIXELS DA FIGURA DE ORIGEM E SALVANDO NA MATRIZ
                for(i=0; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fscanf(source,"%d", &mat[i][j][k]);
                        }
                    }
                }

                // GRAVANDO APENAS OS DADOS VERTICAIS DA PRIMEIRA METADE DA MATRIZ SALVA NO PRIMEIRO ARQUIVO
                for(i=0; i<lin/2; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target1, "%d ", mat[i][j][k]);
                        }
                    }
                }

                // GRAVANDO APENAS OS DADOS VERTICAIS DA SEGUNDA METADE DA MATRIZ SALVA NO SEGUNDO ARQUIVO
                for(i=lin/2; i<lin; i++)
                {
                    for(j=0; j<col; j++)
                    {
                        for(k=0; k<3; k++) // valores do r, g, b
                        {
                            fprintf(target2, "%d ", mat[i][j][k]);
                        }
                    }
                }
            }
            fclose(source);
            fclose(target1);
            fclose(target2);
            printf("\n                        =====> A imagem foi dividida em duas metades horizontais!\n\n");
        }

    }
    while( choice != 0);





    return 0;

}
