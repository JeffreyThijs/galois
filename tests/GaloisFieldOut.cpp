// /*
//   *********************************************************************
//   *                                                                   *
//   *               Galois Field Arithmetic Library                     *
//   * Prototype: Galois Field STD OUT Test                              *
//   * Version: 0.0.1                                                    *
//   * Author: Arash Partow - 2000                                       *
//   * URL: http://www.partow.net/projects/galois/index.html             *
//   *                                                                   *
//   * Copyright Notice:                                                 *
//   * Free use of this library is permitted under the guidelines and    *
//   * in accordance with the most current version of the Common Public  *
//   * License.                                                          *
//   * http://www.opensource.org/licenses/cpl.php                        *
//   *                                                                   *
//   *********************************************************************
// */


// #define BOOST_TEST_DYN_LINK
// #include <boost/test/unit_test.hpp>
// #include <boost/test/output_test_stream.hpp>
// #include <iostream>
// #include <stdlib.h>
// #include <stdio.h>
// #include "GaloisField.h"
// #include "GaloisFieldElement.h"
// #include "GaloisFieldPolynomial.h"

// BOOST_AUTO_TEST_SUITE( TestSuite1 )

// struct cout_redirect {
//     cout_redirect( std::streambuf * new_buffer ) 
//         : old( std::cout.rdbuf( new_buffer ) )
//     { }

//     ~cout_redirect( ) {
//         std::cout.rdbuf( old );
//     }

// private:
//     std::streambuf * old;
// };


// BOOST_AUTO_TEST_CASE( test1 )
// {
//     /*
//     p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
//             1    1    0    0    0    0    1    1    1
//     */
//     unsigned int poly[9] = {1,1,1,0,0,0,0,1,1};

//     /*
//     A Galois Field of type GF(2^8)
//     */

//     galois::GaloisField gf(8,poly);

//     boost::test_tools::output_test_stream output;
//     {
//         cout_redirect guard( output.rdbuf( ) );
//         std::cout << gf;
//     }

//     BOOST_CHECK( output.is_equal( "1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0\n" ) );
// }

// BOOST_AUTO_TEST_SUITE_END()

/*
  *********************************************************************
  *                                                                   *
  *               Galois Field Arithmetic Library                     *
  * Prototype: Galois Field STD OUT Test                              *
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

#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"

BOOST_AUTO_TEST_CASE( test_gf_out )
{
    /*
    p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
            1    1    0    0    0    0    1    1    1
    */
    unsigned int poly[9] = {1,1,1,0,0,0,0,1,1};

    /*
    A Galois Field of type GF(2^8)
    */
    galois::GaloisField gf(8,poly);
    // std::cout << gf;
}