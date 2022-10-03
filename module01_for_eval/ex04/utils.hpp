/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jaka <jaka@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/03 15:18:49 by jaka          #+#    #+#                 */
/*   Updated: 2022/10/03 15:23:08 by jaka          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <iostream>
# include <fstream>
# include <stdlib.h>	// for exit()

int		check_arguments(int argc);
void	open_files_and_check(char **argv, std::ifstream &infile, std::ofstream &outfile);

#endif
