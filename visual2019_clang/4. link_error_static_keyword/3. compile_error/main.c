#include <stdio.h>
#include "monster_repo.h"

//extern int g_gold; //g_gold는 static 선언이 되어있어 extern으로 불러올시, 링크에러가 발생한다.

int main(void) {
	add_monster();
	printf("# monsters : %d\n", g_mob_counter);
	//printf("# monsters : %d\n", g_gold); 
	return 0;
}