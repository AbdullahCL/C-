// consoldemo.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Math.h"
#include <stdlib.h>
#include "Main.h"

class Calculator
{
    private:
	  int	_op;
	  float _x;
	  float _y;

	  float add()
	  {
		  return _x + _y;
	  }

	  float sub()
	  {
		  return _x - _y;
	  }

	  float mul()
	  {
		  return _x * _y;
	  }

	  float div()
	  {
		  if (_y == 0)
		  {
			  printf("Divide By Zero...");
			  return -1;
		  }

		  return _x / _y;
	  }

	  float expo()
	  {
		  return pow(_x, _y);
	  }

	  float root()
	  {
		  return sqrt(_x);
	  }

	  float log()
	  {
		  return log10(_x);
	  }
public:
	Calculator(int op, float x, float y)
	{
		_op = op;
		_x = x;
		_y = y;
	}

	float calc()
	{
		switch (_op)
		{
		    case 0:
			    return add();
		    case 1:
			    return sub();
		    case 2:
			    return mul();
		    case 3:
			    return div();
		    case 4:
    		    return expo();	
		    case 5:
			    return root();
			case 6: 
				return log();
			default:
				return -1;				
		}
	}	
};


int _tmain(int argc, _TCHAR* argv[])
{
	while (true)
	{
		printf(_CR);
		printf(_TITLE);
		printf(_LINE);		

		for (char * op : ops)
		{
			printf(op);
			printf(_CR);
		}
		
		int a = 0;
		float x, y = 0;
		printf(_CR);
		printf("Select a Number: ");
		scanf_s("%d", &a);
		int index = 0;
		int len = sizeof(ops) / sizeof(ops[1]);
		
		for (int i = 0; i < len; i++)
		{
			if (a == i)
			{
				printf(ops[a]);
				break;
			}

			index++;
		}		
		
		if (index == len)
		{
			printf("Unknow OP.");
			scanf_s("");
			printf(_CR);
			continue;			
		}

		printf(_CR);
		printf(_LINE);
		printf(_CR);

		if (a == 7)
		{
			return 0;
		}
		
		printf("N1: ");
		scanf_s("%f", &x);

		for (int i = 0; i < 5; i++)
		{
			if (a == i)
			{
				printf("N2: ");
				scanf_s("%f", &y);
				printf(_CR);
				break;
			}
		}

		float res = 0;
		Calculator *c = new Calculator(a, x, y);
		res = c->calc();
		printf("Result : %0.4f", res);
		scanf_s("");
		printf(_CR);
	}
}

