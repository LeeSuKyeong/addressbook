#include "system.h"

void pause() {
	printf("\n���� ȭ������ ���ư����� �ƹ�Ű�� �����ּ���...\n");
	_getche();
}

// exe������ ������ �� ������ �´��� �˻�
// ������Ʈ �Ӽ�-�����-����μ�(addr_book.txt) �Է�
// release�� ����
bool chk_argc(int argc) {
	if (argc != 2) {
		printf("Error\n: use *.exe addr_book.txt\n");
		return true;
	}
	return false;
}