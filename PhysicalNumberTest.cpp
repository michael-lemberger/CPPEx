/**
 * Examples of automatic tests for the exercise on physical numbers.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
#include <sstream>
using std::cout, std::endl, std::istringstream;
#include "PhysicalNumber.h"
using ariel::PhysicalNumber, ariel::Unit;
#include "badkan.hpp"

int main() {
  badkan::TestCase testcase;
  int grade=0;
  int signal = setjmp(badkan::longjmp_buffer);
  if (signal == 0) {

    // BASIC TESTS - DO NOT CHANGE
    PhysicalNumber a(2, Unit::KM);
    PhysicalNumber a2(2000, Unit::M);
    PhysicalNumber a3(200000, Unit::CM);
    PhysicalNumber b(300, Unit::M);
    PhysicalNumber c(2, Unit::HOUR);
    PhysicalNumber c2(120, Unit::MIN);
    PhysicalNumber c3(7200, Unit::SEC);
    PhysicalNumber d(30, Unit::MIN);
    PhysicalNumber e(750, Unit::KG);
    PhysicalNumber f(1, Unit::TON);
    PhysicalNumber f2(1000, Unit::KG);
    PhysicalNumber f3(1000000, Unit::G);
    PhysicalNumber g(1000, Unit::G);
    PhysicalNumber h(100, Unit::CM);
    PhysicalNumber i(60, Unit::SEC);
    
    testcase
    .setname("Equality between other units")
    .CHECK_EQUAL(a==a2, true)
    .CHECK_EQUAL(a==a3,true)
    .CHECK_EQUAL(a3==a2,true)
    .CHECK_EQUAL(c==c2, true)
    .CHECK_EQUAL(c==c3, true)
    .CHECK_EQUAL(c3==c2, true)
    .CHECK_EQUAL(f==f2, true)
    .CHECK_EQUAL(f3==f, true)
    .CHECK_EQUAL(f2==f3, true)
    .CHECK_EQUAL(g<f2,true)
    .CHECK_EQUAL(g>f3,false)
    .CHECK_EQUAL(a3<=h, false)
    .CHECK_EQUAL(a3>=h, true)
    .CHECK_EQUAL(c3!=c2, false)


  
    .setname("Basic output")
    .CHECK_OUTPUT(a, "2[km]")
    .CHECK_OUTPUT(b, "300[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(e, "750[kg]")
    .CHECK_OUTPUT(f, "1[ton]")
    .CHECK_OUTPUT(g, "1000[g]")
    .CHECK_OUTPUT(h, "100[cm]")
    .CHECK_OUTPUT(i, "60[sec]")

    .setname("Compatible dimensions")
    .CHECK_OUTPUT(b+a, "2300[m]")
    .CHECK_OUTPUT((a+=b), "2.3[km]")
    .CHECK_OUTPUT(a, "2.3[km]")
    .CHECK_OUTPUT(a+a, "4.6[km]")
    .CHECK_OUTPUT(b-b, "0[m]")
    .CHECK_OUTPUT(c, "2[hour]")
    .CHECK_OUTPUT(d, "30[min]")
    .CHECK_OUTPUT(d+c, "150[min]")
    .CHECK_OUTPUT(a2+a3, "4000[m]")
    .CHECK_OUTPUT((a-=h), "2.299[km]")
    .CHECK_OUTPUT(++a3, "200001[cm]")
    .CHECK_OUTPUT(--a, "1.299[km]")
    .CHECK_OUTPUT(i+c2, "7260[sec]")
    .CHECK_OUTPUT((i+=i), "120[sec]")
    .CHECK_OUTPUT(c2+d, "150[min]")
    .CHECK_OUTPUT(c+c, "4[hour]")
    .CHECK_OUTPUT((g+=g), "2000[g]")
    .CHECK_OUTPUT(f2-g, "998[kg]")
    .CHECK_OUTPUT(f2+f, "2000[kg]")
    .CHECK_OUTPUT((f2-=e), "250[kg]")
    .CHECK_OUTPUT(f+f3, "2[ton]")
    
    .setname("Incompatible dimensions")
    .CHECK_THROWS(a+c)
    .CHECK_THROWS(a+d)
    .CHECK_THROWS(b+c)
    .CHECK_THROWS(b+d)
    .CHECK_THROWS(a3-c3)
    .CHECK_THROWS(a3+=c2)
    .CHECK_THROWS(a3-=c)
    .CHECK_THROWS(a3==g)
    .CHECK_THROWS(a3-f2)
    .CHECK_THROWS(a3+=f)
    .CHECK_THROWS(a3-=c)
    .CHECK_THROWS(a3+g)
    .CHECK_THROWS(a3<=f2)
    .CHECK_THROWS(a3+=f)
    .CHECK_THROWS(a2-=c3)
    .CHECK_THROWS(a2+g)
    .CHECK_THROWS(a2-f2)
    .CHECK_THROWS(a2!=f)
    .CHECK_THROWS(a-=c3)
    .CHECK_THROWS(a+g)
    .CHECK_THROWS(a<=f2)
    .CHECK_THROWS(a+=f)
    .CHECK_THROWS(c3+g)
    .CHECK_THROWS(c3-f2)
    .CHECK_THROWS(c3!=f)
    .CHECK_THROWS(a+g)
    .CHECK_THROWS(a-f2)
    .CHECK_THROWS(a+=f)
    .CHECK_THROWS(d+g)
    .CHECK_THROWS(d>f2)
    .CHECK_THROWS(d+=f)
    .CHECK_THROWS(c+g)
    .CHECK_THROWS(c-f2)
    .CHECK_THROWS(c<f)

    .setname("other operators")
    .CHECK_OK(cout<<i)
    .CHECK_OUTPUT(-i, "-120[sec]")
    .CHECK_OUTPUT(+i, "-120[sec]")

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1.0, Unit::TON)), "1700[kg]")
     .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}