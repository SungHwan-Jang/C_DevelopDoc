#include <stdio.h>
#include "monster_repo.h"

extern int g_mob_counter; //monster_repo.h 에 해당 extern을 선언해도된다.
// public과 유사하지만... extern 선언으로 누구나 쓸수 있기에 주객 전도된 느낌.

int main(void) {
	add_monster();
	printf("# monsters : %d\n", g_mob_counter);

	return 0;
}