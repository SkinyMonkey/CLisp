#include <assert.h>
#include <stdio.h>
#include "lisp.h"
#include "arithmetics.h"
#include "booleans.h"
#include "statements.h"

int 		main(void)
{
  printf("----------------------------------------------------------\n");
  // Simple arithmetics

  printf("(+ 42)\n");
  assert(add(integer(42)) == 42); // (+ 42)
  printf("(+ 40 2)\n");
  assert(add(integer(40), integer(2)) == 42); // (+ 40 2)
  printf("(+ 38 2 2)\n");
  assert(add(integer(38), integer(2), integer(2)) == 42); // (+ 38 2 2)
  printf("(- 40 2)\n");
  assert(minus(integer(40), integer(2)) == 38); // (- 38 2 2)
  printf("(* 42 2)\n");
  assert(time(integer(40), integer(2)) == 80); // (* 40 2)
  printf("(/ 40 2)\n");
  assert(divide(integer(40), integer(2)) == 20); // (/ 40 2)
  printf("(%% 50 2\n");
  assert(modulus(integer(40), integer(2)) == 0); // (% 40 2)
  
  // Functor arithmetics.
  // (+ 40 (+ 1 (+ 1 2 3)))
  printf("(+ 40 (+ 1 (+ 1 2 3)))\n");
  assert(add(integer(40),
		     functor(add, integer(1),
		     functor(add, integer(1), integer(2), integer(3)))) == 47);
  // Booleans.
  // (&& (= 1 1) (= 4 4))
  printf("(&& (= 1 1) (= 4 4))\n");
  assert(and(functor(equal, integer(1), integer(1)),
		  functor(equal, integer(4), integer(4))) == true);
  
  // (|| (= 1 2) (= 2 2))
  printf("(|| (= 1 2) (= 2 2))\n");
  assert(or(functor(equal, integer(1), integer(2)),
	    functor(equal, integer(2), integer(2))) == true);
  
  // (! false)
  printf("(! false)\n");
  assert(not(integer(false)) == true);
  
  // (! true)
  printf("(! true)\n");
  assert(not(integer(true)) == false);
  
  // (= 1 1)
  printf("(= 1 1)\n");
  assert(equal(integer(1), integer(1)) == true);
  
  // (= 0 1)
  printf("(= 0 1)\n");
  assert(equal(integer(0), integer(1)) == false);

  // (!= 2 1)
  printf("(!= 2 1)\n");
  assert(different(integer(2), integer(1)) == true);

  // (!= 2 2)
  printf("(!= 2 2)\n");
  assert(different(integer(2), integer(2)) == false);

  // (< 1 2)
  printf("(< 1 2)\n");
  assert(less(integer(1), integer(2)) == true);

  // (> 3 2)
  printf("(> 3 2)\n");
  assert(greater(integer(3), integer(2)) == true);
  
  // (<= 1 1)
  printf("(<= 1 1)\n");
  assert(less_or_equal(integer(1), integer(1)) == true);
  
  // (>= 3 3)
  printf("(>= 3 3)\n");
  assert(greater_or_equal(integer(3), integer(3)) == true);

  // Statements.
  // (if (< 1 3)
  // 	 (print ">")
  //  (print "<"))
  printf("(if (< 1 3)\n\
    (print \">\")\n\
(print \"<\"))\n");
  condition(functor(less, integer(1), integer(3))
	   ,functor(print, string(">"))
	   ,functor(print, string("<")));

  // Statements.
  // (if (< 3 3)
  // 	 (print ">"))
  printf("(if (< 3 3)\n\
    (print \">\")\n");
  condition(functor(less, integer(3), integer(3))
	   ,functor(print, string(">")));

  //(or
  //   (and (= 0 n) (print "n is null"))
  //(print "n is not null"))
  printf("(or\n\
    (and (= 0 n) (print \"n is null\"))\n\
(print \"n is not null\"))\n");
  or(functor(and, functor(equal, integer(0), id("n")),
		  functor(print, string("n is null"))),
     functor(print, string("n is not null")));
  printf("All test passed\n");
  return 0;
}
