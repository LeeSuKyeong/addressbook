#include "addr_book.h"

void menu(Address** list, Address** tail) {

	bool flag = true;
	int num;
	system("cls");
	
	while (flag) {
		printf("\n [ Address Book ]\n\n");

		printf(" 1. ����ó ���\n");
		printf(" 2. ����ó �˻�\n");
		printf(" 3. ����ó ���\n");
		printf(" 4. ����ó ����\n");
		printf(" 5. ����ó ����\n");
		printf(" 6. ���� �� ����\n\n");
		printf(" ����� ����� �����ϼ��� : ");
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
			printf("���α׷��� ���� �� �����մϴ�");
			save((*list)->next);
			flag = false;
			exit(0);
		default:
			printf("�߸��� �Է��Դϴ�. ����ϰ����ϴ� ����� ��ȣ�� �Է����ֽʽÿ�.\n");
			pause();
			break;
		}
		system("cls");
	}
}
void display(Address* addr) {
	int cnt = 0;
	system("cls");
	printf("\n [ ����ó ��� ] \n\n");
	while (addr != NULL) {
		printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
		addr = addr->next;
		cnt++;
	}
	printf("\n �� [%d]���� ����ó�� �����մϴ�.\n", cnt);
	pause();
	return;
}

void search(Address* addr) {
	int num;
	system("cls");
	printf("\n [ ����ó �˻� ] \n\n");
	printf(" 1. ���̵� �˻�\n");
	printf(" 2. �̸� �˻�\n");
	printf(" 3. ��ȭ��ȣ �˻�\n");
	printf(" 4. ���ư���\n\n");

	printf(" ����� ����� �����ϼ��� : ");
	scanf(" %d", &num);

	system("cls");
	switch (num) {
	case SEARCH_ID:
		int id;
		printf("\n [ ���̵� �˻� ] \n\n");
		printf(" �˻��� ���̵� �Է��ϼ��� : ");
		scanf(" %d", &id);
		printf("\n");

		search_id(addr, id);
		break;
	case SEARCH_NAME:
		char name[15];
		printf("\n [ �̸� �˻� ] \n\n");

		printf(" �˻��� �̸��� �Է��ϼ��� : ");
		scanf(" %s", &name);
		printf("\n");

		search_name(addr, name);
		break;
	case SEARCH_PHONE:
		printf("\n [ ��ȭ��ȣ �˻� ] \n\n");

		printf(" �˻��� ��ȭ��ȣ�� �Է��ϼ��� : ");
		char phone[15];
		scanf(" %s", &phone);
		printf("\n");

		search_phone(addr, phone);
		break;
	case BACK:
		break;
	default:
		printf("�߸��� �Է��Դϴ�. �ٽ� �õ����ּ���.\n");
		pause();
		break;
	}

}

void search_id(Address* addr, int id) {
	printf(" �˻��Ͻ� ���̵�� ��ġ�ϴ� ����ó�Դϴ�.\n\n");
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
	printf(" �˻��Ͻ� �̸��� �����ϴ� ����ó�Դϴ�.\n\n");
	while (addr != NULL) {
		char* result;
		if ((result = strstr(addr->name, name)) != NULL) {
			printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
			cnt++;
		}
		addr = addr->next;
	}

	printf("\n �� [%d]���� ����ó�� �˻��Ǿ����ϴ�.\n", cnt);
	pause();
	return;
}

void search_phone(Address* addr, char* phone) {
	int cnt = 0;
	printf(" �˻��Ͻ� ��ȣ�� �����ϴ� ����ó�Դϴ�.\n\n");
	while (addr != NULL) {
		char* result;
		if ((result = strstr(addr->phone, phone)) != NULL) {
			printf(" [%03d] %15s %14s  %s\n", addr->id, addr->name, addr->phone, addr->content);
			cnt++;
		}
		addr = addr->next;
	}

	printf("\n �� [%d]���� ����ó�� �˻��Ǿ����ϴ�.\n", cnt);
	pause();
	return;
}

