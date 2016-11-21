#include <lib.h>
#include <unistd.h>
#include <stdio.h>

int sem_create(int sem_id)
{
	message m;
	m.m1_i1 = sem_id;
	m.m1_i2 = getpid();
	printf("Process %d\n", m.m1_i2);
	int aux = (_syscall(PM_PROC_NR, PM_SEM_CREATE, &m));

	if(aux==-1)
	{
		printf("Error al crear el semaforo \n");
	}
	else
	{
		printf("El Semaforo fue creado con extio \n");
	}
	return aux;
}

int sem_terminate(int sem_id)
{
	message m;
	m.m1_i1 = sem_id;
	m.m1_i2 = getpid();
	printf("Process %d\n", m.m1_i2);
	int aux = (_syscall(PM_PROC_NR, PM_SEM_TERMINATE, &m));
	
	if(aux ==-1)
	{
		printf("Error al cerrar un semaforo \n");
	}
	else
	{
		printf("El semaforo fue terminado con exito \n");
	}
	return aux;
}

int sem_down(int sem_id)
{
	message m;
	m.m1_i1 = sem_id;
	m.m1_i2 = getpid();
	printf("Process %d\n", m.m1_i2);
	int aux = (_syscall(PM_PROC_NR, PM_SEM_DOWN, &m));

	if(aux==-1)
	{
		printf("Error al agregar un proceso queue\n");
	}
	else
	{
		printf("El proceso se agrego al queue con exito \n");
	}
	return aux;
}

int sem_up(int sem_id)
{
	message m;
	m.m1_i1 = sem_id;
	m.m1_i2 = getpid();
	printf("Process %d\n", m.m1_i2);
	int aux = (syscall(PM_PROC_NR, PM_SEM_UP, &m));

	if(aux==-1)
	{
		printf("Error al quitar un proceso del Queue \n");
	}
	else
	{
		printf("El proceso se ha quitado del queue con exito\n");
	}
	return aux;
}
