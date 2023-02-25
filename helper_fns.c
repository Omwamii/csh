#include "shell.h"

/**
  *print_prompt - prints CL prompt
  *@s: string to print to prompt
  */

void print_prompt(char *s)
{
	if (write(1, s, strlen(s)) == -1)
		perror("Error");
}

/**
  *handle_cd2 - handles cd without input(helps handle_cd
  *@olddir: path to the old directory before changing
  *@curdir: path to current directory after changing
  */
void handle_cd2(__attribute__((unused)) char *curdir, char *olddir)
{
	char *cur_dir = cur_dir, *old_dir = olddir;
	size_t size = 0;

	if (chdir(getenv("HOME")) != 0)
		perror("cd");
	else
	{
		cur_dir = getcwd(NULL, size);
		if (cur_dir == NULL)
			perror("Error"); /* can't get current */
		else
		{
			setenv("OLDPWD", old_dir, 1);
			setenv("PWD", cur_dir, 1);
		}
	}
}

