#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

/**
 * struct list - linked list for env vars
 * @var: hold string
 * @next: ptr to next node
 */
typedef struct list
{
	char *var;
	struct list *next;
} list_t;

int Prompt(char **env);
void *_realloc(void *ptr, unsigned int oldsize, unsigned int newsize);
size_t get_line(char **str);
int stringlen(char *str, int pos, char del);
char *ignorespace(char *str);
char **_strtok(char *str, char *del);
char **cstrtok(char *str, char *del);
char *stringcat(char *dest, char *src);
char *_strdup(char *str);
char *stringcpy(char *dest, char *src);
int stringcmp(char *s1, char *s2);
int changedirectory(char **str, list_t *env, int n);
void changedironly(list_t *env, char *current);
int builtin(char **token, list_t *env, int n, char **command);
void noninteractive(list_t *env);
void exit_shell(char **args, char *line, char **env);
char *_which(char *str, list_t *env);
int __exit(char **str, list_t *env, int n, char **command);
int _execve(char *argv[], list_t *env, int n);
void freedoubleptr(char **str);
void freelinkedlist(list_t *list);
int environment(char **str, list_t *env);
char *getenvironment(char *str, list_t *env);
list_t *envlinkedlist(char **env);
list_t *addendnode(list_t **head, char *str);
size_t printlist(list_t *h);
int deletenodeatindex(list_t **head, int index);
int _unsetenv(list_t **env, char **str);
int setenvironment(list_t **env, char **str);
int findenvironment(list_t *env, char *str);
void notfound(char *str, int n, list_t *env);
void cantcdto(char *str, int cn, list_t *env);
void illegalnumber(char *str, int cn, list_t *env);
char *inttostring(int n);

#endif

