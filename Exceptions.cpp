#include "Exceptions.h"


const char* salaryExc::what() const noexcept
{
	// return pointer to message string
	return " Salary Is Not Valid ,Please Enter A Value higher Than 5000 : \n";
}
char  const*balanceExc:: what() const  noexcept
{
		// return pointer to message string
		return " Balance Is Not Valid ,Please Enter A Value Higher Than 1500 : \n";
}

const char* isBalanceAllowedExc::what() const noexcept
{
	// return pointer to message string
	return " You Don't Have Enough Balance \n";
}
const char* clientNotFound::what() const noexcept
{
	// return pointer to message string
	return "no such client\n";
}
