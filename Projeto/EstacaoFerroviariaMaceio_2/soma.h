#include<stdio.h>

#ifndef SOMA_H /*Se a biblioteca soma.h não for definida, faça-o. Esta verificação é feita para para não ter varia chamada da mesma biblioteca no mesmo programa. Só uma chamada nos satisfaz*/ 

#define SOMA_H

int soma(int a, int b){
	return a+b;
}

int subtrai(int a, int b){
	return a-b;
}
#endif