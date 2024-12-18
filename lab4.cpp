#include <iostream>
#include <math.h>
#include <iomanip>

double x,xend, xideal, xdel, xcopy, top;
int n = 1,coi = 1, nomer = 1;
double summfac=1.0f, coupsumm, otvet_my_last, proverca=1.0f, summ = 1.0f;
double otvet_my, otvet_com, tothnost;
double e=0.1f, g = 0.0f;
float flag = true;

double proverca_vsego()
{
	if (std::cin.fail()) 
	{
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout << "Ошибка: повторите попытку ввода"<< std::endl;
		exit(0);
    }

	if ( fabs(top) > pow(10,8))
	{
		std::cout << "Ошибка: я еще не умею коректно выводить такие большие числа, напиши реальные значения";
		exit(0);
	}
	if ((top<0 && top> -pow(10, -8)) || (top > 0 && top < pow(10, -8)) ) {
		std::cout << "Ошибка: я еще не умею коректно выводить такие большие числа, напиши реальные значения";
		exit(0);
	}

	if (x > xend && xdel>0 && flag == false )
	{
		xcopy = xend;
		xend = x;
		x = xcopy;
	}
}
double e_e() 
{
	if (n != 8) {
		e = pow(10, -n);
		n += 1;
		tothnost = e;
	}
	return e;
}
double eilertable1()
{
	coupsumm = otvet_my=0;
	proverca = summfac = summ = coi = 1;
	for (coi = 1; proverca>tothnost ; coi++) 
	{
		coupsumm = summ+x;
		summfac *= coi; 
		summ += 1 / summfac;
 		otvet_my_last = coupsumm;
		otvet_my = summ + x;
		proverca = fabs(otvet_my - otvet_my_last);
	}
	return otvet_my;
}
double otvet_com_f() 
{
	otvet_com = x + exp(1);
	return otvet_com;
}
double g_f()
{
	g = sqrt(fabs(pow(otvet_my, 2) - pow(otvet_com, 2)));
	return g;
}
int main() 
{
	setlocale(LC_ALL, "ru");
	std::cout << "Введите E (Точность) :";
	std::cin >> tothnost;
	std::cout << std::endl;

	if (tothnost != pow(10,-1) && tothnost != pow(10, -2) && tothnost != pow(10, -3) && tothnost != pow(10, -4) && tothnost != pow(10, -5) && tothnost != pow(10, -6) && tothnost != pow(10, -7)) 
	{
		std::cout << "Введите допустимую погрешность \n";
		return 0;
	}

	std::cout << "Введите число X start : ";
	std::cin >> x;
	top = x;
	proverca_vsego();
	std::cout << std::endl;
	std::cout << "Введите число X end : ";
	std::cin >> xend;
	top = xend;
	proverca_vsego();
	std::cout << std::endl;
	std::cout << "Введите шаг : ";
	std::cin >> xdel;
	top = xdel;
	if (xdel == 0) 
	{
		std::cout << "Ошибка: Шаг не может равняться 0";
		return 0;
	}
	flag = false;
	proverca_vsego();
	std::cout << std::endl;
	std::cout << std::string(101,'_') << std::endl << "|" << std::setw(20) << "x" << std::setw(5) << "|" << std::setw(20) << " f(x)" << std::setw(5) << "|" << std::setw(20) << "F(x)" << std::setw(5) << "|" << std::setw(13) << "g" << std::setw(9) << "|" << std::endl;
	if (xdel < 0) 
	{
		for (x; xend <= x; x += xdel) {
			std::cout.precision(7);
			std::cout << std::fixed << "|" << std::setw(20) << x-5+5 << std::setw(5) << "|" << std::setw(20) << eilertable1() << std::setw(5) << "|" << std::setw(20) << otvet_com_f() << std::setw(5) << "|" << std::setw(13) << g_f() << std::setw(9) << "|" << std::endl;

		}
	}
	else {
		for (x; x <= xend; x += xdel)
		{
			std::cout.precision(7);
			std::cout << std::fixed << "|" << std::setw(20) << x-5+5 << std::setw(5) << "|" << std::setw(20) << eilertable1() << std::setw(5) << "|" << std::setw(20) << otvet_com_f() << std::setw(5) << "|" << std::setw(13) << g_f() << std::setw(9) << "|" << std::endl;

		}
	
	}
	std::cout << std::string(101, '_') << std::endl ;
	std::cout << "Введите число X ideal : ";
	std::cin >> xideal;
	top = xideal;
	proverca_vsego();
	std::cout << std::endl;

	std::cout <<std::string(115,'-')<< std::endl << "|" << std::setw(20) << "e" << std::setw(9) << "|" << std::setw(20) << "f(xideal)" << std::setw(9) << "|" << std::setw(20) << "F(xideal)" << std::setw(9) << "|" << std::setw(15) << "g" << std::setw(9) << "|" << std::endl;
	
	tothnost = e;

	for (nomer = 1; nomer <= 7; nomer++)     
	{
		x = xideal;
		std::cout.precision(10);
		std::cout <<std::fixed<< "|" << std::setw(20) << e_e() << std::setw(9) << "|" << std::setw(20) << eilertable1() << std::setw(9) << "|" << std::setw(20) << otvet_com_f() << std::setw(9) << "|" << std::setw(15) << g_f() << std::setw(9) << "|" << std::endl;
	}
	std::cout << std::string(115,'-') << std::endl;
	return 0;
}
