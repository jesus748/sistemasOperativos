#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>

#include <sys/types.h> // ASN
#include <sys/wait.h>  // ASN  
  
#define max_args 13  /*Numero maximo de argumentos (-1) cuando se trate de un comando externo*/
#define maxln_Com_Amb 105 /*Numero de caracteres maximo para comando las variables de ambiente*/

/*Declarando variables*/
char comando[maxln_Com_Amb]; /*Esta var lee el comando que ingrese el usuario*/
char *args[max_args]; /*en este arreglo se almacenan los argumentos del comando ingresado*/

/*Declarando variables de ambiente*/
char SHELL[maxln_Com_Amb];
char PATH[maxln_Com_Amb];
char HOME[maxln_Com_Amb];
char PWD[maxln_Com_Amb];

/*Declarando cabeceras de funciones*/
void separaArgs(void); /*Esta funcion separa la cadena ingresada por el usuario en 
  palabras individuales, la 1ra palabra sera considerada comando y el resto sus argumentos*/
void listaDir(void); /*Esta func ejecuta el comando dir*/
void eco(void); /*Esta func ejecuta el comando echo*/
void comExterno(void); /*Esta func ejecuta lo que se considere comandos externos*/

FILE *file; // ASN
int numASCII; // ASN
int leyendoDesdeArchivo=1; // ASN
bool existeArchivo=false; // ASN
char linea[1024]; // ASN

int pausa=1;

int exists(const char *fname) // ASN
{
	//FILE *file;
    if ( (file = fopen(fname, "r") ) )
    {
		// El archivo existe
		existeArchivo = true;
        //fclose(file);
        return 1;
    }
    else{
		// El archivo no existe
		existeArchivo = false;
		return 0;
	}
}

//main(void){ // ASN
int main(void){
	int continuar=1;
	
	/*Inicializando variables de ambiente*/
	getcwd(PWD,maxln_Com_Amb); /*Obteniendo la ruta actual y cargando en PWD*/
	strcpy(PATH,getenv("PATH")); /*Obteniendo el directorio del path y cargando en PATH*/
	
	/*strcpy(HOME,getenv("HOME")); Obteniendo el directorio home y cargando en HOME
		strcpy(SHELL,getenv("SHELL")); Obteniendo el directorio de shell y cargando en SHELL
		NOTA: en el documento con las especificaciones del programa se pide que el valor
		de SHELL y de HOME sea la ruta absoluta desde donde se esta ejecutando el shell por
		ello no he dejado los valores que se obtienen desde el sistema, en su lugar ambas
		valdran El primer valor de PWD*/
	strcpy(HOME,PWD);
	strcpy(SHELL,PWD);

	do{ /*Ciclo principal*/
		if(leyendoDesdeArchivo){
			
			printf(" %s /myshell-> ",PWD); /*Imprimiendo el indicador del shell (directorio actual)*/
			__fpurge(stdin); /*Limpiando el buffer de entrada de teclado*/
			memset(comando,'\0',maxln_Com_Amb); /*Borrando cualquier contenido previo de comando*/
			scanf("%[^\n]s",comando); /*Esperar hasta que el usuario ingrese algun comando*/
			
			if(getchar()==10 && strlen(comando)<1){
				printf("Shell activada\n");
				pausa=1;
			}
			
		}
		
		if(pausa){
			if(strlen(comando)>0){ /*Actuar solo si comando contiene algo y solo un enter*/
				separaArgs(); /*Separar comando de sus argumentos*/
				if(strcmp(comando,"cd")==0){ /*Si el comando es cd*/
					if(args[1]) /*Verificar que cuente con el argumento necesario*/
						if(chdir(args[1])!=0) /*La func chdir hace el cambio de directorio si regresa un valor 
							diferente de cero la operacion no se pudo ejecutar con exito*/
							printf("Error! %s no existe o no se puede cambiar a este directorio\n",args[1]);
					else getcwd(PWD,maxln_Com_Amb);/*En caso de cambio exitoso actualizar PWD*/
				}
				else if(strcmp(comando,"dir")==0){
					listaDir(); /*Si el comando es el dir llamar a la func correspondiente*/
					//printf("Dentro de DIR, comando: >%s<\n",comando);
				}
				else if(strcmp(comando,"clr")==0)
					strcpy(comando,"clear"), comExterno(); /*Para limpiar la pantalla aprovecho la
					funcion de comando externo y le paso como comando clear. Otra seria
					implementar la func clear de la libreria ncurses.h pero tendria que 
					modificar bastantes cosas*/
				else if(strcmp(comando,"environ")==0){
					printf(" Variables de ambiente:\n");/*Mostrar los valores de las var de ambiente*/
					printf("  HOME=%s\n  PWD=%s\n",HOME,PWD);
					printf("  SHELL=%s\n  PATH=%s\n",SHELL,PATH);
				}
				/*
				else if(strcmp(comando,"help")==0){ // ASN
					//printf("%s",comando);
					strcpy(comando,"help"), comExterno();
					//printf("\n PRUEBA\n");
				}
				*/
				else if(strcmp(comando,"pause")==0){ // ASN
					pausa=0;
				}else if(strcmp(comando,"echo")==0){
					if(args[1]) eco(); /*Si hay al menos 1 argumento llamar la func que ejecuta echo*/
				}
				else if(strcmp(comando,"pwd")==0)
					printf("%s\n",PWD); /*Mostrar el contenido de PWD (Directorio actual)*/
				else if(strcmp(comando,"quit")==0)
					continuar=0; /*Cambiar el valor de continuar para que termine*/
				//else if(strcmp(comando,"programname")==0){
				//	continuar=0; /*Cambiar el valor de continuar para que termine*/
				//}
				else if( strcmp(comando,"myshell")!=0 )
					comExterno(); /*Cualquier otra entrada llamar a comExterno*/
				
				if( strcmp(comando,"myshell")==0 || leyendoDesdeArchivo==0){ // ASN
					if(leyendoDesdeArchivo==1)
						exists(args[1]);
					
					if(existeArchivo){
						if( fgets(linea, 1024, (FILE*) file) != NULL ) {
							strcpy(comando, strtok(linea,"\n") );
							leyendoDesdeArchivo=0;
						}
						else{
							fclose(file);
							leyendoDesdeArchivo=1;
							existeArchivo=false;
						}
					}
					else{
						printf("El nombre de archivo dado no es valido\n");
						printf("POR FAVOR INTRODUZCA UN NOMBRE VALIDO\n");
					}
				}
				
				
			}
		}
		else
			printf("El shell está en pausa, oprima solamente la tecla ENTER para desbloquear\n");
	}while(continuar); /*Volver a ejecutar mientras no ingresen quit*/
	return 0;
}

