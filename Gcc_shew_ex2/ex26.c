#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>

#define MAX_BUF_SIZE 1024

// 1. ���� ���͸� �ľ�
// 2. ���͸��� ��� ������ ���������� �ҷ�����
// 3. ���Ͽ��� �˻��� ã��
// 4. �˻��� ��� ���� �� ���
// 5. �˻��� ���� �� ���

int main(int argc, char** argv)
{
	DIR *dir_info;
	FILE *fp = NULL;
	char *str = NULL;
	struct dirent *dir_entry;
	int winStopConsoleFlag = 0;

	dir_info = opendir(".");              // ���� ���丮�� ����
	if (NULL != dir_info)
	{
		while (dir_entry = readdir(dir_info)) // ���丮 �ȿ� �ִ� ��� ���ϰ� ���丮 ���
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
