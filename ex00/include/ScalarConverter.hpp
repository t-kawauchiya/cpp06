/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takawauc <takawauc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:57:27 by takawauc          #+#    #+#             */
/*   Updated: 2026/02/18 12:59:35 by takawauc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _SCALAR_CONVERTER_H_
#define _SCALAR_CONVERTER_H_

#include <string>

class ScalarConverter {
public:
  static void convert(const std::string& str);

  enum e_type { CHAR, INT, FLOAT, DOUBLE, INVALID };

  typedef struct s_data {
    e_type type;
    union {
      char c_data;
      int i_data;
      float f_data;
      double d_data;
    };
  } t_data;

private:
  static ScalarConverter::t_data parseStrToData(const std::string& str);
  static void putLiterals(ScalarConverter::t_data data);
};

#endif
