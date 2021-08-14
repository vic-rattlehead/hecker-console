#include <stdio.h>
#include <stdlib.h>
#define FIRSTKEY 0x0

const int exitcode_ok  	= 0x1;
const int exitcode_err 	= 0x0;
	
typedef FILE * file_ptr;

int printspr(file_ptr * file, char * filename);
char * readln(int n);
char * get_usr(char * link);

int main(void)
{
	file_ptr f;
	
	if(!printspr(&f, "sprite.txt")) exit(exitcode_err);
	
	_Bool program_on = 0x1;
	char * link;
	
	while(program_on)
	{
		printf("\nLink De la Victima> ");
		link = readln(50);
		
		if(link[FIRSTKEY] == '\n') continue;
		
		else 
		{
			if(!printspr(&f, "phrass.txt"));
			program_on = 0x0;	
		}	
	}
	printf(
		"Cuenta hackeada con éxito!\nUsuario: %s\nContraseña: *************\n\nClickea aquí para obtener la contraseña\n",
		get_usr(link)
	);
	free(link);
	return 0x0;
}

char * get_usr(char * link)
{
	char * final = (char*) calloc(20, sizeof(char));
	
	int begin = 25 ;
	int index = 0x0;
	
	for(begin, index; link[begin] != '\0'; ++begin, ++index)
		final[index] = link[begin];
		
	return final;
}

char * readln(int n)
{
	char * line = (char*) calloc(n, sizeof(char));
	
	volatile signed short int keystroke;
	volatile signed short int * keystroke_ptr = &keystroke;
	volatile signed short int where = 0x0;
	
	do
	{
		*keystroke_ptr = getchar();
		
		if(*keystroke_ptr == '\0') break;
		
		line[where] = *keystroke_ptr;
		++where;
	}
	while(keystroke != '\n');
	line[where] = '\0';
	return line;
}

int printspr(file_ptr * file, char * filename)
{
	*file = fopen(filename, "r");
	
	if (file == NULL) return exitcode_err;
	
	volatile int pix;
	volatile int * pix_ptr = &pix;
	
	while(!feof(*file))	
	{
		*pix_ptr = getc(*file);
		printf("%c", *pix_ptr);
	}
	fclose(*file);
	return exitcode_ok;
}