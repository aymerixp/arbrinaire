/*
 * source : http://www.thegeekstuff.com/2013/02/c-binary-tree/
 */
#include <stdlib.h>
#include <stdio.h>
#include "../libraire/libft.h"

typedef struct		bin_tree
{
	int				id;
	int				data;
	struct bin_tree	*right;
	struct bin_tree	*left;
}					node;

void	insert(node **tree, int val)
{
	static int i = 0;
	node *temp;
	temp = NULL;

	if(!(*tree))
	{
		/*
		ft_putendl("malloc");
		*/
		temp = (node *)malloc(sizeof(node));
		temp->left = NULL;
		temp->right = NULL;
		temp->data = val;
		temp->id = i++;
		*tree = temp;
		return;
	}

	if(val < (*tree)->data)
	{
		/*
		ft_putstr("insertion a gauche");
		ft_putchar(' ');
		ft_putnbr(val);
		ft_putchar('\n');
		*/
		insert(&(*tree)->left, val);
	}
	else if(val > (*tree)->data)
	{
		/*
		ft_putstr("insertion a droite");
		ft_putchar(' ');
		ft_putnbr(val);
		ft_putchar('\n');
		*/
		insert(&(*tree)->right, val);
	}
	// print une adresse
	// printf("%p\n", &(*tree)->right);
}

void	organize(node **tree)
{
	node *copy;
	copy = (*tree);

	ft_putnbr(copy->data);
	ft_putchar('\n');
	ft_putendl("========");

	node *node_right;
	node *node_left;
	node_left = NULL;
	node_right = NULL;
	node_right = copy->right;
	node_left = copy->left;

	// RIGHT
	while (node_right != NULL)
	{
		ft_putnbr(node_right->data);
		ft_putstr("R\n");
		node_right = node_right->right;
	}

	ft_putendl("========");

	// LEFT
	while (node_left != NULL)
	{
		ft_putnbr(node_left->data);
		ft_putstr("L\n");
		node_left = node_left->left;
	}
	ft_putchar('\n');
}

void	deltree(node *tree)
{
	if (tree)
	{
		deltree(tree->left);
		deltree(tree->right);
		free(tree);
	}
}

node	*search(node **tree, int val)
{
	if(!(*tree))
		return NULL;

	if(val < (*tree)->data)
	{
		search(&((*tree)->left), val);
	}
	else if(val > (*tree)->data)
	{
		search(&((*tree)->right), val);
	}
	else if(val == (*tree)->data)
	{
		return *tree;
	}
	return (*tree);
}

node	*recherche_arbre(node **tree, int val)
{
	if ((*tree) == NULL)
		return (NULL);
	if (val < (*tree)->data)
		recherche_arbre(&((*tree)->left), val);
	else if (val > (*tree)->data)
		recherche_arbre(&((*tree)->right), val);
	else if (val == (*tree)->data)
		return (*tree);
	return (*tree);
}

void	opti_arbre_rec(node *arbre, node **opti)
{
	if (arbre != NULL)
	{
		opti_arbre_rec(arbre->left, opti);
		insert(opti, arbre->data);
		opti_arbre_rec(arbre->right, opti);
	}
}

void	affiche_arbre_rec(node *arbre)
{
	if (arbre != NULL)
	{
		affiche_arbre_rec(arbre->left);
		if (arbre->left != NULL)
		{
			ft_putchar(',');
		}
		ft_putchar('[');
		ft_putnbr(arbre->id);
		ft_putchar(':');
		ft_putnbr(arbre->data);
		ft_putchar(']');
		//ft_putstr(" ");
		if (arbre->right != NULL)
		{
			ft_putchar(',');
		}
		affiche_arbre_rec(arbre->right);
	}
}

int		main(int ac, char **av)
{
	node *root;
	//node *tmp;
	root = NULL;
	//tmp = NULL;
	node *opti;
	opti = NULL;

	if (ac == 1)
	{
		ft_putstr("Erreur : manque les parametres");
		return (0);
	}

	int i;
	i = 1;
	while (i < ac)
	{
		insert(&root, ft_atoi(av[i]));
		i++;
	}

	//organize(&root);
	affiche_arbre_rec(root);
	ft_putchar('\n');
	opti_arbre_rec(root, &opti);
	affiche_arbre_rec(opti);
	ft_putstr("\nresultat de la recherche : ");
	ft_putnbr(recherche_arbre(&root, 85)->id);
	//affiche_arbre_rec(root, &opti);

	/* Search node into tree */
	/*
	tmp = search(&root, 9);
	if (tmp)
		printf("\nSearched node = %d\n", tmp->data);
	else
		printf("\nData Not found in tree.\n");
	*/
	/* Deleting all nodes of tree */
	deltree(root);
}
