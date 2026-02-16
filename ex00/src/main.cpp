/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:56:41 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/16 22:37:47 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <limits>

int main() {
  float _inff = std::numeric_limits<float>::infinity();
  float _ninff = -std::numeric_limits<float>::infinity();
  float _nanf = nanf("");
  double _infd = std::numeric_limits<double>::infinity();
  double _ninfd = -std::numeric_limits<double>::infinity();
  double _nand = nan("");

  std::cout << "+inff: " << _inff << std::endl;
  std::cout << "-inff: " << _ninff << std::endl;
  std::cout << "nanf: " << _nanf << std::endl;

  std::cout << "+inf: " << _infd << std::endl;
  std::cout << "-inf: " << _ninfd << std::endl;
  std::cout << "nan: " << _nand << std::endl;

  std::cout << "strtod(\"42.0\",NULL): "
            << static_cast<float>(strtod("42.0", NULL)) << std::endl;
  std::cout << "strtod(\"inf\",NULL): " << strtod("inf", NULL) << std::endl;
  std::cout << "strtod(\"+inf\",NULL): " << strtod("+inf", NULL) << std::endl;
  std::cout << "strtod(\"-inf\",NULL): " << strtod("-inf", NULL) << std::endl;
  std::cout << "strtod(\"nan\",NULL): " << strtod("nan", NULL) << std::endl;
  std::cout << "strtod(\"NAN\",NULL): " << strtod("NAN", NULL) << std::endl;
}
