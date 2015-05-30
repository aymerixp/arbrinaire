/*
 * source : http://www.thegeekstuff.com/2013/02/c-binary-tree/
 */
#include <stdlib.h>
#include <stdio.h>
#include "../libraire/libft.h"

typedef struct		bin_tree
{
	int				data;
	struct bin_tree	*right;
	struct bin_tree	*left;
}					node;

void	insert(node **tree, int val)
{
	node *temp;
	temp = NULL;

	if(!(*tree))
	{
		temp = (node *)malloc(sizeof(node));
		temp->left = temp->right = NULL;
		temp->data = val;
		*tree = temp;
		return;
	}

	if(val < (*tree)->data)
		insert(&(*tree)->left, val);
	else if(val > (*tree)->data)
		insert(&(*tree)->right, val);
}

void	print_preorder(node *tree)
{
	if (tree)
	{
		printf("%d ",tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}

void	print_inorder(node *tree)
{
	if (tree)
	{
		print_inorder(tree->left);
		printf("%d ",tree->data);
		print_inorder(tree->right);
	}
}

void	print_postorder(node *tree)
{
	if (tree)
	{
		print_postorder(tree->left);
		print_postorder(tree->right);
		printf("%d ",tree->data);
	}
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

int		main(int ac, char **av)
{
	node *root;
	node *tmp;
	root = NULL;
	tmp = NULL;

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

	/* Printing nodes of tree */
	printf("Pre Order Display\n");
	print_preorder(root);

	printf("In Order Display\n");
	print_inorder(root);

	printf("Post Order Display\n");
	print_postorder(root);

	/* Search node into tree */
	tmp = search(&root, 900);
	if (tmp)
		printf("\nSearched node = %d\n", tmp->data);
	else
		printf("\nData Not found in tree.\n");
	/* Deleting all nodes of tree */
	deltree(root);
}
