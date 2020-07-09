#include "addr_book.h"

void menu(Address** list, Address** tail) {

	bool flag = true;
	int num;
	system("cls");
	
	while (flag) {
		printf("\n [ Address Book ]\n\n");

		printf(" 1. 연락처 출력\n");
		printf(" 2. 연락처 검색\n");
		printf(" 3. 연락처 등록\n");
		printf(" 4. 연락처 삭제\n");
		printf(" 5. 연락처 저장\n");
		printf(" 6. 저장 후 종료\n\n");
		printf(" 사용할 기능을 선택하세요 : ");
		scanf(" %d", &num);
		system("cls");
		boolean r_flag = true;
		switch (num) {
		case VIEW:
			display((*list)->next);
			break;
		case SEARCH:
			search(*list);
			break;
		case ADD:
			add(tail);
			break;
		case REMOVE:
			while (r_flag) {
				r_flag = remove(*list);
			}
			break;
		case SAVE:
			save((*list)->next);
			pause();
			break;
		case EXIT:
			printf("프로그램을 저장 후 종료합니다");
			save((*list)->next);
			flag = false;
			exit(0);
		default:
			printf("잘못된 입력입니다. 사용하고자하는 기능의 번호를 입력해주십시오.\n");
			pause();
			break;
		}
		system("cls");
	}
}
void display(Address* addr) {
	int cnt = 0;
	system("cls");
	printf("\n [ 연락처 출력 ] \n\n");
	while (addr != NULL) {
		printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
		addr = addr->next;
		cnt++;
	}
	printf("\n 총 [%d]건의 연락처가 존재합니다.\n", cnt);
	pause();
	return;
}

void search(Address* addr) {
	int num;
	system("cls");
	printf("\n [ 연락처 검색 ] \n\n");
	printf(" 1. 아이디 검색\n");
	printf(" 2. 이름 검색\n");
	printf(" 3. 전화번호 검색\n");
	printf(" 4. 돌아가기\n\n");

	printf(" 사용할 기능을 선택하세요 : ");
	scanf(" %d", &num);

	system("cls");
	switch (num) {
	case SEARCH_ID:
		int id;
		printf("\n [ 아이디 검색 ] \n\n");
		printf(" 검색할 아이디를 입력하세요 : ");
		scanf(" %d", &id);
		printf("\n");

		search_id(addr, id);
		break;
	case SEARCH_NAME:
		char name[15];
		printf("\n [ 이름 검색 ] \n\n");

		printf(" 검색할 이름을 입력하세요 : ");
		scanf(" %s", &name);
		printf("\n");

		search_name(addr, name);
		break;
	case SEARCH_PHONE:
		printf("\n [ 전화번호 검색 ] \n\n");

		printf(" 검색할 전화번호를 입력하세요 : ");
		char phone[15];
		scanf(" %s", &phone);
		printf("\n");

		search_phone(addr, phone);
		break;
	case BACK:
		break;
	default:
		printf("잘못된 입력입니다. 다시 시도해주세요.\n");
		pause();
		break;
	}

}

void search_id(Address* addr, int id) {
	printf(" 검색하신 아이디와 일치하는 연락처입니다.\n\n");
	while (addr != NULL) {
		if (addr->id == id) {
			printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
			break;
		}
		addr = addr->next;
	}

	pause();
	return;
}

void search_name(Address* addr, char* name) {
	int cnt = 0;
	printf(" 검색하신 이름을 포함하는 연락처입니다.\n\n");
	while (addr != NULL) {
		char* result;
		if ((result = strstr(addr->name, name)) != NULL) {
			printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
			cnt++;
		}
		addr = addr->next;
	}

	printf("\n 총 [%d]건의 연락처가 검색되었습니다.\n", cnt);
	pause();
	return;
}

void search_phone(Address* addr, char* phone) {
	int cnt = 0;
	printf(" 검색하신 번호를 포함하는 연락처입니다.\n\n");
	while (addr != NULL) {
		char* result;
		if ((result = strstr(addr->phone, phone)) != NULL) {
			printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
			cnt++;
		}
		addr = addr->next;
	}

	printf("\n 총 [%d]건의 연락처가 검색되었습니다.\n", cnt);
	pause();
	return;
}

