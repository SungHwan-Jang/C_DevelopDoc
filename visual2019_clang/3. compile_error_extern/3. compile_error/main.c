#include <stdio.h>
#include "monster_repo.h"

extern int g_mob_counter; //monster_repo.h �� �ش� extern�� �����ص��ȴ�.
// public�� ����������... extern �������� ������ ���� �ֱ⿡ �ְ� ������ ����.

int main(void) {
	add_monster();
	printf("# monsters : %d\n", g_mob_counter);

	return 0;
}