#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct	s_student
{
	char		name[20];
	char		surname[20];
	char		email_address[20];
	char		grade[5];
	char		state[10];
}				t_student;

char	**break_by_comma(char *line)
{
	char	**tab;
	int		i, j;
	int		index;

	i = 0;
	j = 0;
	index = 0;
	tab = (char**)malloc(sizeof(char*) * 5);
	while (line[index] != '\0')
	{
		if (j == 0)
			tab[i] = (char*)malloc(sizeof(char) * 20);
		if (line[index] == ';')
		{
			tab[i][j] = '\0';
			i++;
			j = 0;
		}
		else
		{
			tab[i][j] = line[index];
			j++;
		}
		index++;
	}
	return (tab);
}

t_student		getInfoFromStudent(char	*line)
{
	t_student	student;
	int			iter;
	int			jter;
	char		**tab;

	tab = break_by_comma(line);
	strcpy(student.surname, tab[0]);
	strcpy(student.name, tab[1]);
	strcpy(student.email_address, tab[2]);
	strcpy(student.grade, tab[3]);
	strcpy(student.state, tab[4]);
	return (student);
}

void			print_student(t_student student)
{
	printf ("%s %s\n", student.surname, student.name);
}

int				main(void)
{
	FILE		*file_descriptor;
	char		buff[255];
	t_student	current_student;

	file_descriptor = fopen("students.csv", "r");
	while (fscanf(file_descriptor, "%s", buff) > 0)
	{
		current_student = getInfoFromStudent(buff);
		if (strcmp(current_student.state, "Cluj") == 0 && atof(current_student.grade) > 8.00)
			print_student(current_student);
	}
	return (0);
}
