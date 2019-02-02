#include <iostream>
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

#define ANIMA_1 199999999
#define ANIMA_2 599999999

typedef enum {VENDA,ALUGUEL} tTipoDeNegocio;        //Define se a negociação eh Venda ou Aluguel
typedef enum {ATIVO,DESATIVO} tStatusDeAtiv;        //Define se o imóvel está ativo ou desativo para negociações


//Cria tCasa
typedef struct Casa{
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cep;
    std::string cidade;
    double valor;
    tTipoDeNegocio tipoDeNegocio;
    tStatusDeAtiv statusDeAtiv;

    std::string tituloAnuncio;
    int nPavimentos;
    int nQuartos;
    float areaTerreno;
    float areaConstruida;

}tCasa;

//Cria tApartamento
typedef struct Apartamento{
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cep;
    std::string cidade;
    double valor;
    tTipoDeNegocio tipoDeNegocio;
    tStatusDeAtiv statusDeAtiv;

    std::string tituloAnuncio;
    float areaTotal;
    int nQuartos;
    std::string posicao;
    int andar;
    float valorCondominio;
    int vagasGaragem;

}tApartamento;

//Cria tTerreno
typedef struct Terreno{
    std::string logradouro;
    int numero;
    std::string bairro;
    std::string cep;
    std::string cidade;
    double valor;
    tTipoDeNegocio tipoDeNegocio;
    tStatusDeAtiv statusDeAtiv;

    std::string tituloAnuncio;
    float areaTotal;

}tTerreno;

//Criação estruturas

    tCasa casa[500];
    tApartamento ape[500];
    tTerreno terreno[500];

//***************************



void Splash(){
    int i=0;

    for(i=0;i<ANIMA_2;i++);
    puts("\t\t\t\n\n\n\tBEM-VINDO");
    for(i=0;i<ANIMA_2;i++);
    printf("\t   A\n");
    for(i=0;i<ANIMA_2;i++);
    puts("     IMOBILIARIA JPVN\n");
    for(i=0;i<ANIMA_2;i++);

    system("CLS");
    for(i=0;i<ANIMA_1;i++);
    puts("\t\t\t\n\n\n\tBEM-VINDO\n\t   A\n     IMOBILIARIA JPVN");
    for(i=0;i<ANIMA_1;i++);
    system("CLS");
    for(i=0;i<ANIMA_1;i++);
    puts("\t\t\t\n\n\n\tBEM-VINDO\n\t   A\n     IMOBILIARIA JPVN");

}

//Mostra o menu principal
void DisplayMenu(){

    system("CLS");
    printf("1.Gerenciar Imoveis\n2.Lista de Imoveis Disponiveis\n3.Buscar Imoveis\n4.Sair do sistema\n");

}

//Mostra menu de gerenciamento de imoveis
void DisplaySubmenu1(){
    system("CLS");
    puts("\t\t\t\t\t\tGERENCIAMENTO DE IMOVEIS\n\n");
    printf("1.Cadastrar Imoveis\n2.Editar Imoveis\n3.Remover Imoveis\n4.Salvar Mudancas\n5.Cancelar\n");

}

//Mostra submenu da lista dos imoveis
void DisplaySubmenu2(){
    system("CLS");

    puts("\t\t\t\t\t\tLISTA DE IMOVEIS DISPONIVEIS\n\n");
    printf("1.Todos os Imoveis Disponiveis\n2.Imoveis Disponiveis para Venda\n3.Imoveis Disponiveis para Aluguel\n4.Voltar ao Menu Principal\n");

}

//Mostra menu da busca de imoveis
void DisplaySubmenu3(){
    system("CLS");

    puts("\t\t\t\t\t\tBUSCA DE IMOVEIS\n\n");
    printf("1.Busca por Titulo\n2.Busca por Bairro\n3.Busca por Valor\n4.Voltar ao Menu Principal\n");

}

