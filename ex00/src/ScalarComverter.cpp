/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarComverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:58:52 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 14:51:17 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
void printData(ScalarConverter::t_data data);

void ScalarConverter::convert(const std::string& str) {
  t_data data = ScalarConverter::parseStrToData(str);
  printData(data);
  ScalarConverter::putLiterals(data);
}

void printData(ScalarConverter::t_data data) {
  const std::string sep = "---------------------------------------\n";
  std::cout << sep;
  std::cout << "type: ";
  switch (data.type) {
  case ScalarConverter::CHAR:
    std::cout << "CHAR, c_data: " << data.c_data << std::endl;
    break;
  case ScalarConverter::INT:
    std::cout << "INT, i_data: " << data.i_data << std::endl;
    break;
  case ScalarConverter::FLOAT:
    std::cout << "FLOAT, f_data: " << data.f_data << std::endl;
    break;
  case ScalarConverter::DOUBLE:
    std::cout << "DOUBLE, d_data: " << data.d_data << std::endl;
    break;
  case ScalarConverter::INVALID:
    std::cout << "INVALID, c_data: " << data.c_data << std::endl;
    break;
  }
  std::cout << sep;
}
