#include <stdlib.h>
#include "../libraire/libft.h"
/* source :
 * http://www.cprogramming.com/tutorial/c/lesson18.html
 * 
A la difference de la liste chaînée, il y a deux elements suivants : right et left

                  2
        1                  3
0          1                     4

pour chaque noeud : a gauche, tous les elements qui sont plus petits et a droite
tous les elements qui sont plus grands ou egaux

arbre binaire avec un parent :
typedef struct                 s_btree
{
      struct s_btree           *parent; // le previous d'une liste doublement chainees pour comparer
      struct s_btree           *right;
      struct s_btree           *left;
      void                     *data;
}                              t_btree;

parcours d'un arbre
premier type : en profondeur (DFS)
" je parcours a gauche, je parcours moi meme, je parcours a droite"

parcours infixe ?
parcours prefixe ?

deuxieme type de parcours : parcours en largeur (BFS)

pour ajouter une nouvelle valeur dans l'arbre on va utiliser dichotomie
 */

typedef struct		s_btree // node
{
	int				key_value;
	int				indice;
	struct s_btree	*left;
	struct s_btree	*right;
}					t_btree;

t_btree *root = 0;

void	destroy_tree(t_btree *leaf)
{
	if (leaf != 0)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		free(leaf);
	}
}

/*
 * The following insert function will create a new tree if necessary;
 * it relies on pointers to pointers in order to handle the case of a
 * non-existent tree (the root pointing to NULL).
 * In particular, by taking a pointer to a pointer,
 * it is possible to allocate memory if the root pointer is NULL.
 */
void		insert(int key, t_btree **leaf, int indice)
{
	if (*leaf == 0)
	{
		*leaf = (t_btree*)malloc(sizeof(t_btree));
		(*leaf)->key_value = key;
		(*leaf)->indice = indice;
		/* initialize the children to null */
		(*leaf)->left = 0;
		(*leaf)->right = 0;
	}
	else if (key < (*leaf)->key_value)
	{
		insert(key, &(*leaf)->left, indice);
	}
	else if (key > (*leaf)->key_value)
	{
		insert(key, &(*leaf)->right, indice);
	}
}

t_btree		*search(int key, t_btree *leaf)
{
	if (leaf != 0)
	{
		if (key == leaf->key_value)
		{
			return (leaf);
		}
		else if (key < leaf->key_value)
		{
			return (search(key, leaf->left));
		}
		else
		{
			return (search(key, leaf->right));
		}
	}
	else
		return (0);
}

int		main(void)
{
	t_btree *nono;
	t_btree *reponse;
	int i;

	i = 0;
	nono = NULL;
	reponse = NULL;
	insert(12, &nono, i++);
	insert(11, &nono, i++);
	
	reponse = search(11, nono);
	ft_putnbr(reponse->indice);

	return (0);
}
