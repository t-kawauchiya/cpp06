/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:56:41 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/25 16:40:58 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  srand((unsigned int)std::time(NULL));

  Base* test = generate();

  std::cout << "[void identify(Base* p)]" << std::endl;
  identify(test);

  std::cout << "[void identify(Base& p)]" << std::endl;
  identify(*test);
}
