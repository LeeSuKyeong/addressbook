#define _CRT_SECURE_NO_WARNINGS
#include "addr_book.h"

int main(int argc, char* argv[]){

	//exe ���� ���� �ܿ��� �ּ�ó���ϼ���
	if (chk_argc(argc)) {
		return 0;
	}

	Address* list = (Address*)malloc(sizeof(Address)); //create address list
	Address* tail = list; //end node in list

	load(&tail);
	menu(&list, &tail);
	free_mem(list);
	return 0;

}
