/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:56:41 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 18:06:56 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"
#include <iostream>

int main() {
  Data data = {5, "hello!"};
  Data* deserialized = Serializer().deserialize(Serializer().serialize(&data));

  if (&data == deserialized)
    std::cout << "same address!!" << std::endl;
  else
    std::cout << "not same address..." << std::endl;
}
