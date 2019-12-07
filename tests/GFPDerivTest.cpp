/*
  *********************************************************************
  *                                                                   *
  *               Galois Field Arithmetic Library                     *
  * Prototype: Galois Field Polynomial Derivative Test                *
  * Version: 0.0.1                                                    *
  * Author: Arash Partow - 2000                                       *
  * URL: http://www.partow.net/projects/galois/index.html             *
  *                                                                   *
  * Copyright Notice:                                                 *
  * Free use of this library is permitted under the guidelines and    *
  * in accordance with the most current version of the Common Public  *
  * License.                                                          *
  * http://www.opensource.org/licenses/cpl.php                        *
  *                                                                   *
  *********************************************************************
*/


/*
   This is a test of the formal derivative capabilities of the GaloisFieldPolynomial
   class. The test is based upon a problem in the book: The Art of Error Correcting
   Coding.

   On page 70 (Non-binary BCH codes: Reed-Solomon) it is assumed the formal derivative
   of the polynomial phi is 1.

   Where phi(x) = 1x^0 + 1x^1 + alpha^5x^2 + 0x^3 + alpha^5x^4

   The code below demonstrates this fact.

*/
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"

BOOST_AUTO_TEST_SUITE( redir_stdout )
struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer ) 
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};


BOOST_AUTO_TEST_CASE( deriv_test )
{

  /*
    p(x) = 1x^4+1x^3+0x^2+0x^1+1x^0
            1    1    0    0    1
  */
  unsigned int poly[5] = {1,0,0,1,1};

  /*
    A Galois Field of type GF(2^8)
  */

  galois::GaloisField galois_field(4,poly);


  //  std::cout << "Galois Field: " << std::endl << galois_field << std::endl;

   galois::GaloisFieldElement gfe[5] = {
                                         galois::GaloisFieldElement(&galois_field,galois_field.alpha(1)),
                                         galois::GaloisFieldElement(&galois_field,galois_field.alpha(1)),
                                         galois::GaloisFieldElement(&galois_field,galois_field.alpha(5)),
                                         galois::GaloisFieldElement(&galois_field,                    0),
                                         galois::GaloisFieldElement(&galois_field,galois_field.alpha(5)),
                                       };

   galois::GaloisFieldPolynomial polynomial(&galois_field,4,gfe);

    boost::test_tools::output_test_stream output_1;
    {
        cout_redirect guard( output_1.rdbuf( ) );
        std::cout << "p(x)  = " << polynomial              << std::endl;
    }
    BOOST_CHECK( output_1.is_equal( "p(x)  = 2 x^0 + 2 x^1 + 11 x^2 + 0 x^3 + 11 x^4\n" ) );

    boost::test_tools::output_test_stream output_2;
    {
        cout_redirect guard( output_2.rdbuf( ) );
        std::cout << "p'(x) = " << polynomial.derivative() << std::endl;
    }
    BOOST_CHECK( output_2.is_equal( "p'(x) = 2 x^0\n" ) );
}
BOOST_AUTO_TEST_SUITE_END()