void add(Address** tail)
{
	printf("\n [ ����ó ��� ] \n\n");
	
	Address* tmp;
	tmp = (Address*)malloc(sizeof(Address));
	
	tmp->id = ((*tail)->id) + 1;
	printf(" �̸� : ");
	scanf(" %s", tmp->name);

	printf(" ��ȭ��ȣ(- ����) : ");
	scanf(" %s", tmp->phone);

	printf(" ��� : ");
	scanf(" %s", tmp->content);

	tmp->next = NULL;
	(*tail)->next = tmp;
	*tail = (*tail)->next;

	printf("\n ����� �Ϸ��߽��ϴ�.\n");
	pause();
}
bool remove(Address* addr) {
	char ans;
	int id;

	system("cls");
	printf("\n [ ����ó ���� ] \n\n");
	printf(" ������ ���̵� �ƽʴϱ�? (y/n) \n");
	printf(" ������ ������ �����Ŵٸ� escŰ�� �����ּ��� : ");
	ans = _getch();

	if (ans == 27) {
		return false;
	}
	else if (ans == 'n' || ans == 'N') {
		int c ;
		
		printf("\n\n ������ ���̵� �˻��ϼ���\n");
		printf(" 1. ��κ��� 2. ����ó �˻�\n");
		scanf(" %d", &c);
			
		if (c == 1) display(addr->next);
		else if (c == 2) search(addr);
		else {
			printf("�߸��� �Է°��Դϴ�.\n");
			pause();
		}
		printf("\n");
	}
	else if (ans == 'y' || ans == 'Y') {

		printf("\n ������ ���̵� �Է����ּ��� : ");
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
			printf("\n �ش� ���̵� ���������ʽ��ϴ�. �ٽ� �õ����ּ��� \n");
			pause();
			return true;
		}
		else {
			char rm_ans;
			printf("\n �����ϰ��� �ϴ� ����ó \n");
			printf(" [%03d] %15s %14s  %s\n", tmp->id, tmp->name, tmp->phone, tmp->content);
			printf(" ������ �����Ͻðڽ��ϱ�? (y/n) : ");
			scanf(" %c", &rm_ans);
			if (rm_ans == 'y' || rm_ans == 'Y') {
				addr->next = tmp->next;
				free(tmp);
				printf("\n �ش� ���̵� ���� ����ó�� �����߽��ϴ�.\n\n");
			}
			else if (rm_ans == 'n' || rm_ans == 'N') {
				printf("\n �ش� ����ó ������ ����߽��ϴ�.\n\n");
			}
			else {
				printf("�߸��� �Է°��Դϴ�. �ٽýõ����ּ���\n");
				pause();
				return true;
			}
				
		}

		char chk;
		printf(" �������Ͻðڽ��ϱ�? (y/n)\n");
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
		printf("\n �߸��� �Է°��Դϴ�. �ٽ� �õ����ּ��� \n");
	}
	
	return true;

}

void save(Address* addr) {

	printf("\n [ ����ó ���� ] \n\n");

	if (addr == NULL) {
		printf(" ������ �� �����ϴ�. \n");
		pause();
		return;
	}

	if (addr->next == NULL) {
		printf(" ������ ����ó�� �����ϴ�.\n");
		pause();
		return;
	}
	
	FILE* fp = fopen("C:\\addr_book.txt", "w");

	if (fp == NULL) {
		printf(" ������ ã�� �� �����ϴ�. ���ÿ� ����ó�� �����ϴµ� �����߽��ϴ�.\n");
		fclose(fp);
		pause();
		return;
	}

	printf(" ����ó�� ���ÿ� �������Դϴ�... \n");
	while (addr != NULL) {
		fprintf(fp, "%d %s %s %s\n", addr->id, addr->name, addr->phone, addr->content);
		addr = addr->next;
	}

	fclose(fp);
	printf(" ������ �Ϸ��߽��ϴ�.\n");
}

//load address.txt
void load(Address** tail) {
	
	FILE* fp = fopen("C:\\addr_book.txt", "r");

	//create file if not exist
	if (fp == NULL) {
		printf("�о�� ������ �����ϴ�. ������ ���� �����մϴ�.\n");
		fclose(fp);
		return;
	}

	printf("������ ������ �о�ɴϴ�.\n");

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