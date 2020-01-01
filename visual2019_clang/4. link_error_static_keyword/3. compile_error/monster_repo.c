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
	// static이 없으면 지역변수, 함수 반환시 그 변수도 사라짐. 
	// static을 쓰면 개념상 전역변수. 허나 그 함수 안에서만 접근가능. 즉, 변수가 반환되어도 여전히 값은 저장되어 있음.
}

static void can_not_access(void) {
	//Can not access main.
}