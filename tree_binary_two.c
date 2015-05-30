/*
 * C Program for Depth First Binary Tree Search using Recursion
 * source : http://www.sanfoundry.com/c-program-depth-first-search-using-recursion/
 */
#include <stdlib.h>
#include <stdio.h>
#include "../libraire/libft.h"

typedef struct	s_node
{
	int a;
	struct s_node *left;
	struct s_node *right;
}				t_node;

void generate(t_node **head, int num)
{
	t_node *tmp = *head, *prev = *head;

	if (*head == NULL)
	{
		*head = (t_node *)malloc(sizeof(t_node));
		(*head)->a = num;
		(*head)->left = (*head)->right = NULL;
	}
	else
	{
		while (tmp != NULL)
		{
			if (num > tmp->a)
			{
				prev = tmp;
				tmp = tmp->right;
			}
			else
			{
				prev = tmp;
				tmp = tmp->left;
			}
		}
		tmp = (t_node*)malloc(sizeof(t_node));
		tmp->a = num;
		if (num >= prev->a)
		{
			ft_putstr("oui");
			prev->right = tmp;
		}
		else// if (prev->left != NULL && prev != NULL)
		{
			ft_putstr("non");
			prev->left = tmp;
		}
	}
}

void DFS(t_node *head)
{
	if (head)
	{
		if (head->left)
		{
			DFS(head->left);
		}
		if (head->right)
		{
			DFS(head->right);
		}
		ft_putnbr(head->a);
	}
}

void delete(t_node **head)
{
	if (*head != NULL)
	{
		if ((*head)->left)
		{
			delete(&(*head)->left);
		}
		if ((*head)->right)
		{
			delete(&(*head)->right);
		}
		free(*head);
	}
}

int main(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("Erreur : manque les parametres");
		return (0);
	}
	t_node *head;
	head = NULL;
	t_node *tmp;

	int i;
	i = 1;
	while (i < ac)
	{
		generate(&head, ft_atoi(av[i]));
		i++;
	}
	tmp = head;
	DFS(tmp);
	//delete(&head);

	return (0);
}
