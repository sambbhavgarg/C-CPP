/*File Handling
file is a collection of related data that computers treats as a single unit
FILE structure- predefined structure; stores the attributes of a file
create stream via a pointer variable using FILE structure
FILE *p;:
fopen: used to open a file(text/binary) in a specific way(read/write)[if file doesnt exist, return ERROR].
->fopen makes connection between physical file and stream, and creates a program file structure to store the
info that c needs to process file.
syntax: filepointer=fopen("filename","mode");
eg: spdata=fopen("myfirst.txt","w");
spdata=fopen("C:\\myfirst.txt","w");
fclose
fread
fwrite(if file doesnt exist it will be created)
fseek
ftell
r+: open for reading and writing(start at beginning).
w+: open for writing and reading(deletes existing data).
a+: open for writing and reading(continues from existing data if any).
*/
n
