#pragma once
extern int g_mob_counter;
//static int g_gold; // static 전역 변수는 외부에서 불러올수 없기에 헤더 파일에도 추가하지 않는다.
void add_monster(void);
void add_key(void);
// static void can_not_access(void); //기본적으로 static 함수는 외부에서 불러올수 없기에 헤더 파일에도 추가하지 않는다.