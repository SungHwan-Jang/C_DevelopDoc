#include <stdio.h>
#include "monster_repo.h"

//extern int g_gold; //g_gold�� static ������ �Ǿ��־� extern���� �ҷ��ý�, ��ũ������ �߻��Ѵ�.

int main(void) {
	add_monster();
	printf("# monsters : %d\n", g_mob_counter);
	//printf("# monsters : %d\n", g_gold); 
	return 0;
}