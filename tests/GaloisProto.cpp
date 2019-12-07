/*
  *********************************************************************
  *                                                                   *
  *               Galois Field Arithmetic Library                     *
  * Prototype: Galois Field Prototype                                 *
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
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"

/*
   p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
          1    1    0    0    0    0    1    1    1
*/
unsigned int poly[9] = {1,1,1,0,0,0,0,1,1};

/*
  A Galois Field of type GF(2^8)
*/

galois::GaloisField gf(8,poly);

galois::GaloisFieldElement gfe[10] = {
                                      galois::GaloisFieldElement(&gf, 1),
                                      galois::GaloisFieldElement(&gf, 2),
                                      galois::GaloisFieldElement(&gf, 3),
                                      galois::GaloisFieldElement(&gf, 4),
                                      galois::GaloisFieldElement(&gf, 5),
                                      galois::GaloisFieldElement(&gf, 6),
                                      galois::GaloisFieldElement(&gf, 7),
                                      galois::GaloisFieldElement(&gf, 8),
                                      galois::GaloisFieldElement(&gf, 9),
                                      galois::GaloisFieldElement(&gf,10)
                                     };

galois::GaloisFieldElement gfe2[6] = {
                                      galois::GaloisFieldElement(&gf, 6),
                                      galois::GaloisFieldElement(&gf, 5),
                                      galois::GaloisFieldElement(&gf, 4),
                                      galois::GaloisFieldElement(&gf, 3),
                                      galois::GaloisFieldElement(&gf, 2),
                                      galois::GaloisFieldElement(&gf, 1)
                                     };

galois::GaloisFieldElement gfe3[5] = {
                                      galois::GaloisFieldElement(&gf, 13),
                                      galois::GaloisFieldElement(&gf, 11),
                                      galois::GaloisFieldElement(&gf,  7),
                                      galois::GaloisFieldElement(&gf,  3),
                                      galois::GaloisFieldElement(&gf,  2)
                                     };


galois::GaloisFieldElement gfez[3] = {
                                      galois::GaloisFieldElement(&gf, 0),
                                      galois::GaloisFieldElement(&gf, 0),
                                      galois::GaloisFieldElement(&gf, 1)
                                     };


BOOST_AUTO_TEST_CASE( addsub_test )
{

   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,5,gfe2);
   galois::GaloisFieldPolynomial gfp3(&gf,0);

   gfp3 = gfp1 + gfp2;
   gfp3 = gfp3 - gfp2;

   BOOST_CHECK_EQUAL(gfp1, gfp3);
}

BOOST_AUTO_TEST_CASE( muldiv_test )
{
   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,5,gfe2);
   galois::GaloisFieldPolynomial gfp3(&gf,0);

   gfp3 = gfp1 * gfp2;
   gfp3 = gfp3 / gfp2;

   BOOST_CHECK_EQUAL(gfp1, gfp3);
}

BOOST_AUTO_TEST_CASE( divmod_test )
{
   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,5,gfe2);
   galois::GaloisFieldPolynomial gfp3(&gf,4,gfe3);
   galois::GaloisFieldPolynomial gfp4(&gf,0);

   gfp4 = (gfp1 * gfp2) + gfp3;

   BOOST_CHECK_EQUAL(gfp4 % gfp1, gfp3);
   BOOST_CHECK_EQUAL(gfp4 % gfp2, gfp3);
}

BOOST_AUTO_TEST_CASE( mod_zmodetest )
{
   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,2,gfez); // p(x) = x^2

   BOOST_CHECK_EQUAL((gfp1 % gfp2), (gfp1 % 2));
}

BOOST_AUTO_TEST_CASE( exp_test )
{
   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,0);

   gfp2 = gfp1 ^ 10;

   for (unsigned int i = 0; i < 10; i++)
   {
      gfp2 = gfp2 / gfp1;
   }

   BOOST_CHECK_EQUAL(gfp2, gfp1);
}

BOOST_AUTO_TEST_CASE( shiftleft_test )
{

   galois::GaloisFieldPolynomial gfp1(&gf,9,gfe);
   galois::GaloisFieldPolynomial gfp2(&gf,0);

   gfp2 = gfp1 << 10;
   gfp2 = gfp2 >> 10;

   BOOST_CHECK_EQUAL(gfp2, gfp1);
}