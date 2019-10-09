#include<stdio.h>
#include<mysql.h>
MYSQL_ROW row;
MYSQL *con;
MYSQL_RES *res;
int num_fields;
int num_rows;
char *server = "localhost";
char *user = "Minor";
char *password = "minor1";
char *database = "RTable";

void finish_with_error(MYSQL *con){
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

// ENTER DB NAME TO BE ENTERED
void createDatabase(char * DBName){
  if(mysql_real_connect(con, server, user, password, NULL, 0, NULL, 0) == NULL){
    finish_with_error(con);
  }
  if (mysql_query(con, "CREATE DATABASE RTable")){
    finish_with_error(con);
  }
}

// RECEIVE TABLE NAME & AND FIELDS TO BE ENTERED
void createTable(char * TableName){
  printf("If this table exists, it will be dropped. Do you accept? (y/n)\n");

  char choice;
  scanf("%c", &choice);

  if(choice == 'y' || choice == 'Y'){
    if(mysql_query(con, "DROP TABLE IF EXISTS DISTANCES")){
        finish_with_error(con);
    }

    if (mysql_query(con, "CREATE TABLE DISTANCES(A FLOAT, B FLOAT, C FLOAT, D FLOAT)")){
      finish_with_error(con);
    }
  }
  else{
    printf("Table already exists!");
  }
}

// RECEIVE VALUES TO BE ENTERED
void insertValues(){
  if(mysql_query(con, "INSERT INTO DISTANCES VALUES(4.70, 5.75, 3.99, 4.12)")){
    finish_with_error(con);
  }
}

int main(int argv, char** argc){
  con = mysql_init(NULL);
  if(con == NULL){
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }
  //CREATE DATABASE BEFORE next line.

  if(mysql_real_connect(con, server, user, password, database, 0, NULL, 0)==NULL){
    finish_with_error(con);
  }

  if(mysql_query(con, "SELECT * FROM DISTANCES")){
    finish_with_error(con);
  }
  res = mysql_store_result(con); //  retrieves all data from the DISTANCES table.
  //MYSQL_RES is a structure for holding a result set
  if(res == NULL){
    finish_with_error(con);
  }

  num_rows = mysql_num_rows(res);
  num_fields = mysql_num_fields(res); //num_fields = no. of columns

  int mat[num_rows][num_fields];
  int mat_i = 0;

  while(row = mysql_fetch_row(res)){
    for(int j=0; j<num_fields; j++){
      mat[mat_i][j] = (int)row[j] ? row[j] : NULL;
      printf("%s ", row[j] ? row[j] : "NULL");
    }
    mat_i++;
    printf("\n");
  }

  printf("\n");

  for(int i=0; i<num_rows; i++){
    for(int j=0; j<num_fields; j++){
      printf("%d ", mat[i][j]);
    }
    printf("\n");
  }

  printf("\n");
  printf("TIME(S) TABLE: \n");
  if(mysql_query(con, "SELECT * FROM TIMES")){ // returns 0, hence doesnt enter block
    finish_with_error(con);
  }

  printf("TEST DEBUG: Code queried\n");

  res = mysql_store_result(con);

  printf("TEST DEBUG: Result saved in MYSQL_RES pointer\n");

  if(res == NULL){
    finish_with_error(con);
  }

  num_fields = mysql_num_fields(res);
  printf("TEST DEBUG: Number of columns = %d\n", num_fields);

  while(row = mysql_fetch_row(res)){
    for(int i=0; i<num_fields; i++){
      printf("Column %d %p\n", i, row[i] ? (int)row[i] : NULL);
    }
    printf("\n");
  }

  mysql_free_result(res);
  mysql_close(con);
  exit(0);
}
