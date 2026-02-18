/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:56:41 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 19:59:22 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"
#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  srand((unsigned int)std::time(NULL));
  std::cout << "[void identify(Base* p)]" << std::endl;
  Base* test = generate();
  identify(test);
  std::cout << "[void identify(Base& p)]" << std::endl;
  identify(*test);
}
