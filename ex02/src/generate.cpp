/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 19:18:55 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 19:56:19 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>

Base* generate(void) {
  const int randVal = std::rand();

  switch (randVal % 3) {
  case 0:
    return new A();
  case 1:
    return new C();
  default:
    return new B();
  }
}
