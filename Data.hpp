#ifndef __DATA_HPP
#define __DATA_HPP
#include <iostream>
using namespace std;
struct data {
	char word[100];
};

string convert (char array[100]){
	string result="";
	int cont=0;
	while (array[cont] != '\0'){
		result = result + array[cont];
		cont++;
	}	
	result = result + '\0';
	return result;
}

#endif
