/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:32:11 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 19:54:53 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p) {

  if (dynamic_cast<A*>(p))
    std::cout << "class of p is \"A\"\n";
  else if (dynamic_cast<B*>(p))
    std::cout << "class of p is \"B\"\n";
  else if (dynamic_cast<C*>(p))
    std::cout << "class of p is \"C\"\n";
  else
    std::cout << "class of p is unknown....\n";
}

void identify(Base& p) {

  try {
    (void)dynamic_cast<A&>(p);
    std::cout << "class of p is \"A\"\n";
    return;
  } catch (std::exception e) {
  }
  try {
    (void)dynamic_cast<B&>(p);
    std::cout << "class of p is \"B\"\n";
    return;
  } catch (std::exception e) {
  }
  try {
    (void)dynamic_cast<C&>(p);
    std::cout << "class of p is \"C\"\n";
    return;
  } catch (std::exception e) {
  }
  std::cout << "class of p is unknown....\n";
}
