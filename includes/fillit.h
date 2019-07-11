/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcross <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 21:16:07 by rcross            #+#    #+#             */
/*   Updated: 2019/07/11 15:09:51 by rcross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define SQUARE "##..##"
# define LINE "#...#...#...#"
# define STR8 "####"
# define TUP "###..#"
# define TRIGHT "#...##..#"
# define TDOWN "#..###"
# define TLEFT "#..##...#"
# define LUP "#...#...##"
# define LRIGHT "#.###"
# define LDOWN  "##...#...#"
# define LLEFT "###.#"
# define JUP "#...#..##"
# define JRIGHT "###...#"
# define JDOWN "##..#...#"
# define JLEFT "#...###"
# define ZUP "##...##"
# define ZSIDE "#..##..#"
# define SUP "##.##"
# define SSIDE "#...##...#"

# define SQUARE2 "##\n##"
# define LINE2 "#\n#\n#\n#"
# define TUP2 "###\n.#."
# define TRIGHT2 "#.\n##\n#."
# define TDOWN2 ".#.\n###"
# define TLEFT2 ".#\n##\n.#"
# define LUP2 "#.\n#.\n##"
# define LRIGHT2 "..#\n###"
# define LDOWN2 "##\n.#\n.#"
# define LLEFT2 "###\n#.."
# define JUP2 ".#\n.#\n##"
# define JRIGHT2 "###\n..#"
# define JDOWN2 "##\n#.\n#."
# define JLEFT2 "#..\n###"
# define ZUP2 "##.\n.##"
# define ZSIDE2 ".#\n##\n#."
# define SUP2 ".##\n##."
# define SSIDE2 "#.\n##\n.#"

typedef struct		s_etris
{
	char			**piece;
	char			letter;
	struct s_etris	*next;
}					t_etris;

int					g_pcs;

int					ft_error(void);
int					ft_usage(void);
int					read_file(int fd, t_etris **tetriminos);
int					check_file(char *str, int i, int hash, int count);
int					check_links(char *str);
void				add_tet(char *buf, char letter, t_etris **tet);
t_etris				*make_node(char **ndata, char letter);
void				add_node(t_etris **head, t_etris *new);
void				deletelist(t_etris **head);
int					get_size(void);
char				**clean_map(char **map, t_etris *node);
char				**create_map(int size);
void				fillit(t_etris *tetriminos);
void				make_piece(char *str, char letter, t_etris **tetriminos);
void				trimstr(char *str, char *tmp);
void				trimmer(char *str);
void				trimmer2(char *str);
int					solver(char **map, t_etris *node);
int					is_placeable(char **map, t_etris *node, int i, int j);
char				**place(char **map, t_etris *node, int	i, int j);
void				print_solution(char **map);

#endif
