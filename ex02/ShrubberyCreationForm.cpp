/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <manutea.birougmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 17:46:34 by mbirou            #+#    #+#             */
/*   Updated: 2025/01/01 18:31:57 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = "The Shadow Wizard Money Gang";;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm("ShrubberyCreationForm", 145, 137)
{
	*this = src;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator =(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
		_target = rhs._target;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string	&ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void	ShrubberyCreationForm::formAction() const
{
	std::ofstream	ofs;
	std::string		filename = _target;

	ofs.open(filename.append("_shrubbery").c_str(), std::ofstream::out | std::ofstream::trunc);
	if (ofs.fail())
		throw (ShrubberyCreationForm::FileCreationFailedExeption());
	PRINT CYN BOLD AND _target AND " is growing a forest of shrubs 🌱" CLR ENDL;
	ofs AND "%               @@@\n\
%			 @@@ @@@                 @@@@@@@\n\
%			@@     @@              @@       @@                           @@@@@@                     @@@@@\n\
%		   @@        @            @@         @@                        @@      @@                 @@     @@\n\
%		   @         @            @           @                        @        @                 @@      @\n\
%		  @           @          @            @                      @@          @               @         @@\n\
%		 @@           @          @             @                     @@          @@             @@          @@\n\
%		 @            @@        @               @                    @            @@            @            @\n\
%		@              @       @@               @@                  @              @           @              @\n\
%		@              @       @                 @                  @              @          @@              @@\n\
%		@               @      @                 @                  @               @         @@              @@\n\
%		@               @      @                 @                  @               @         @@              @@\n\
%		@               @     @@                 @@                @@               @         @                @\n\
%	   @                @     @                   @                @                @        @@                @@\n\
%	   @                @     @                   @                @                @        @                  @\n\
%	   @                @     @                   @               @@                @@       @                  @\n\
%	   @                @     @                   @               @@                @@       @                  @\n\
%	   @                @     @                   @               @@                @@       @                  @\n\
%	   @                @     @                   @               @                  @       @                  @                                  @@@@@@@\n\
%	   @                @     @                   @               @                  @       @                  @   @@@@@@@@@@@@@@@          @@@@@@       @@@@@@   @@@@@@@@@\n\
%		@               @     @                   @               @                  @        @                @@@@@               @@@@  @@@@                   @@@         @@@\n\
%		@     @@@@@@@@  @     @                   @               @                  @        @     @@@@@@@@@@@@@                     @@@@                         @@          @@\n\
%		@@@@@@        @@@     @         @@@@@@@@@@@@@@@           @                  @        @@  @@             @@@                 @@                              @           @\n\
%	  @@@@               @@@@ @    @@@@@               @@@@@      @                  @        @@@@                  @@             @@@                                @@         @@\n\
%   @@@                        @@@@@@                        @@@@  @          @@@@@@@@@     @@@                        @@@@@@@@@@@@@  @@@@@@@@@@                         @@        @@\n\
%  @@                          @@                                @@@  @@@@@@@@        @@@@@@@@@                      @@@@                      @@@@                       @@        @@\n\
% @@                  @@@@@@@@@@@@@                               @@@@@                       @@@@      @@@@@@@@@@@@@@@@@@                        @@@       @@@@@@@@@@@@@@ @         @\n\
%@@               @@@@             @@@                            @@                              @@   @                 @@@@                       @@    @@@             @@@        @\n\
%@@           @@@@                    @@@                       @@                                 @@@@                     @@@                      @@@@@                   @@      @\n\
%@@         @@@                         @@@@        @@@@@@@@ @@@                                  @@@                         @@@                     @@                      @@@    @\n\
%@@       @@@                             @@@ @@@@@@@      @@@@@@@                               @@                              @@                 @@                          @@   @\n\
%  @     @@                               @@@@                    @@@@                         @@                                 @@                @                            @@  @\n\
%   @@@  @          @@@@@@@@@@@@@@@   @@@@@                          @ @@                     @@                             @@@@@@@@@@@@@@@@@      @   @@@@@@@@@@@@@@@@@@         @@@\n\
%	 @  @         @@@@           @@@@@                                 @                    @@                            @@@@              @@@@  @   @@                 @@@       @\n\
%	  @@@     @@@@                   @@@                                @@                  @                         @@@@@@                    @@@@@@                     @@@    @@\n\
%		@@@ @@@                        @@@                                @@@@@@@@@@@@@@@@ @@                       @@@                            @@                        @@  @@\n\
%		  @@                             @@                            @@@@               @@@                      @                              @                            @@@\n\
%		 @@                                @@                        @@                      @@@@               @@@                              @@                             @@\n\
%		@      @@@@@@@                      @@                     @@                           @@      @@@@@@@@@                               @                                @\n\
%		@    @@@    @@@@@                    @                    @@                              @ @@@@       @@@@@                            @                                @\n\
%	   @@ @@@           @@@@                 @@                  @@                              @@@                @@@                         @                                @@\n\
%	  @@@@                  @@@@              @                 @                            @@@@                      @@@@                     @                                 @\n\
%	  @@                       @@@   @@@@@@@@@@@@@@@@@@@@      @@       @@@@@@@@@@@@@@@    @@@                            @@@                   @                                @\n\
%	 @@                         @@@@@                    @@@   @     @@@               @@@@@                                @@                  @                                @\n\
%	@@                          @@@                         @@@@  @@@                    @@                                  @@                  @@                             @@\n\
%	@@                         @@                             @@  @@                    @@                                    @@                 @@                            @@\n\
%	@                         @@                               @@@                      @@                                    @@                  @@                          @@\n\
%	@                       @@@                                @@                      @@                                      @@                  @@                       @@@\n\
%	@                      @@                                 @                        @                                        @                    @@@@                @@@@\n\
%	@@                     @                                 @@                        @                                        @                    @@@@@@@@@@   @@@@@@@@@\n\
%	 @                     @                                 @                         @                                        @                   @@        @@@@@\n\
%	 @@                    @                                 @                          @                                      @                 @@@@\n\
%	  @@                   @                                 @                          @@                                    @@            @@@@@@@\n\
%	   @@@                 @@                                 @                          @@                                  @@@@@@@@@@@@@@@\n\
%		 @@@@            @@@@@                                @                           @@                                @@\n\
%			 @@@@@@@@@@@@    @@                                @@                          @@                              @@\n\
%							  @@                               @@                            @                            @@\n\
%							   @@@                            @@ @@                          @@@@                      @@@\n\
%								  @@@@@                @@@@@@@    @@@@@                 @@@@@@  @@@@@@@@        @@@@@@@@\n\
%									 @@@@@@@@@@@@@@@@@@@@            @@@@@@@@       @@@@@@            @@@@@@@@@@@@@\n\
%																			@@@@@@@@\n\
	" ENDL;
	ofs.close();
}