//Salva dados nos vetores casa para o arquivo em que serao salvos
void SalvarCasa(tCasa casa[]){
    FILE *arqCasa = fopen("dadosCasa.txt","w");
    if (arqCasa > 0) {
        for(int i = 0; i<500;i++){
            if (casa[i].statusDeAtiv == ATIVO && casa[i].numero != 0) {

                fprintf(arqCasa, "%s\n", casa[i].logradouro.c_str());
                fprintf(arqCasa, "%d\n",casa[i].numero);
                fprintf(arqCasa, "%s\n",casa[i].bairro.c_str());
                fprintf(arqCasa, "%s\n", casa[i].cep.c_str());
                fprintf(arqCasa, "%s\n", casa[i].cidade.c_str());
                fprintf(arqCasa, "%lf\n", casa[i].valor);
                if(casa[i].tipoDeNegocio == ALUGUEL){
                    fprintf(arqCasa,"1\n");
                }else{
                    fprintf(arqCasa,"0\n");
                }
                if(casa[i].statusDeAtiv == ATIVO){
                    fprintf(arqCasa,"0\n");
                }else{
                    fprintf(arqCasa,"1\n");
                }

                //Exclusivos Casa
                fprintf(arqCasa, "%s\n", casa[i].tituloAnuncio.c_str());
                fprintf(arqCasa, "%d\n", casa[i].nPavimentos);
                fprintf(arqCasa, "%d\n", casa[i].nQuartos);
                fprintf(arqCasa, "%f\n", casa[i].areaTerreno);
                fprintf(arqCasa, "%f\n", casa[i].areaConstruida);
            }
        }
        fclose(arqCasa);
    }
    else
        std::cout << "Erro ao abrir o arquivo\n";

}

//salva dados no vetor ape
void SalvarApe(tApartamento ape[]){
    FILE *arqApe = fopen("dadosApe.txt","wt");
    if (arqApe > 0) {
        fwrite(ape, 500, sizeof(tApartamento), arqApe);
        fclose(arqApe);
    }
    else
        std::cout << "Erro ao abrir o arquivo\n";

}

//salva dados no vetor terreno
void SalvarTerreno(tTerreno terreno[]){
    FILE *arqTerreno = fopen("dadosTerreno.txt","wt");
    if (arqTerreno > 0) {
        fwrite(terreno, 500, sizeof(tTerreno), arqTerreno);
        fclose(arqTerreno);
    }
    else
        std::cout << "Erro ao abrir o arquivo\n";
    fclose(arqTerreno);
}

void CarregaCasa(tCasa casa[]){
    FILE* arqCasa = fopen("dadosCasa.txt", "r");
    if (arqCasa > 0) {

        int i=0,tipoDeNegocio,statusDeAtiv;
        char logradouro[500],bairro[500],cep[500],cidade[500],tituloAnuncio[500];
        while (!feof(arqCasa)){
            fgets(logradouro, 500, arqCasa);
            casa[i].logradouro = logradouro;

            fscanf(arqCasa,"%d%*c",&casa[i].numero);
            fgets(bairro, 500, arqCasa);
            casa[i].bairro = bairro;

            fgets(cep, 500, arqCasa);
            casa[i].cep=cep;

            fgets(cidade, 500, arqCasa);
            casa[i].cidade=cidade;

            fscanf(arqCasa,"%lf%*c",&casa[i].valor);
            fscanf(arqCasa,"%d%*c",&tipoDeNegocio);
            if(tipoDeNegocio == 0){
                casa[i].tipoDeNegocio = VENDA;
            }else{
                casa[i].tipoDeNegocio = ALUGUEL;
            }
            fscanf(arqCasa,"%d%*c",&statusDeAtiv);
            if(statusDeAtiv == 0){
                casa[i].statusDeAtiv = ATIVO;
            }else{
                casa[i].statusDeAtiv = DESATIVO;
            }


            //EXCLUSIVOS DE CASA
            fgets(tituloAnuncio, 500, arqCasa);
            casa[i].tituloAnuncio = tituloAnuncio;

            fscanf(arqCasa,"%d%*c",&casa[i].nPavimentos);
            fscanf(arqCasa,"%d%*c",&casa[i].nQuartos);
            fscanf(arqCasa,"%f%*c",&casa[i].areaTerreno);
            fscanf(arqCasa,"%f%*c",&casa[i].areaConstruida);
            i++;
        }
        }
        else
            std::cout << "Erro ao abrir o arquivo para leitura\n";

}
void CarregaApe(tApartamento ape[]){
    FILE* arqApe = fopen("dadosApe.txt", "rt");
    if (arqApe > 0) {
        fread(ape, 500, sizeof(tApartamento), arqApe);
        fclose(arqApe);
    }
    else
        std::cout << "Erro ao abrir o arquivo para leitura\n";

}
void CarregaTerreno(tTerreno terreno[]){
    FILE* arqTerreno = fopen("dadosTerreno.txt", "rt");
    if (arqTerreno > 0) {
        fread(terreno, 500, sizeof(tTerreno), arqTerreno);
        fclose(arqTerreno);
    }
    else
        std::cout << "Erro ao abrir o arquivo para leitura\n";

}

