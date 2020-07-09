#include "system.h"

void pause() {
	printf("\n원래 화면으로 돌아가려면 아무키를 눌러주세요...\n");
	_getche();
}

// exe파일을 실행할 때 형식이 맞는지 검사
// 프로젝트 속성-디버깅-명령인수(addr_book.txt) 입력
// release로 실행
bool chk_argc(int argc) {
	if (argc != 2) {
		printf("Error\n: use *.exe addr_book.txt\n");
		return true;
	}
	return false;
}