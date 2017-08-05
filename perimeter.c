/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perimeter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/04 15:25:32 by exam              #+#    #+#             */
/*   Updated: 2017/08/04 17:08:35 by smifsud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_node {
	int				value;
	struct s_node	*right;
	struct s_node	*left;
}					t_node;

int		isleft = 2;
int		onleftmost = 1;
int		onrightmost = 0;
//int		fd;

void		perimeter(t_node *root)
{
	int		isfirst = 0;
	int		isright = onrightmost;
	int		print = 1;

	if (isleft == 2)
	{
		printf("%d", root->value);
		isfirst = 1;
		print = 0;
	}
	if (root)
	{
		//dprintf(fd, "DEBUG isleft: %d, onleftmost: %d, onrightmost: %d, isfirst: %d, isright: %d, this: [%d, %p], left: [%p], right: [%p]\n", isleft, onleftmost, 
		//		onrightmost, isfirst, isright, root->value, root, root->left, root->right);
		if (!(root->left) && !(root->right) && print)
		{
			printf(" %d", root->value);
			print = 0;
		}
		if (isleft)
		{
			if (onleftmost && print)
			{
				printf(" %d", root->value);
				print = 0;
			}
		}
		if (root->left)
		{
			isleft = 1;
			onrightmost = 0;
			perimeter(root->left);
		}
		if (root->right)
		{
			isleft = 0;
			onleftmost = 0;
			if (isfirst)
				onrightmost = 1;
			if (isright)
				onrightmost = 1;
			perimeter(root->right);
		}
		if (!isleft)
		{
			if (isright && print)
				printf(" %d", root->value);
		}
	}
	if (isfirst)
		printf("\n");
}

//libraries included for main

#include <stdlib.h>
#include <fcntl.h>

void		*newnode(void)
{
	return (malloc(sizeof(t_node)));
}


int			main(void)
{
	t_node	**arr = calloc(31, sizeof(t_node*));
	int		ints[30] = {92, 85, 79, 10, 39, 35, 96, 26, 64, 40, 88, 12, 58, 55, 58, 41, 10, 52, 22, 35, 87, 31, 78, 2, 33, 55, 11, 99, 85, 51};

	for (int i = 0; i < 30; i++)
	{
		arr[i] = newnode();
		arr[i]->value = ints[i];
	}
	for (int i = 0; i < 30; i++)
	{
		arr[i]->left = 0;
		arr[i]->right = 0;
	}
	arr[0]->left = arr[1];
	arr[0]->right = arr[7];
	arr[1]->left = arr[2];
	arr[2]->right = arr[3];
	arr[2]->left = 0;
	arr[3]->left = arr[4];
	arr[3]->right = 0;
	arr[4]->left = arr[5];
	arr[4]->right = 0;
	arr[5]->left = arr[6];
	arr[7]->right = arr[8];
	arr[8]->left = arr[9];
	arr[8]->right = arr[22];
	arr[9]->left = arr[10];
	arr[9]->right = arr[16];
	arr[10]->left = arr[11];
	arr[10]->right = arr[13];
	arr[11]->left = arr[12];
	arr[13]->left = arr[14];
	arr[13]->right = arr[15];
	arr[16]->left = arr[17];
	arr[16]->right = arr[20];
	arr[17]->left = arr[18];
	arr[17]->right = arr[19];
	arr[20]->right = arr[21];
	arr[22]->left = arr[23];
	arr[22]->right = arr[28];
	arr[23]->left = arr[24];
	arr[23]->right = arr[26];
	arr[24]->right = arr[25];
	arr[26]->right = arr[27];
	arr[28]->right = arr[29];
/*	for (int i = 0; i < 30; i++)
	{
		printf("%d ", arr[i]->value);
	} */
	printf("\n");
//	fd = open("file.txt", O_RDWR);
	perimeter(arr[0]);
}
