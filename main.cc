#include"matrix.hh"
#include "tableau2D.hh"

int main(void)
{

/*  Tableau2D<float> tab(10,10);
  tab(2,2) = 42.0;
  std::cout << tab (2,2) << std::endl ;

  Tableau2D<float> tab2 = tab;
  tab2(1,1) = 1.5;
  tab2=tab;
  if ( tab2 == tab )
    std::cout << "equal" << std::endl;
  std::cout << tab2 << std::endl;*/

/*  Tableau2D<float> tab3(15,15);
  tab3=tab2;
    std::cout << tab3 << std::endl ;*/

  Matrix<float> a1(5,5,1);
  Matrix<float> a2(5,5,0);
  Matrix<float> a3=a1;
  Matrix<float> a4=(a1+a2+a3)*a1;
  std::cout<<a1<<std::endl;
  std::cout<<2*a4/2<<std::endl;
  return 0;
}
