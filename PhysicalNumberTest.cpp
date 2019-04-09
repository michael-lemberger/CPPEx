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
    .CHECK_EQUAL(g==f3, false)
    .CHECK_EQUAL(g<f2,true)
    .CHECK_EQUAL(g>f3,false)
    .CHECK_EQUAL(a3<=h, false)
    .CHECK_EQUAL(a3>=h, true)
    .CHECK_EQUAL(c3!=c2, false)
    .CHECK_EQUAL(a!=h, true)
    .CHECK_EQUAL(i!=c2, true)
    .CHECK_EQUAL(c3>c2, false)
    .CHECK_EQUAL(c3<c2, false)
    .CHECK_EQUAL(c3>=c2, true)
    .CHECK_EQUAL(a>b, true)
    .CHECK_EQUAL(a<h, false)
    .CHECK_EQUAL(i>=c3, false)
    .CHECK_EQUAL(c<=i, false)
    .CHECK_EQUAL(c>=i, true)


  
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
    .CHECK_OUTPUT((f2+PhysicalNumber(750,Unit::KG)), "1000[kg]")
    .CHECK_OUTPUT((f2-PhysicalNumber(750,Unit::KG)), "-500[kg]")
    .CHECK_OUTPUT((f-f3), "0[ton]")
    .CHECK_OUTPUT((PhysicalNumber(5400,Unit::SEC)+d),"7200[sec]")
    .CHECK_OUTPUT((PhysicalNumber(5400,Unit::SEC)-d),"3600[sec]")
    .CHECK_OUTPUT((d-=i),"28[min]")
    .CHECK_OUTPUT((a+PhysicalNumber(6000,Unit::M)),"7.299[km]")
    .CHECK_OUTPUT((a-PhysicalNumber(6000,Unit::M)),"-4.701[km]")
    .CHECK_OUTPUT((PhysicalNumber(5,Unit::TON)-PhysicalNumber(400,Unit::KG)),"4.6[ton]")
    .CHECK_OUTPUT((PhysicalNumber(200,Unit::KG)+PhysicalNumber(6000,Unit::G)),"206[kg]")
    .CHECK_OUTPUT((PhysicalNumber(200,Unit::MIN)+PhysicalNumber(6000,Unit::SEC)),"300[min]")
    .CHECK_OUTPUT((PhysicalNumber(200,Unit::HOUR)-PhysicalNumber(6000,Unit::MIN)),"100[hour]")
    .CHECK_OUTPUT((PhysicalNumber(200,Unit::CM)+PhysicalNumber(6,Unit::KM)),"600200[cm]")
    .CHECK_OUTPUT((PhysicalNumber(200,Unit::M)-PhysicalNumber(8700,Unit::CM)),"113[m]")
    .CHECK_OK(a=PhysicalNumber(200000,Unit::CM))
    .CHECK_OUTPUT(a,"2[km]")
    .CHECK_OK(a2=PhysicalNumber(2,Unit::KM))
    .CHECK_OUTPUT(a2,"2000[m]")
    .CHECK_OK(a3=PhysicalNumber(20,Unit::M))
    .CHECK_OUTPUT(a3,"2000[cm]")
    .CHECK_OK(c=PhysicalNumber(120,Unit::MIN))
    .CHECK_OUTPUT(c,"2[hour]")
    .CHECK_OK(c2=PhysicalNumber(240,Unit::SEC))
    .CHECK_OUTPUT(c2,"4[min]")
    .CHECK_OK(c3=PhysicalNumber(1,Unit::HOUR))
    .CHECK_OUTPUT(c3,"3600[sec]")
    .CHECK_OK(f=PhysicalNumber(3000,Unit::KG))
    .CHECK_OUTPUT(f,"3[ton]")
    .CHECK_OK(f2=PhysicalNumber(5000,Unit::G))
    .CHECK_OUTPUT(f2,"5[kg]")
    .CHECK_OK(f3=PhysicalNumber(1,Unit::TON))
    .CHECK_OUTPUT(f3,"1e+06[g]")
    
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
     .CHECK_THROWS(PhysicalNumber(200,Unit::TON)+PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::TON)-PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::TON)==PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::TON)>=PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::TON)<=PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::TON)!=PhysicalNumber(2.4,Unit::KM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)+PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)-PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)==PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)>=PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)<=PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::KG)!=PhysicalNumber(2.4,Unit::CM))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)+PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)-PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)==PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)>=PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)<=PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::HOUR)!=PhysicalNumber(2.4,Unit::M))
      .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)+PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)-PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)==PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)>=PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)<=PhysicalNumber(2.4,Unit::M))
    .CHECK_THROWS(PhysicalNumber(200,Unit::SEC)!=PhysicalNumber(2.4,Unit::M))
      .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)+PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)-PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)==PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)>=PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)<=PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)!=PhysicalNumber(2.4,Unit::G))
      .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)+PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)-PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)==PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)>=PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)<=PhysicalNumber(2.4,Unit::G))
    .CHECK_THROWS(PhysicalNumber(200,Unit::MIN)!=PhysicalNumber(2.4,Unit::G))

        .setname("other operators")
    .CHECK_OK(cout<<i)
    .CHECK_OUTPUT((-i), "-120[sec]")
    .CHECK_OUTPUT(+i, "120[sec]")
    .CHECK_EQUAL((a2++), PhysicalNumber(200000,Unit::CM))
    .CHECK_EQUAL(a2, PhysicalNumber(2.00100,Unit::KM))
    .CHECK_OK((++(++b)))
    .CHECK_OUTPUT(b, "302[m]")
    .CHECK_OK(b--)
    .CHECK_OUTPUT(b, "301[m]")
    .CHECK_OK(--(--e))
    .CHECK_OUTPUT(e, "748[kg]")
    .CHECK_OK(++(++e))
    .CHECK_OUTPUT(e, "750[kg]")
    .CHECK_OK((e)++)
    .CHECK_OUTPUT(e, "751[kg]")
    .CHECK_OK((e--))
    .CHECK_OUTPUT(e, "750[kg]")
    .CHECK_OK(--(--i))
    .CHECK_OUTPUT(i, "118[sec]")
    .CHECK_OK(++(++i))
    .CHECK_OUTPUT(i, "120[sec]")
    .CHECK_OK((i)++)
    .CHECK_OUTPUT(i, "121[sec]")
    .CHECK_OK((i--))
    .CHECK_OUTPUT(i, "120[sec]")
    .CHECK_OUTPUT(-e, "-750[kg]")
    .CHECK_OUTPUT(+e, "750[kg]")
    .CHECK_OUTPUT(+b, "301[m]")
    .CHECK_OUTPUT(-b, "-301[m]")


   

    .setname("Basic input")
    .CHECK_OK(istringstream("700[kg]") >> a)
    .CHECK_OUTPUT((a += PhysicalNumber(1.0, Unit::TON)), "1700[kg]")
    .CHECK_OK(istringstream("5[ton]") >> b)
    .CHECK_OUTPUT((b += PhysicalNumber(300, Unit::KG)), "5.3[ton]")
    .CHECK_OK(istringstream("120[g]") >> c)
    .CHECK_OUTPUT((c += PhysicalNumber(1, Unit::KG)), "1120[g]")
    .CHECK_OK(istringstream("7[hour]") >> d)
    .CHECK_OUTPUT((d += PhysicalNumber(120, Unit::MIN)), "9[hour]")
    .CHECK_OK(istringstream("12[min]") >> e)
    .CHECK_OUTPUT((e += PhysicalNumber(2, Unit::HOUR)), "132[min]")
    .CHECK_OK(istringstream("60[sec]") >> f)
    .CHECK_OUTPUT((f += PhysicalNumber(1, Unit::MIN)), "120[sec]")
    .CHECK_OK(istringstream("100[cm]") >> g)
    .CHECK_OUTPUT((g += PhysicalNumber(1, Unit::M)), "200[cm]")
    .CHECK_OK(istringstream("2[m]") >> h)
    .CHECK_OUTPUT((h += PhysicalNumber(1, Unit::KM)), "1002[m]")
    .CHECK_OK(istringstream("3[km]") >> i)
    .CHECK_OUTPUT((i += PhysicalNumber(100000, Unit::CM)), "4[km]")
     .print(cout, /*show_grade=*/false);
      grade = testcase.grade();
    } else {
      testcase.print_signal(signal);
      grade = 0;
    }
    cout <<  "*** Grade: " << grade << " ***" << endl;
    return grade;
}
