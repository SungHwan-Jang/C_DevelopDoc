#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

#define MAX_DB 128
#define MAX_LEN 1024

typedef struct _address{
	int id;
	int set;
	char name[MAX_LEN];
	char email[MAX_LEN];
}address;

typedef struct _database{
	address rows[MAX_DB];
}database;

typedef struct _connection{
	FILE* file;
	database* db;
}connection;

void error_print(const char* message){
	if(errno)
		perror(message);
	else
		printf("%s\n", message);
	exit(1);
}

void database_filetomem(connection* conn){

	int rc = fread(conn->db, sizeof(database), 1, conn->file);
	if(rc!=1)
		error_print("file read error!");
}

connection* database_open(const char* filename, char mode){
	
	connection *conn = malloc(sizeof(connection)); //HEAP
	if(!conn)
		error_print("connection memory create error!");

	conn->db = malloc(sizeof(database)); //HEAP
	if(!conn->db)
		error_print("database memory create error!");

	if(mode == 'c'){
		conn->file = fopen(filename, "w");
	}
	else{
		conn->file = fopen(filename, "r+");
		database_filetomem(conn);
	}
	return conn;
}

void database_memtofile(connection* conn){
	rewind(conn->file);
	int wc = fwrite(conn->db, sizeof(database), 1, conn->file);
	if(wc != 1)
		error_print("file save error!");

	wc = fflush(conn->file);
}

void database_write(connection* conn, const int id, const char* name, const char* email){
	if(conn->db->rows[id].set != 0)
		error_print("Aready exist!");
	else{
		conn->db->rows[id].id = id;
		conn->db->rows[id].set = 1;
		strncpy(conn->db->rows[id].name, name, MAX_LEN);
		strncpy(conn->db->rows[id].email, email, MAX_LEN);
	}

}

void database_get(connection* conn, const int id){
	if(conn->db->rows[id].set != 1)
		error_print("No exist!");
	else{
		printf("id:%d name:%s email:%s\n", conn->db->rows[id].id, conn->db->rows[id].name, conn->db->rows[id].email); 
	}

}

int main(int argc, char** argv){
	connection* connect;
	char *filename;
	char mode;
	int id = -1;

	if(argc < 3)
		printf("USAGE: ./file <database> <mode> [-data <id, name, email>]\n");
	else{
		filename = argv[1];
		mode = argv[2][0];
		if(argc>3)
			id = atoi(argv[3]);
		
		connect = database_open(filename, mode);
		
		switch(mode){
			case 'c':
				connect = database_open(filename, mode);
				break;
			case 's':
				if(argc>5){
					char *name = argv[4];
					char *email = argv[5];
					database_write(connect, id, name, email);
				}
				else
					error_print("Need ID, NAME, EMAIL");
				break;
			case 'l':
				//if(id != -1)
					database_get(connect, id);
				//else
				//	error_print("Need ID");
				break;
			case 'd':

				break;
			case 'g':

				break;

			default :
				printf("<mode> c:create, s:save, l:ALL load, d:delete, g:get item\n");

		}

		database_memtofile(connect);
	}

	return 0;
}
