#include<iostream> 
#include<math.h> 
#include<cstring> 
#pragma warning (disable: 4996) 
 using namespace std; 
 int ErrorDetectionFunction(char* c, int x); int DegreeOfPolynomial(char* c, int x); double* CofficientsOfTheEquation(char* c, int x, int n); double PolynomialFunction(double* x, int n, double parameter); double RootsOfEquation(double* coff, int n, double Xl, double Xu); 
  int main() 
{ 
 	char c[100];  	int Detector; 
  	cout << "Enter the polynomial Equation " << endl; 
 	cout << "In the form anx^n + a(n-1)x^(n-1) + ............ + a0 " << endl; 
 	cout << "Enter all the coefficients even if they are 1 or 0" << endl << endl;  
	 	cin.getline(c, strlen(c)); 
  	for (int i = 0; i < strlen(c); i++) if (c[i] == 'X') 
	 	 	c[i] += ('a' - 'A'); 
	 	Detector = ErrorDetectionFunction(c, strlen(c)); 
 
	 	if (Detector == 1) 
	 	{ 
	 	 	cout << endl << "Enter the function in correct form" << endl; 
	 	 	return 0; 
	 	} 
 
	 	double l, r; 
 
 	a:cout << endl;  	cout << "Enter the range you want to find the roots in " << endl; 
 	cout << "Strat : ";  	cin >> l; 
 	cout << "End : ";  	cin >> r; 
 
	 	if (l >= r) 
	 	{ 
	 	 	cout << endl << "Enter the smaller number first" << endl; 
	 	 	goto a; 
	 	} 
 	 
	 	int n = DegreeOfPolynomial(c, strlen(c)); 
  	double* CofficientsArray = new double[n + 1]; 
	 	CofficientsArray = CofficientsOfTheEquation(c, strlen(c), n); 
cout << endl; 
	 	if (n == 2) 
	 	{ 
 	 	double a = CofficientsArray[0];  	 	double b = CofficientsArray[1];  	 	double c = CofficientsArray[2]; 
 
 	 	if (((b * b) - (4 * a * c)) < 0)  	 	 	cout << "This function has no real roots" << endl; 
 
	 	 	else 
	 	 	{ 
 	 	 	double R1 = (-b + sqrt((b * b) - (4 * a * c))) / (2 * a);  	 	 	double R2 = (-b - sqrt((b * b) - (4 * a * c))) / (2 * a); 
 
	 	 	 	if ((R1 > l && R1 < r) && (R2 > l && R2 < r)) 
	 	 	 	{ 
	 	 	 	 	if (R1==R2) 
	 	 	 	 	 	cout << "The root number 1 is " << R1 << endl; 
 	 	 	 	 
	 	 	 	 	else 
	 	 	 	 	{ 
 	 	 	 	 	cout << "The root number 1 is " << R1 << endl;  	 	 	 	 	cout << "The root number 2 is " << R2 << endl; 
	 	 	 	 	} 
	 	 	 	} 
 
	 	 	 	else if ((R1 > l && R1 < r) && !(R2 > l && R2 < r)) 
	 	 	cout << "The root number 1 is " << R1 << endl; 
 	 	 	else if (!(R1 > l && R1 < r) && (R2 > l && R2 < r))  	 	 	 	cout << "The root number 1 is " << R2 << endl; 
 
	 	 	 	else 
	 	 	 	 	cout << "There is no roots in this range " << endl; 
	 	 	} 
	 	} 
 
	 	else 
	 	{ 
	 	 	double* temp = new double[r - l + 1]; 
 	 	double y = l;  	 	double z; 
 
	 	 	for (int i = 0; i <= (r - l); i++) 
	 	 	{ 
	 	 	 	temp[i] = y; 
	 	 	 	y++; 
	 	 	} 
	 	 	cout << endl; 
 
 	 	double Root;  	 	int k = 0; 
 
	 	 	for (int i = 0; i < (r - l); i++) 
	 	 	{ 
 	if ((PolynomialFunction(CofficientsArray, n, temp[i]) * PolynomialFunction(CofficientsArray, n, temp[i + 1])) < 0) 
	 	 	 	{ 
	 	 	 	 	k++; 
 	 	 	 	Root = RootsOfEquation(CofficientsArray, n, temp[i], temp[i + 1]); 
 	 	 	 	cout << "The root number " << k << " is " << Root << endl; 
	 	 	 	} 
	 	 	} 
 
	 	 	if (k == 0) 
	 	 	 	cout << "There is no roots in this range" << endl; 
 
	 	 	delete[] CofficientsArray; 
	 	 	delete[] temp; 
	 	} 
	 	return 0; 
} 
  int ErrorDetectionFunction(char* c, int x) 
{ 
	 	int i; 
  	if (c[x - 1] == '+' || c[x - 1] == '-')  
	 	 	return 1;   
for (i = 0; i < x; i++) 
{ 
if (c[i] != 'x' && c[i] != '^' && c[i] != '+' && c[i] != '-' && 
c[i] != '.' && c[i] != '0' && 
 	 	 	c[i] != '1' && c[i] != '2' && c[i] != '3' && c[i] != '4' && c[i] != '5' && c[i] != '6' && c[i] != '7' && 
	 	 	 	c[i] != '8' && c[i] != '9') 
	 	 	 	return 1; 
	 	} 
  	for (i = 0; i < x - 1; i++) 
	 	{ 
	 	 	if (c[i] == '^' && !(c[i + 1] >= '0' && c[i + 1] <= '9')) 
	 	 	 	return 1; 
	 	} 
  	for (i = 1; i < x; i++) 
	 	{ 
	 	 	if (c[i] == 'x' && !(c[i - 1] >= '0' && c[i - 1] <= '9')) 
	 	 	 	return 1; 
	 	} 
  	for (i = 1; i < x - 1; i++) 
	 	{ 
	 	 	if ((c[i] == '+' || c[i] == '-') && (!(c[i - 1] >= '0' && c[i - 
1] <= '9') || !(c[i + 1] >= '0' && c[i + 1] <= '9'))) 
	 	 	 	return 1; 
	 	} 
 
	 	for (i = 0; i < x-1; i++) 
	 	{ 
 	 	if ((c[i] == '+' || c[i] == '-') && (c[i + 1] == '+' || c[i + 1] == '-')) 
	 	return 1; 
} 
	 	return 0; 
} 
  int DegreeOfPolynomial(char* c, int x) 
{ 
 	int i;  	int n ; 
 	int Start=0;  	int End=0;  	int k = 0; 
 
	 	for (i = 0; i < x; i++) 
	 	{ 
	 	 	if (*(c + i) == '^') 
	 	 	{ 
 	 	 	Start = i;  	 	 	break; 
	 	 	} 
	 	} 
  	for (k = 1; k < x; k++) 
	 	{ 
	 	if (*(c + k) == '+'|| *(c + k) == '-') 
	 	{ 
 	 	End = k;  	 	break; 
} 
} 
 	int Length = End - Start;  	char* temp = new char[Length]; 
 
	 	k = 0; 
  	for (i = Start + 1; i < End; i++) 
	 	{ 
	 	 	temp[k] = c[i]; 
 	 	k++;  	} 
 
 	n = atof(temp);  	delete[]temp; 
 
	 	return n; 
}  double* CofficientsOfTheEquation(char* c, int x, int n) 
{  	double* CofficientsArray = new double[n + 1]; 
 
	 	int i = 0; 
	 	int Start = 0; 
int End = 0; 
if (c[i] == 'x') 
	 	CofficientsArray[0] = 1; 
else if (c[i] == '-' && c[i + 1] == 'x') 
	 	CofficientsArray[0] = -1; 
 
	 	else 
	 	 	CofficientsArray[0] = atof(strtok(c, "x")); 
 
 	for (i = x-1; i >= 0; i--)  	 	if (c[i] == '+' || c[i] == '-') 
	 	 	{ 
	 	 	 	Start = i; 
	 	 	 	break; 
	 	 	} 
  	int Lenght = x - Start;  	char* temp = new char[Lenght];  	int j = 0; 
  	for (i = Start; i < x; i++) 
	 	{ 
	 	 	temp[j] = c[i]; 
 	 	j++;  	} 
 
	 	CofficientsArray[n] = atof(temp); 
 i = 0; 
Start = 0; End = 0; int Length = 0; int Delimeter = 0; 
for (i = x; i >= 0; i--) 
	 	{ 
	 	 	Delimeter++; 
	 	 	if (c[i] == '+' || c[i] == '-') 
	 	 	 	break; 
	 	} 
 
	 	int counter = 1; 
 
	 	while (counter < n) 
	 	{ 
	 	 	for (i = 1; i < x - Delimeter; i++) 
	 	 	{ 
	 	 	 	if (c[i] == '+' || c[i] == '-') 
	 	 	 	{ 
	 	 	 	 	Start = i; 
	 	 	 	 	while (c[i] != 'x') 
	 	 	 	 	{ 
	 	 	 	 	 	Length++; 
	 	 	 	 	 	i++; 
	 	 	 	 	} 
	 	 	 	 	End = i; 
 
	 	 	 	 	int j = 0; 
	 	 	 	char* temp = new char[Length]; 
	 	 	 	for (int k = Start; k < End; k++) 
	 	 	 	{ 
	 	 	 	 	temp[j] = c[k]; 
	 	 	 	 	j++; 
	 	 	 	} 
 
	 	 	 	 	CofficientsArray[counter] = atof(temp); 
	 	 	 	 	counter++; 
	 	 	 	} 
	 	 	} 
	 	} 
  	return CofficientsArray; 
  	delete[] CofficientsArray;  	delete[] temp; 
}  double PolynomialFunction(double* x, int n, double parameter) 
{ 
 	int i = 0;  	double sum = 0;  	int k = n; 
  	for (i = 0; i <= n; i++) 
	 	{ 
	 	 	sum += (x[i] * pow(parameter, k)); 
	 	 	k--; 
	 	} 
 
	 	return sum; 
} 
double RootsOfEquation(double* coff, int n, double Xl, double Xu) 
{ 
 	double RelativeError = 0.00001;  	double Xr; 
 	double Start = Xl;  	double End = Xu;  	double Xrold; 
 
	 	Xr = (Start + End) / 2; 
 
	 	do 
	 	{ 
	 	 	if (fabs(PolynomialFunction(coff, n, Xr)) < RelativeError) 
	 	 	 	break; 
 
  if (PolynomialFunction(coff, n, Start) * PolynomialFunction(coff, n, Xr) < 0) 
 	 	 	End = Xr;  	 	else 
	 	 	 	Start = Xr; 
 
	 	 	Xrold = Xr; 
	 	 	Xr = (Start + End) / 2; 
 
	 	} while (fabs(Xr - Xrold) > RelativeError); 
 
	 	return Xr; 
} 
