#include <iostream>
#include <math.h>
#include <cmath>
#include <random>
#include <time.h>
#include "Data.hpp"
#include "Tree.hpp"

using namespace std;

int main (){
	setlocale (LC_ALL,"portuguese");
	tree *t;	
	t = NULL;	
	data test;
	int size=1;	
	int op;
	
	while (true){
		cout<<"--------------------------MENU--------------------------\n\n";
		cout<<"Digite:\n\n1 - Adicionar palavra ao dicionário\n2 - Buscar palavra no dicionário\n3 - Imprimir dicionário\n4 - Testar desempenho\n5 - Compactar dicionário\n6 - Encerrar\n\nOperação: ";
		cin>>op;
		system ("cls");	
		switch (op){	
			case 1:{
				data input;
				cin.ignore();
				cout<<"Digite a palavra (máximo de 100 caracteres): ";
				cin.getline(input.word,100);
				t->add(&t,input);
				size++;
				break;
			}
			case 2:{
				tree* aux;
				data input;
				int NOp;
				cin.ignore();
				cout<<"Digite a palavra (máximo de 100 caracteres): ";
				cin.getline(input.word,100);
				system("cls");
				aux = t->search(input,t,1,&NOp,false);
				cout<<"Resultado:\nQuantidade de operações Registradas: "<<NOp;	
				cout<<"\nNúmero médio esperado de operações: "<<round(log2(size))<<"\n";
				if (aux == NULL){
					cout<<"'"<<input.word<<"' não está presente no dicionário.\n\n";
				}
				else{
					cout<<"'"<<input.word<<"' está presente no dicionário, no endereço de memória ["<<aux<<"].\n\n";
				}
				system("pause");
				break;
			}
			case 3:{
				cout<<"Métodos de Impressão: \n\n";
				cout<<"Método de pré-ordem: {";
				t->print("pre-order",t);
				cout<<" }\n";
				
				cout<<"Método de em-ordem:  {";
				t->print("in-order",t);
				cout<<" }\n";
				
				cout<<"Método de pos-ordem: {";
				t->print("pos-order",t);
				cout<<" }\n\n\n";
				system("pause");
				break;
			}
			case 4:{
				data array[size];
				turnToArray(t,array,0);
				int OpTree[10],OpArray[10];	
				
				for (int i=0;i<10;i++){
					OpArray[i] = 0;
				}	
				srand(time(NULL));	
				int definedValues = rand()%size;
				
				for (int i=0;i<definedValues;i++){
					int value = rand()%size;
					t->search(array[value],t,1,&OpTree[i],false);	
					for (int j=0;j<size;j++){
						if (array[0].word == array[value].word){
							break;
						}
						else{
							OpArray[i]++;
						}
					}
				}
				
				for (int i=0;i<size-definedValues;i++){
					data aux[size - definedValues];
					
					for (int j=0;j<100;j++){
						aux[i].word[j] = rand()%26 +97;
					}
					
					t->search(aux[i],t,1,&OpTree[definedValues + i],false);
					OpArray[definedValues + i] = size + 1;
				}
				
				int Ttree=0,Tarray=0;
				
				for (int i=0;i<size;i++){
					Ttree = Ttree + OpTree[i];
					Tarray = Tarray + OpArray[i];
				}
				cout<<"Número de palavras pesquisadas: 10\n\nNúmero de Operações:\nÁrvore: "<<Ttree<<"\nVetor: "<<Tarray<<"\n\n\n";
				system("pause");	
				break;
			}
			case 5:{
				data aux;
				int val;
				cout<<"Digite uma palavra para ver sua forma compactada: ";
				cin>>aux.word;
				system ("cls");
				cout<<"A partir da raíz da árvore '0' significa deslocar para a esquerda e '1' deslocar a direita,\nse não houverem números, o item é a raíz da árvore.\n\n";
				cout<<aux.word<<" = ";
				t->search(aux,t,0,&val,true);
				cout<<"\n\n";
				system("pause");
				
				break;
			}
			case 6:{
				return 0;
				break;
			}
			default:{
				cout<<"[ERRO]Operação inexistente.\n\n";
				system("pause");
				break;
			}
		}	
		system("cls");
	}
}			
