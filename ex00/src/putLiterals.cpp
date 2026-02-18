/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putLiterals.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:51:19 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 15:02:26 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <iostream>

void putCharLiteral(ScalarConverter::t_data data);
void putIntLiteral(ScalarConverter::t_data data);
void putFloatLiteral(ScalarConverter::t_data data);
void putDoubleLiteral(ScalarConverter::t_data data);

void ScalarConverter::putLiterals(ScalarConverter::t_data data) {
  putCharLiteral(data);
  putIntLiteral(data);
  putFloatLiteral(data);
  putDoubleLiteral(data);
}

void putCharLiteral(ScalarConverter::t_data data) {
  std::cout << "char: ";

  char val = 0;
  switch (data.type) {
  case ScalarConverter::CHAR:
    val = data.c_data;
    break;
  case ScalarConverter::INT:
    if (data.i_data < std::numeric_limits<char>::max() &&
        data.i_data > std::numeric_limits<char>::min()) {
      val = static_cast<char>(data.i_data);
      break;
    }
  case ScalarConverter::FLOAT:
    if (isfinite(data.f_data) &&
        data.f_data < std::numeric_limits<char>::max() &&
        data.f_data > std::numeric_limits<char>::min()) {
      val = static_cast<char>(data.f_data);
      break;
    }
  case ScalarConverter::DOUBLE:
    if (isfinite(data.d_data) &&
        data.d_data < std::numeric_limits<char>::max() &&
        data.d_data > std::numeric_limits<char>::min()) {
      val = static_cast<char>(data.d_data);
      break;
    }
  default:
    std::cout << "impossible" << std::endl;
    return;
  }
  if (std::isprint(val))
    std::cout << "'" << val << "'" << std::endl;
  else
    std::cout << "Non displaiable" << std::endl;
}

void putIntLiteral(ScalarConverter::t_data data) {
  std::cout << "int: ";

  int val = 0;
  switch (data.type) {
  case ScalarConverter::CHAR:
    val = static_cast<int>(data.c_data);
    break;
  case ScalarConverter::INT:
    val = data.i_data;
    break;
  case ScalarConverter::FLOAT:
    if (isfinite(data.f_data) &&
        data.f_data > std::numeric_limits<int>::max() &&
        data.f_data < std::numeric_limits<int>::min()) {
      val = static_cast<int>(data.f_data);
      break;
    }
  case ScalarConverter::DOUBLE:
    if (isfinite(data.d_data) &&
        data.d_data > std::numeric_limits<int>::max() &&
        data.d_data < std::numeric_limits<int>::min()) {
      val = static_cast<int>(data.d_data);
      break;
    }
  default:
    std::cout << "impossible" << std::endl;
    return;
  }
  std::cout << std::fixed << val << std::endl;
}

void putFloatLiteral(ScalarConverter::t_data data) {
  std::cout << "float: ";

  float val = 0;

  switch (data.type) {
  case ScalarConverter::CHAR:
    val = static_cast<float>(data.c_data);
    break;
  case ScalarConverter::INT:
    val = static_cast<float>(data.i_data);
    break;
  case ScalarConverter::FLOAT:
    val = data.f_data;
    break;
  case ScalarConverter::DOUBLE:
    if (!isfinite(data.d_data) ||
        (data.d_data > std::numeric_limits<float>::max() &&
         data.d_data < std::numeric_limits<float>::min())) {
      val = static_cast<float>(data.d_data);
      break;
    }
  default:
    std::cout << "impossible" << std::endl;
    return;
  }
  std::cout << std::fixed << std::setprecision(1) << val << "f" << std::endl;
}

void putDoubleLiteral(ScalarConverter::t_data data) {
  std::cout << "double: ";

  double val = 0;

  switch (data.type) {
  case ScalarConverter::CHAR:
    val = static_cast<double>(data.c_data);
    break;
  case ScalarConverter::INT:
    val = static_cast<double>(data.i_data);
    break;
  case ScalarConverter::FLOAT:
    val = static_cast<double>(data.f_data);
    break;
  case ScalarConverter::DOUBLE:
    val = data.d_data;
    break;
  default:
    std::cout << "impossible" << std::endl;
    return;
  }
  std::cout << std::fixed << std::setprecision(1) << val << std::endl;
}