void add(Address** tail)
{
	printf("\n [ 연락처 등록 ] \n\n");
	
	Address* tmp;
	tmp = (Address*)malloc(sizeof(Address));
	
	tmp->id = ((*tail)->id) + 1;
	printf(" 이름 : ");
	scanf(" %s", tmp->name);

	printf(" 전화번호(- 포함) : ");
	scanf(" %s", tmp->phone);

	printf(" 비고 : ");
	scanf(" %s", tmp->content);

	tmp->next = NULL;
	(*tail)->next = tmp;
	*tail = (*tail)->next;

	printf("\n 등록을 완료했습니다.\n");
	pause();
}
bool remove(Address* addr) {
	char ans;
	int id;

	system("cls");
	printf("\n [ 연락처 삭제 ] \n\n");
	printf(" 삭제할 아이디를 아십니까? (y/n) \n");
	printf(" 삭제를 원하지 않으신다면 esc키를 눌러주세요 : ");
	ans = _getch();

	if (ans == 27) {
		return false;
	}
	else if (ans == 'n' || ans == 'N') {
		int c ;
		
		printf("\n\n 삭제할 아이디를 검색하세요\n");
		printf(" 1. 모두보기 2. 연락처 검색\n");
		scanf(" %d", &c);
			
		if (c == 1) display(addr->next);
		else if (c == 2) search(addr);
		else {
			printf("잘못된 입력값입니다.\n");
			pause();
		}
		printf("\n");
	}
	else if (ans == 'y' || ans == 'Y') {

		printf("\n 삭제할 아이디를 입력해주세요 : ");
		scanf(" %d", &id);
		bool find = false;
		Address* tmp =NULL;

		while (addr != NULL) {
			tmp = addr->next;
			if (tmp == NULL) break;
			if (tmp->id == id) {
				find = true;
				break;
			}
			addr = addr->next;
		}

		if (!find) {
			printf("\n 해당 아이디가 존재하지않습니다. 다시 시도해주세요 \n");
			pause();
			return true;
		}
		else {
			char rm_ans;
			printf("\n 삭제하고자 하는 연락처 \n");
			printf(" [%03d] %15s %14s  %s\n", tmp->id, tmp->name, tmp->phone, tmp->content);
			printf(" 정말로 삭제하시겠습니까? (y/n) : ");
			scanf(" %c", &rm_ans);
			if (rm_ans == 'y' || rm_ans == 'Y') {
				addr->next = tmp->next;
				free(tmp);
				printf("\n 해당 아이디를 가진 연락처를 삭제했습니다.\n\n");
			}
			else if (rm_ans == 'n' || rm_ans == 'N') {
				printf("\n 해당 연락처 삭제를 취소했습니다.\n\n");
			}
			else {
				printf("잘못된 입력값입니다. 다시시도해주세요\n");
				pause();
				return true;
			}
				
		}

		char chk;
		printf(" 더삭제하시겠습니까? (y/n)\n");
		scanf(" %c", &chk);
		if (chk== 'N' || chk=='n') {
			return false;
		}
		else if (chk == 'Y' || chk == 'y') {
			return true;
		}
		else {
			return true;
		}
	}
	else {
		printf("\n 잘못된 입력값입니다. 다시 시도해주세요 \n");
	}
	
	return true;

}

void save(Address* addr) {

	printf("\n [ 연락처 저장 ] \n\n");

	if (addr == NULL) {
		printf(" 저장할 수 없습니다. \n");
		pause();
		return;
	}

	if (addr->next == NULL) {
		printf(" 저장할 연락처가 없습니다.\n");
		pause();
		return;
	}
	
	FILE* fp = fopen("C:\\addr_book.txt", "w");

	if (fp == NULL) {
		printf(" 파일을 찾을 수 없습니다. 로컬에 연락처를 저장하는데 실패했습니다.\n");
		fclose(fp);
		pause();
		return;
	}

	printf(" 연락처를 로컬에 저장중입니다... \n");
	while (addr != NULL) {
		fprintf(fp, "%d %s %s %s\n", addr->id, addr->name, addr->phone, addr->content);
		addr = addr->next;
	}

	fclose(fp);
	printf(" 저장을 완료했습니다.\n");
}

//load address.txt
void load(Address** tail) {
	
	FILE* fp = fopen("C:\\addr_book.txt", "r");

	//create file if not exist
	if (fp == NULL) {
		printf("읽어올 파일이 없습니다. 파일을 새로 생성합니다.\n");
		fclose(fp);
		return;
	}

	printf("기존의 파일을 읽어옵니다.\n");

	while (!feof(fp)) {
		Address* tmp = (Address*)malloc(sizeof(Address));
		fscanf(fp, " %d %s %s %s\n", &tmp->id, &tmp->name, &tmp->phone, &tmp->content);
		tmp->next = NULL;
		(*tail)->next = tmp;
		*tail = (*tail)->next;
	}
	fclose(fp);
	return;
}

void free_mem(Address* addr) {
	Address* tmp;
	while (addr != NULL) {
		tmp = addr->next;
		free(addr);
		addr = tmp;
	}
}