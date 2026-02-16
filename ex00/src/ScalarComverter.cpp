/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarComverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 20:58:52 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/16 22:30:58 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <string>

ScalarConverter::t_data parseStrToData(const std::string& str);
void putCharLiteral(ScalarConverter::t_data data);
void putIntLiteral(ScalarConverter::t_data data);
void putFloatLiteral(ScalarConverter::t_data data);
void putDoubleLiteral(ScalarConverter::t_data data);

void ScalarConverter::convert(const std::string& str) {
  t_data data = parseStrToData(str);

  putCharLiteral(data);
  putIntLiteral(data);
  putFloatLiteral(data);
  putDoubleLiteral(data);
}

bool isIntLiteral(const std::string& str);
bool isFloatLiteral(const std::string& str);
bool isDoubleLiteral(const std::string& str);

ScalarConverter::t_data parseStrToData(const std::string& str) {
  ScalarConverter::t_data ret;

  ret.type = ScalarConverter::INVALID;
  ret.c_data = 0;
  if (str.size() == 1) {
    ret.type = ScalarConverter::CHAR;
    ret.c_data = str.c_str()[0];
  } else if (isIntLiteral(str)) {
    ret.type = ScalarConverter::INT;
    ret.i_data = strtol(str.c_str(), NULL, 10);
  } else if (isFloatLiteral(str)) {
    ret.type = ScalarConverter::FLOAT;
    ret.f_data = strtof(str.c_str(), NULL);
  } else if (isDoubleLiteral(str)) {
    ret.type = ScalarConverter::DOUBLE;
    ret.d_data = strtod(str.c_str(), NULL);
  }
  return ret;
}

bool isIntLiteral(const std::string& str) {
  long tmp;
  char* end;
  if (str.size() > 11)
    return false;
  tmp = strtol(str.c_str(), &end, 10);
  if (end != str.c_str() + str.size() ||
      tmp > std::numeric_limits<int>::max() ||
      tmp < std::numeric_limits<int>::min())
    return false;
  return true;
}

bool isFloatLiteral(const std::string& str) {
  double tmp;
  char* end;
  // format check
  tmp = strtod(str.c_str(), &end);
  if (end != str.c_str() + str.size() ||
      tmp > std::numeric_limits<float>::max() ||
      tmp < std::numeric_limits<float>::min())
    return false;
  return false;
}
bool isDoubleLiteral(const std::string& str);
