#include <iostream>
#include <ctype.h>

double itemScan(int qty);
void payment(char method, double total);

const double TAX_RATE = 0.0775;

int main()
{
  int       qty;
  char      paymentMeth;
  double    total;

  std::cout << "How many items?: ";
  std::cin >> qty;

  total = itemScan(qty);

  std::cout << "Cash or credit? Enter 'C' for Cash or 'T' for Credit: ";
  std::cin >> paymentMeth;
  paymentMeth = toupper(paymentMeth);

  payment(paymentMeth, total);

  return 0;
}

double itemScan(int qty)
{
  double    itemPrice;
  double    subtotal = 0;
  double    total;
  double    taxAmount;
  
  for(int i = 1; i <= qty; i++)
    {
      std::cout << "Please enter the cost of item #" << i << ": $";
      std::cin >> itemPrice;
      subtotal = itemPrice + subtotal;
    }
  taxAmount = (subtotal * TAX_RATE);
  total = taxAmount + subtotal;

  std::cout.setf(std::ios::showpoint);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(2);
  
  std::cout << "\nSubtotal: $" << subtotal << std::endl;
  std::cout << "Tax(7.75%): $" << taxAmount << std::endl;
  std::cout << "Total: $" << total << std::endl;
  
  return total;
}

void payment(char method, double total)
{
  double cash = 0;
  double change;
  
  while(!(method == 'C' || method == 'T'))
    {
      std::cout << "Enter 'C' for Cash or 'T' for Credit: ";
      std::cin >> method;
    }

  if(method == 'C')
    {
      std::cout << "Cash: $";
      std::cin >> cash;
      if(cash < total)
	{
	  do{
	    total = total - cash;
	    std::cout << "Amount Due: $" << total << std::endl;
	    std::cout << "Enter 'C' for Cash or 'T' for Credit: ";
	    std::cin >> method;
	    method = toupper(method);
	    while(!(method == 'C' || method == 'T'))
	      {
		std::cout << "Enter correct selection: ";
		std::cin >> method;
		method = toupper(method);
	      }
	      if(method == 'T')
		{
		  std::cout << "Card Payment: $" << total << std::endl;
		  exit(0);
		}
	      else if(method == 'C')
		{
		  std::cout << "Cash: $";
		  std::cin >> cash;
		}
	  }while(cash < total);
	}
      if(cash >= total)
	{
	  change = cash - total;
	  std::cout << "Change: $" << change << std::endl;
	}
    }
  else if(method == 'T')
    {
       std::cout << "Card Payment: $" << total << std::endl;
    }
}
	
	    
		    
		    
		    
		
	    
   