void CadastraCasa(){

    int i;
    int op;
    for(i=0;i<500;i++){
        if(casa[i].numero == 0 ){
            std::cout << "Digite o logradouro da casa que deseja cadastrar : \n";
            std::getline(std::cin,casa[i].logradouro);
            std::cout << "Digite o numero da casa que deseja cadastrar : \n";
            scanf("%d%*c" ,&casa[i].numero);
            std::cout << "Digite o bairro da casa que deseja cadastrar : \n";
            std::getline(std::cin,casa[i].bairro);
            std::cout << "Digite o CEP da casa que deseja cadastrar : \n";
            std::getline(std::cin,casa[i].cep);
            std::cout << "Digite a cidade da casa que deseja cadastrar : \n";
            std::getline(std::cin,casa[i].cidade);
            std::cout<<"Digite o valor da casa que deseja cadastrar : \n";
            scanf("%lf%*c",&casa[i].valor);

            std::cout << "Digite o tipo de negocio da casa que deseja cadastrar(1.Aluguel/2.Venda) : \n";
            scanf("%d%*c",&op);
            if(op == 1){
                casa[i].tipoDeNegocio == ALUGUEL;
            }else{
                casa[i].tipoDeNegocio == VENDA;
            }

            casa[i].statusDeAtiv = ATIVO;


            //PROPRIEDADES PARTICULARES DA ESTRUTURA CASA
            std::cout << "Digite o titulo de anuncio da casa que deseja cadastrar : \n";
            std::getline(std::cin,casa[i].tituloAnuncio);

            std::cout << "Digite o numero de pavimentos da casa que deseja cadastrar : \n";
            scanf("%d%*c" ,&casa[i].nPavimentos);
            std::cout << "Digite o numero de quartos da casa que deseja cadastrar : \n";
            scanf("%d%*c" ,&casa[i].nQuartos);
            std::cout << "Digite a area do terreno da casa que deseja cadastrar : \n";
            scanf("%f%*c" ,&casa[i].areaTerreno);
            std::cout << "Digite a area construida da casa que deseja cadastrar : \n";
            scanf("%f%*c" ,&casa[i].areaConstruida);

         break;
        }
    }

}
void CadastraTerreno(){
    static int i;
    int op;
    for(i=0;i<500;i++){
        if(terreno[i].numero == 0 ){
            std::cout << "Digite o logradouro do terreno que deseja cadastrar : \n";
            std::getline(std::cin,terreno[i].logradouro);
            std::cout << "Digite o numero do terreno que deseja cadastrar : \n";
            scanf("%d%*c" ,&terreno[i].numero);
            std::cout << "Digite o bairro do terreno que deseja cadastrar : \n";
            std::getline(std::cin,terreno[i].bairro);
            std::cout << "Digite o CEP do terreno que deseja cadastrar : \n";
            std::getline(std::cin,terreno[i].cep);
            std::cout << "Digite a cidade do terreno que deseja cadastrar : \n";
            std::getline(std::cin,terreno[i].cidade);
            std::cout<<"Digite o valor do terreno que deseja cadastrar : \n";
            scanf("%lf%*c",&terreno[i].valor);


            std::cout << "Digite o tipo de negocio do terreno que deseja cadastrar(1.Aluguel/2.Venda) : \n";
            scanf("%d%*c",&op);
            if(op == 1){
                terreno[i].tipoDeNegocio == ALUGUEL;
            }else{
                terreno[i].tipoDeNegocio == VENDA;
            }

            terreno[i].statusDeAtiv = ATIVO;
            //PROPRIEDADES DO TERRENO

            std::cout << "Digite o titulo do anuncio do terreno que deseja cadastrar : \n";
            std::getline(std::cin,terreno[i].tituloAnuncio);
            std::cout << "Digite o tamanho da area do terreno que deseja cadastrar : \n";
            scanf("%f%*c",&terreno[i].areaTotal);

            break;
        }
    }


}

