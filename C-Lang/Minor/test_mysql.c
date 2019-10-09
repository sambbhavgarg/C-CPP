#include<stdio.h>
#include<mysql.h>
MYSQL_ROW row;
MYSQL *con;
MYSQL_RES *res;
int num_fields;
/*
int main(int argc, char **argv){
  printf("MySQL client version: %s", mysql_get_client_info());
  exit(0);

  MYSQL *con = mysql_init(NULL);
  if(con == NULL){
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }
  if(mysql_real_connect(con, "localhost", "root", "root_pswd", NULL, 0, NULL, 0) == NULL){
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }
  if (mysql_query(con, "CREATE DATABASE RTable")){
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }
  mysql_close(con);
  exit(0);

*/
void finish_with_error(MYSQL *con){
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);
}

/*

int main(int argv, char **argc){
  MYSQL *con = mysql_init(NULL);
  if(con==NULL){
    fprintf(stderr, "%s\n", mysql_error(con));
    exit(1);
  }
  if( mysql_real_connect(con, "localhost", "Minor", "minor1", "RTable", 0, NULL, 0) == NULL){
    finish_with_error(con);
  }
  if(mysql_query(con, "DROP TABLE IF EXISTS DISTANCES, TIMES")){
    finish_with_error(con);
  }
  if (mysql_query(con, "CREATE TABLE DISTANCES(A FLOAT, B FLOAT, C FLOAT, D FLOAT)")){
    finish_with_error(con);
  }
  if(mysql_query(con, "INSERT INTO DISTANCES VALUES(4.70, 5.75, 3.99, 4.12)")){
    finish_with_error(con);
  }
  if(mysql_query(con, "INSERT INTO DISTANCES VALUES(4.70, 5.75, 3.99, 4.12)")){
    finish_with_error(con);
  }
  if (mysql_query(con, "CREATE TABLE TIMES(A FLOAT, B FLOAT, C FLOAT, D FLOAT)")){
    finish_with_error(con);
  }
  if(mysql_query(con, "INSERT INTO TIMES VALUES(4.70, 5.75, 3.99, 4.12)")){
    finish_with_error(con);
  }
  */
int main(int argv, char** argc){
  con = mysql_init(NULL);

  if(con == NULL){
    fprintf(stderr, "mysql_init() failed\n");
    exit(1);
  }
  if(mysql_real_connect(con, "localhost", "Minor", "minor1", "RTable", 0, NULL, 0)==NULL){
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
  num_fields = mysql_num_fields(res); //num_fields = no. of columns

  while(row = mysql_fetch_row(res)){
    for(int i=0; i<num_fields; i++){
      printf("%s ", row[i] ? row[i] : "NULL" );
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
