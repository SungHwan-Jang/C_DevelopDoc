#include "monster_repo.h"

int g_mob_counter = 0;
static int g_gold = 0;

void add_monster(void) {
	++g_mob_counter;
	g_gold++;
}

void add_key(void) {
	static int keyCount = 0;
	++keyCount; 
	// static�� ������ ��������, �Լ� ��ȯ�� �� ������ �����. 
	// static�� ���� ����� ��������. �㳪 �� �Լ� �ȿ����� ���ٰ���. ��, ������ ��ȯ�Ǿ ������ ���� ����Ǿ� ����.
}

static void can_not_access(void) {
	//Can not access main.
}