void separaArgs(void){
	int i;
	for(i=0;i<(max_args-1);i++) args[i]=NULL; /*Borrar argumento previo que pudiera existir*/
	strtok(comando," "), i=0; /*separar palabras individuales usando tokens (espacio vacio)*/
	args[i]=comando; /*El 1er argumento sera comando por un requerimiento de execvp*/
	while((args[++i]=strtok(NULL," "))!=NULL && i<(max_args-2));
}

void listaDir(void){
	char ruta[maxln_Com_Amb]; /*Var auxiliar para formar la ruta solicitada por el usuario*/
	int archs; /*Numero de archivos encontrados en el dir indicado*/
	int cnt=-1;
	struct dirent **lista; /*var que guarda la lista de archivos/dirs encontrados*/
	strcpy(ruta,PWD); /*Suponemos que el dir solicitado es de la ruta actual*/
	
	if(args[1]) strcat(ruta,"/"), strcat(ruta,args[1]);
    /*pero si se trata de una(s) subcarpeta(s) las concatenamos*/
		archs=scandir(ruta,&lista,0,alphasort); /*Mandamos revisar el dir solicitado*/
		
	if(archs<0) /*En caso de falla enviar mensaje*/
		printf("Error no existe o no se pudo leer [%s]\n",ruta);
	else if(archs==2){ /*Si solo encontro los directorios . (actual) y .. (padre)
		consideraremos que el dir esta vacio a efectos practicos*/
		printf(" El directorio [%s] esta vacio",ruta);
	}
	else{ /*Si se encontra al menos un archivo/directorio mostrarlo*/
		printf(" Archivos y carpetas encontrados en: [%s]\n",ruta);
		while(++cnt<archs)
		if(strcmp(lista[cnt]->d_name,".")!=0 && strcmp(lista[cnt]->d_name,"..")!=0)
			printf(" %s\n",lista[cnt]->d_name);
	}
}

void eco(void){
  int i;
  int j;
  int k=0;
  char aux[6];
  while(args[++k]){ /*Aqui hay que recorrer argumento por  argumentos mientra este tenga valor*/
    for(i=0;i<strlen(args[k]);i++){ /*Para imprimir lo hare de caracter en caracter para 
      interceptar el $ en caso de que este presente en cuanquier posicion*/
      if(args[k][i]!='$') printf("%c",args[k][i]);
      else{ /*Si se encuentra el $ ver si le sigue el nombre de alguna variable de ambiente 
        en caso afirmativo imprimir el valor correspondiente, sino imprimir el simbolo*/
        j=-1;
        while(++j<5 && (i+j+1)<strlen(args[k]) && args[k][i+j+1]!='\0')
          aux[j]=args[k][i+j+1]; /*En aux copiar la sub cadena que sigue al simbolo $*/
        aux[j]='\0';
        if(strcmp(aux,"SHELL")==0) /*Ver si hay que imprimir el valor de SHELL*/
          printf("%s",SHELL), i+=5;
        else if(strncmp(aux,"PATH",4)==0) /*Idem PATH*/
          printf("%s",PATH), i+=4;
        else if(strncmp(aux,"PWD",3)==0) /*Idem PWD*/
          printf("%s",PWD), i+=3;
        else if(strncmp(aux,"HOME",4)==0) /*Idem HOME*/
          printf("%s",HOME), i+=4;
        else printf("$"); /*Ninguno de los anteriores el $ es solo un caracter mas*/
      }
    }
    printf(" "); /*Imprimir el espacio entre los distintos argumentos*/
  }
  printf("\n"); /*Imprimir un salto de linea al final del ultimo argumento*/
}

void comExterno(){ /*Ejecutar entradas consideradas comando externos*/
	int pid=0;
	int status;
	pid=fork(); /*Crear un proceso hijo*/
	if(pid<0)
		printf("Error! no se pudo crear un proceso hijo");
	if (pid==0){
		status=execvp(comando,args); /*Trata de ejecutar el comando y los argumentos que tenga*/
		
		printf("Comando: %s\n",comando);
		
		if(status){
		  printf("Error! %s no se reconoce o no se pudo ejecutar\n",comando);
		  //printf("status: %d\n",status); // ASN
		  exit(1); /*Como no se pudo ejecutar el comando cerramos el proceso hijo*/
		}
	}else
		wait(NULL); /*esperar a que termine el proceso hijo*/
}
