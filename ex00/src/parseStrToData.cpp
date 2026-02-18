/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseStrToData.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 23:46:47 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 15:46:13 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

#include <cstdlib>
#include <limits>

bool isCharLiteral(const std::string& str);
bool isIntLiteral(const std::string& str);
bool isFloatLiteral(const std::string& str);
bool isDoubleLiteral(const std::string& str);
bool isSpecial(const std::string& str);
std::string reductSigns(const std::string& str);

ScalarConverter::t_data
ScalarConverter::parseStrToData(const std::string& str) {
  ScalarConverter::t_data ret;

  ret.type = ScalarConverter::INVALID;
  ret.c_data = 0;
  if (isCharLiteral(str)) {
    ret.type = ScalarConverter::CHAR;
    ret.c_data = str.c_str()[0];
  } else if (isIntLiteral(str)) {
    ret.type = ScalarConverter::INT;
    ret.i_data = strtol(reductSigns(str).c_str(), NULL, 10);
  } else if (isFloatLiteral(str)) {
    ret.type = ScalarConverter::FLOAT;
    ret.f_data = strtof(reductSigns(str).c_str(), NULL);
  } else if (isDoubleLiteral(str)) {
    ret.type = ScalarConverter::DOUBLE;
    ret.d_data = strtod(reductSigns(str).c_str(), NULL);
  }
  return ret;
}

bool hasValidSign(const std::string& str);

bool isCharLiteral(const std::string& str) {
  return (str.size() == 1);
}

bool isIntLiteral(const std::string& str) {
  long tmp;
  char* end;

  if (!hasValidSign(str))
    return false;
  const std::string reducted = reductSigns(str);
  if (reducted.size() > 11)
    return false;

  tmp = strtol(reducted.c_str(), &end, 10);
  if (end != reducted.c_str() + reducted.size() ||
      tmp > std::numeric_limits<int>::max() ||
      tmp < std::numeric_limits<int>::min())
    return false;
  return true;
}

bool isFloatLiteral(const std::string& str) {
  double tmp;
  char* end;

  if (str == "inff" || str == "-inff" || str == "+inff" || str == "-+inff" ||
      str == "+-inff" || str == "nanf")
    return true;
  if (!hasValidSign(str) || *(str.end() - 1) != 'f' ||
      str.find('.') == std::string::npos)
    return false;
  const std::string reducted = reductSigns(str);

  tmp = strtod(reducted.c_str(), &end);
  if (end != (reducted.c_str() + reducted.size() - 1) ||
      tmp > std::numeric_limits<float>::max() ||
      tmp < -std::numeric_limits<float>::max())
    return false;
  return true;
}

bool isDoubleLiteral(const std::string& str) {
  double tmp;
  char* end;

  if (str == "inf" || str == "-inf" || str == "+inf" || str == "-+inf" ||
      str == "+-inf" || str == "nan")
    return true;
  if (!hasValidSign(str) || str.find('.') == std::string::npos)
    return false;
  const std::string reducted = reductSigns(str);

  tmp = strtod(reducted.c_str(), &end);
  if (end != (reducted.c_str() + reducted.size()) ||
      tmp > std::numeric_limits<double>::max() ||
      tmp < -std::numeric_limits<double>::max())
    return false;
  return true;
}

bool hasValidSign(const std::string& str) {
  std::string::const_iterator it = str.begin();
  bool hasPosSign = false;
  bool hasNegSign = false;
  while (it != str.end() && (*it == '+' || *it == '-')) {
    if (*it == '+') {
      if (hasPosSign)
        return false;
      hasPosSign = true;
    }
    if (*it == '-') {
      if (hasNegSign)
        return false;
      hasNegSign = true;
    }
    ++it;
  }
  return true;
}

std::string reductSigns(const std::string& str) {
  std::string::const_iterator it = str.begin();
  bool hasPosSign = false;
  bool hasNegSign = false;

  std::string ret;

  while (it != str.end() && (*it == '+' || *it == '-')) {
    if (*it == '+') {
      if (hasPosSign)
        return std::string(str);
      hasPosSign = true;
    }
    if (*it == '-') {
      if (hasNegSign)
        return std::string(str);
      hasNegSign = true;
    }
    ++it;
  }
  if (hasNegSign)
    return ("-" + std::string(it, str.end()));
  if (hasPosSign)
    return ("+" + std::string(it, str.end()));
  return std::string(str);
}
