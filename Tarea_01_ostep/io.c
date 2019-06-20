#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

FILE *file;
int numASCII;
bool existeArchivo;

int exists(const char *fname)
{
    //FILE *file;
    if ( (file = fopen(fname, "r") ) )
    {
		// El archivo existe
		existeArchivo = true;
        //fclose(file);
        return 1;
    }
    
    // El archivo no existe
    existeArchivo = false;
    return 0;
}

int main()
{
	
	char s[11];
	fgets(s,11, stdin);
	//printf( "\nEl nombre del archivo es: %s",s );
	//stdin;
	exists(s);
	if(existeArchivo){
		//printf("El archivo existe\n");
		printf("\n\n");
		// Hacer si el archivo existe
		
		fseek(file,0,SEEK_END); // Me ubico en el último caracter
		
		int i = 0;
		
		while(ftell(file)!=0){
			
			numASCII = fgetc(file);
			if(numASCII!=10 && numASCII!=-1)
				printf("%c",numASCII);
			else
				printf("\n");
			
			fseek(file,( i*-1 ),SEEK_END);
			i++;
		}
		
		if(ftell(file)==0){
			numASCII = fgetc(file);
			if(numASCII!=10 && numASCII!=-1)
				printf("%c",numASCII);
			else
				printf("\n");
		}
		
		printf("\n\n");
		
	}
	else
		printf("El archivo no existe\n");
	
	fclose(file);
	return 0;
}
