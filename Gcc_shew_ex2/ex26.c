#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 1024

// 1. 현재 디렉터리 파악
// 2. 디렉터리의 모든 파일을 순차적으로 불러오기
// 3. 파일에서 검색어 찾기
// 4. 검색된 경우 파일 명 얻기
// 5. 검색된 파일 명 출력

int main(int argc, char** argv)
{
	DIR *dir_info;
	FILE *fp = NULL;
	char *str = NULL;
	struct dirent *dir_entry;
	int winStopConsoleFlag = 0;

	dir_info = opendir(".");              // 현재 디렉토리를 열기
	if (NULL != dir_info)
	{
		while (dir_entry = readdir(dir_info)) // 디렉토리 안에 있는 모든 파일과 디렉토리 출력
		{
			printf("%s\n", dir_entry->d_name);

			fp = fopen(dir_entry->d_name, "r");
			str = malloc(sizeof(char) * MAX_BUF_SIZE);

			while(fgets(str, MAX_BUF_SIZE, fp))
				printf("%s", str);

			fclose(fp);
			free(str);
		}
		closedir(dir_info);
	}
	scanf("%d", &winStopConsoleFlag);
}