void BuscaCasaTitulo(){
    int i;
    std::string busca;
    std::cout <<"Digite o titulo de anuncio que deseja buscar : \n";
    std::getline(std::cin,busca);
    system("cls");
    std::cout<<"\t\t\tCASAS ENCONTRADAS POR TITULO DE ANUNCIO : \n\n";

    for(i=0;i<500;i++){

        if( casa[i].tituloAnuncio == busca && casa[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<casa[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<casa[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<casa[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<casa[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<casa[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<casa[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<casa[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE CASA
            std::cout<<"*Numero de Pavimentos : "<<casa[i].nPavimentos<<std::endl;
            std::cout<<"*Numero de Quartos : "<<casa[i].nQuartos<<std::endl;
            std::cout<<"*Area do Terreno :  "<<casa[i].areaTerreno<<std::endl;
            std::cout<<"*Area Construida :  "<<casa[i].areaConstruida<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();

}
void BuscaCasaBairro(){
    int i;
    std::string busca;
    std::cout <<"Digite o bairro que deseja buscar : \n";
    std::getline(std::cin,busca);
    system("cls");
    std::cout<<"\t\t\tCASAS ENCONTRADAS POR BAIRRO : \n\n";

    for(i=0;i<500;i++){

        if( casa[i].bairro == busca && casa[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<casa[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<casa[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<casa[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<casa[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<casa[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<casa[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<casa[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE CASA
            std::cout<<"*Numero de Pavimentos : "<<casa[i].nPavimentos<<std::endl;
            std::cout<<"*Numero de Quartos : "<<casa[i].nQuartos<<std::endl;
            std::cout<<"*Area do Terreno :  "<<casa[i].areaTerreno<<std::endl;
            std::cout<<"*Area Construida :  "<<casa[i].areaConstruida<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();

}
void BuscaCasaValor(){
    int i;
    double busca;
    std::cout <<"Digite o valor base que deseja buscar : \n";
    std::cin >> busca;
    system("cls");
    std::cout<<"\t\t\tCASAS ENCONTRADAS COM VALOR ACIMA : \n\n";

    for(i=0;i<500;i++){

        if( casa[i].valor <= busca && casa[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<casa[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<casa[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<casa[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<casa[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<casa[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<casa[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<casa[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE CASA
            std::cout<<"*Numero de Pavimentos : "<<casa[i].nPavimentos<<std::endl;
            std::cout<<"*Numero de Quartos : "<<casa[i].nQuartos<<std::endl;
            std::cout<<"*Area do Terreno :  "<<casa[i].areaTerreno<<std::endl;
            std::cout<<"*Area Construida :  "<<casa[i].areaConstruida<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();

}


void BuscaApeTitulo(){
    int i;
    std::string busca;


    std::cout <<"Digite o titulo de anuncio que deseja buscar : \n";
    std::getline(std::cin,busca);

    system("cls");
    std::cout<<"\t\t\tAPARTAMENTOS ENCONTRADOS POR TITULO DE ANUNCIO : \n\n";

    for(i=0;i<500;i++){
        if(busca == ape[i].tituloAnuncio &&ape[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<ape[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<ape[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<ape[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<ape[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<ape[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<ape[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<ape[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE APARTAMENTO
            std::cout<<"*Area Total : "<<ape[i].areaTotal<<std::endl;
            std::cout<<"*Numero de Quartos : "<<ape[i].nQuartos<<std::endl;
            std::cout<<"*Posicao do apartamento :  "<<ape[i].posicao<<std::endl;
            std::cout<<"*Andar do apartamento :  "<<ape[i].andar<<std::endl;
            std::cout<<"*Valor do condominio : "<<ape[i].valorCondominio<<std::endl;
            std::cout<<"*Vagas de Garagem : "<<ape[i].vagasGaragem<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}
void BuscaApeBairro(){
    int i;
    std::string busca;


    std::cout <<"Digite o bairro que deseja buscar : \n";
    std::getline(std::cin,busca);

    system("cls");
    std::cout<<"\t\t\tAPARTAMENTOS ENCONTRADOS POR BAIRRO : \n\n";

    for(i=0;i<500;i++){
        if(busca == ape[i].bairro && ape[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<ape[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<ape[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<ape[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<ape[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<ape[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<ape[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<ape[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE APARTAMENTO
            std::cout<<"*Area Total : "<<ape[i].areaTotal<<std::endl;
            std::cout<<"*Numero de Quartos : "<<ape[i].nQuartos<<std::endl;
            std::cout<<"*Posicao do apartamento :  "<<ape[i].posicao<<std::endl;
            std::cout<<"*Andar do apartamento :  "<<ape[i].andar<<std::endl;
            std::cout<<"*Valor do condominio : "<<ape[i].valorCondominio<<std::endl;
            std::cout<<"*Vagas de Garagem : "<<ape[i].vagasGaragem<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}
void BuscaApeValor(){
    int i;
    double busca;


    std::cout <<"Digite o valor base que deseja buscar : \n";
    std::cin >> busca;

    system("cls");
    std::cout<<"\t\t\tAPARTAMENTOS ENCONTRADOS POR BAIRRO : \n\n";

    for(i=0;i<500;i++){
        if(busca >= ape[i].valor && ape[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<ape[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<ape[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<ape[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<ape[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<ape[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<ape[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<ape[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE APARTAMENTO
            std::cout<<"*Area Total : "<<ape[i].areaTotal<<std::endl;
            std::cout<<"*Numero de Quartos : "<<ape[i].nQuartos<<std::endl;
            std::cout<<"*Posicao do apartamento :  "<<ape[i].posicao<<std::endl;
            std::cout<<"*Andar do apartamento :  "<<ape[i].andar<<std::endl;
            std::cout<<"*Valor do condominio : "<<ape[i].valorCondominio<<std::endl;
            std::cout<<"*Vagas de Garagem : "<<ape[i].vagasGaragem<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}


void BuscaTerrenoTitulo(){
    int i;
    std::string busca;


    std::cout <<"Digite o titulo de anuncio que deseja buscar : \n";
    std::getline(std::cin,busca);

    system("cls");
    std::cout<<"\t\t\tTERRENOS ENCONTRADOS POR TITULO DE ANUNCIO : \n\n";

    for(i=0;i<500;i++){
        if(busca == terreno[i].tituloAnuncio && terreno[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<terreno[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<terreno[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<terreno[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<terreno[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<terreno[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<terreno[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<terreno[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE TERRENO
            std::cout<<"*Area Total : "<<terreno[i].areaTotal<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}
void BuscaTerrenoBairro(){
    int i;
    std::string busca;


    std::cout <<"Digite o bairro que deseja buscar : \n";
    std::getline(std::cin,busca);

    system("cls");
    std::cout<<"\t\t\tTERRENOS ENCONTRADOS POR BAIRRO : \n\n";

    for(i=0;i<500;i++){
        if(busca == terreno[i].bairro && terreno[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<terreno[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<terreno[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<terreno[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<terreno[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<terreno[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<terreno[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<terreno[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE TERRENO
            std::cout<<"*Area Total : "<<terreno[i].areaTotal<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}
void BuscaTerrenoValor(){
    int i;
    double busca;


    std::cout <<"Digite o valor base que deseja buscar : \n";
    std::cin >> busca;

    system("cls");
    std::cout<<"\t\t\tTERRENOS ENCONTRADOS POR VALOR : \n\n";

    for(i=0;i<500;i++){
        if(busca >= terreno[i].valor && terreno[i].statusDeAtiv == ATIVO){

            std::cout<<"************************************************\n";
            std::cout<<"*Titulo anuncio : "<<terreno[i].tituloAnuncio<<std::endl;
            std::cout<<"*Logradouro : "<<terreno[i].logradouro<<std::endl;
            std::cout<<"*Numero : "<<terreno[i].numero<<std::endl;
            std::cout<<"*Bairro : "<<terreno[i].bairro<<std::endl;
            std::cout<<"*CEP : "<<terreno[i].cep<<std::endl;
            std::cout<<"*Cidade : "<<terreno[i].cidade<<std::endl;
            std::cout<<"*Valor : " <<terreno[i].valor<<std::endl;



            //EXCLUSIVOS DA PROPRIEDADE TERRENO
            std::cout<<"*Area Total : "<<terreno[i].areaTotal<<std::endl;
            std::cout<<"************************************************\n";
        }
    }
    getch();
}
void CadastraApe(){
    static int i;
    int op;
    for(i=0;i<500;i++){
        if(ape[i].numero == 0 ){
            std::cout << "Digite o logradouro do apartamento que deseja cadastrar : \n";
            std::getline(std::cin,ape[i].logradouro);
            std::cout << "Digite o numero do apartamento que deseja cadastrar : \n";
            scanf("%d%*c" ,&ape[i].numero);
            std::cout << "Digite o bairro do apartamento que deseja cadastrar : \n";
            std::getline(std::cin,ape[i].bairro);
            std::cout << "Digite o CEP do apartamento que deseja cadastrar : \n";
            std::getline(std::cin,ape[i].cep);
            std::cout << "Digite a cidade do apartamento que deseja cadastrar : \n";
            std::getline(std::cin,ape[i].cidade);
            std::cout<<"Digite o valor do apartamento que deseja cadastrar : \n";
            scanf("%lf%*c",&ape[i].valor);


            std::cout << "Digite o tipo de negocio do apartamento que deseja cadastrar(1.Aluguel/2.Venda) : \n";
            scanf("%d%*c",&op);
            if(op == 1){
                ape[i].tipoDeNegocio == ALUGUEL;
            }else{
                ape[i].tipoDeNegocio == VENDA;
            }

            ape[i].statusDeAtiv = ATIVO;

            //PROPRIEDAS DA ESTRUTURA APE
            std::cout << "Digite o titulo anuncio do apartamento que deseja cadastrar : \n";
            getline(std::cin,ape[i].tituloAnuncio);
            std::cout << "Digite a area total do apartamento que deseja cadastrar : \n";
            scanf("%f%*c", &ape[i].areaTotal);
            std::cout << "Digite o numero de quartos do apartamento que deseja cadastrar : \n";
            scanf("%d%*c", &ape[i].nQuartos);
            std::cout << "Digite a posicao do apartamento que deseja cadastrar : \n";
            getline(std::cin,ape[i].posicao);
            std::cout << "Digite o andar do apartamento que deseja cadastrar : \n";
            scanf("%d%*c",&ape[i].andar);
            std::cout << "Digite o valor do condominio que deseja cadastrar : \n";
            scanf("%f*c", &ape[i].valorCondominio);
            std::cout << "Digite a quantidade de vagas na garagem do apartamento que deseja cadastrar : \n";
            scanf("%d*c", &ape[i].vagasGaragem);

            break;
        }

    }

}


void MenuListaImoveis(){
    int i;
    char op;

    system("cls");

    std::cout<<"Qual tipo de imovel voce deseja visualizar?"<<std::endl;
    std::cout<<"\t1.Casa\n\t2.Apartamento\n\t3.Terreno\n\t4.Cancelar"<<std::endl;
    op=getch();

    switch(op){
        case '1':
             std::cout<<"*******************Casas Disponiveis******************"<<std::endl;

            for (i=0; i<500; i++){
                if (casa[i].statusDeAtiv == ATIVO && casa[i].valor != 0){
                    std::cout<<"\t"<<casa[i].tituloAnuncio<<std::endl;
                    std::cout<<"\t-"<<casa[i].cep<<std::endl;
                if (casa[i].tipoDeNegocio == VENDA){
                    std::cout<<"\t-Venda"<<std::endl;
                }else{
                    std::cout<<"\t-Aluguel"<<std::endl;
                }
                std::cout<<"\t-R$"<<casa[i].valor<<std::endl;
                std::cout<<"\t-Indice "<<i<<std::endl;

                std::cout<<"******************************************************"<<std::endl;
                }

            }
            getch();
            break;
        case '2':
            std::cout<<"***************Apartamentos Disponiveis***************"<<std::endl;
            ///Apartamentos
            for (i=0; i<500; i++){
                if (ape[i].statusDeAtiv == ATIVO && ape[i].valor != 0){
                    std::cout<<"\t"<<ape[i].tituloAnuncio<<std::endl;
                    std::cout<<"\t-"<<ape[i].posicao<<std::endl;
                    std::cout<<"\t-"<<ape[i].cep<<std::endl;
                    if (ape[i].tipoDeNegocio == VENDA){
                        std::cout<<"\t-Venda"<<std::endl;
                    }else{
                        std::cout<<"\t-Aluguel"<<std::endl;
                    }
                    std::cout<<"\t-R$"<<ape[i].valor<<std::endl;

                    std::cout<<"******************************************************"<<std::endl;
                }
            }
            getch();
            break;
        case '3':
            std::cout<<"*******************Terrenos Disponiveis******************"<<std::endl;

            for (i=0; i<500; i++){
                if (terreno[i].statusDeAtiv == ATIVO && terreno[i].valor != 0){
                    std::cout<<"\t"<<terreno[i].tituloAnuncio<<std::endl;
                    std::cout<<"\t-"<<terreno[i].areaTotal<<"m2"<<std::endl;
                    std::cout<<"\t-"<<terreno[i].cep<<std::endl;
                    if (terreno[i].tipoDeNegocio == VENDA){
                        std::cout<<"\t-Venda"<<std::endl;
                    }else{
                        std::cout<<"\t-Aluguel"<<std::endl;
                    }
                    std::cout<<"\t-R$"<<terreno[i].valor<<std::endl;

                    std::cout<<"******************************************************"<<std::endl;
                }
            }
            getch();
            break;
    }

}
int main(){
    char op1, op2, op3, op4,op5,op6,op7,op8,op9;

    CarregaCasa(casa);
    CarregaApe(ape);
    CarregaTerreno(terreno);


    //Splash();
    //system("CLS");

    while(1){

        DisplayMenu();
        op1=getch();

        switch(op1){
        case '1':
            DisplaySubmenu1();
            op2=getch();

            switch(op2){
            case '1':
                while(1){
                    system("cls");
                    std::cout << "Deseja cadastrar que tipo de imovel ?\n1.Casa\n2.Apartamento\n3.Terreno\n4.Voltar\n";
                    op3 = getch();

                    switch(op3){
                    case '1':
                        CadastraCasa();
                        break;
                    case '2':
                        CadastraApe();
                        break;
                    case '3':
                        CadastraTerreno();
                        break;
                    default:
                        std::cout << "Opcao Invalida !";
                    }
                    if(op3=='4'){
                        break;
                    }
                }
                break;

            case '4':
                SalvarCasa(casa);
                SalvarApe(ape);
                SalvarTerreno(terreno);

            default:
                std::cout << "Em construcao";
            }
            break;
        case '2':
            MenuListaImoveis();
            break;
        case '3':
            DisplaySubmenu3();
            op4 = getch();

            switch(op4){
            case '1':
                while(1){
                    system("cls");
                    std::cout<<"Escolha o tipo do imovel que deseja buscar:\n1.Casa\n2.Apartamento\n3.Terreno\n4.Voltar\n";
                    op5 = getch();
                    switch(op5){
                    case '1' :
                        BuscaCasaTitulo();
                        break;
                    case '2':
                        BuscaApeTitulo();
                        break;
                    case '3' :
                        BuscaTerrenoTitulo();
                        break;
                    default:
                        std::cout<<"Opcao Invalida !\n";
                    }
                    if(op5 == '4'){
                        break;
                    }
                }
                break;
            case '2':
                    while(1){
                    system("cls");
                    std::cout<<"Escolha o tipo do imovel que deseja buscar:\n1.Casa\n2.Apartamento\n3.Terreno\n4.Voltar\n";
                    op6 = getch();
                    switch(op6){
                    case '1' :
                        BuscaCasaBairro();
                        break;
                    case '2':
                        BuscaApeBairro();
                        break;
                    case '3' :
                        BuscaTerrenoBairro();
                        break;
                    default:
                        std::cout<<"Opcao Invalida !\n";
                    }
                    if(op6 == '4'){
                        break;
                    }
                }
                break;
            case '3':
                    while(1){
                    system("cls");
                    std::cout<<"Escolha o tipo do imovel que deseja buscar:\n1.Casa\n2.Apartamento\n3.Terreno\n4.Voltar\n";
                    op6 = getch();
                    switch(op6){
                    case '1' :
                        BuscaCasaValor();
                        break;
                    case '2':
                        BuscaApeValor();
                        break;
                    case '3' :
                        BuscaTerrenoValor();
                        break;
                    default:
                        std::cout<<"Opcao Invalida !\n";
                    }
                    if(op6 == '4'){
                        break;
                    }
                }
                break;
            default :
                std::cout<<"Opcao Invalida";
            }
            break;

        case '4':

            system("cls");
            printf("ATE LOGO !\n");

            return 1;
        default:
            puts("Opcao Invalida !");
            system("CLS");

        }


    }


    return 0;
}
