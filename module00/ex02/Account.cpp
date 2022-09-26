#include "Account.hpp"
#include <iostream>
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm
// #include <sys/time.h>

/*
	STATIC FUNCTION
	
	Static function is independent of any object of a class.
	It can be called even if no object exists.
	 inside a class is used to access the static variables.
	It cannot access non-static variables.
	It does not have access to this-> pointer


	STATIC VARIABLE
	A static member variable is shared by all objects of the class.
	It is set to zero when the first object is created.
	Cannot be initialized inside the class.
	There is always only one copy of the static member, no matter how many
	objects are created.
	
*/


//	IS THIS ALLOWED TO BE INITIATED HERE OUTSIDE ANY FUNCTION ???
//		The initialisation of the static int i must be done outside of any function.
int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


// HOW CAN WE RETURN THE OSTREAM, SO THAT THIS FUNCTION CAN BE USED
//	BETWEEN <<  setfield() <<   ???
// std::ostream &set_field()
void set_field()
{
	std::cout << std::setfill('0') << std::setw(2);
	//return (*ostream);
}


void	Account::_displayTimestamp( void )
{
	// A)	Time since 1970
	// struct timeval my_time;
	// gettimeofday(&my_time, NULL); // NULL ??
	// std::cout << "[" << my_time.tv_sec << "_" << my_time.tv_usec << "] ";

	// B)	Time since 1900
	// time_t time = std::time(NULL);
	// struct tm now = *std::localtime(&time); 

	// std::cout << "[" << 1900 + now.tm_year;
	// set_field();
	// std::cout << 1 + now.tm_mon;
	// set_field();
	// std::cout << now.tm_mday << "_";
	// set_field();
	// std::cout << now.tm_hour;
	// set_field();
	// std::cout << now.tm_min;
	// set_field();
	// std::cout << now.tm_sec << "] ";

	// C)
	std::cout << "[19920104_091532] ";
}


Account::Account()
{
	std::cout << "Default constructor\n";
}


Account::Account(int init_dep)
{

	static int i = 0;

	this->_accountIndex = i;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = init_dep;
	this->_displayTimestamp();

	_nbAccounts++;
	_totalAmount = _totalAmount + init_dep;
	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
	i++;
}


Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed\n";
}


////////////////////////////////////////////////////////////////////
// GENERAL INFO
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}


// DISPLAY STATISTICS IN ONE LINE
void	Account::displayAccountsInfos( void )
{
	std::cout << "\n";
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << "\n\n";


	// HOW TO NOW ACCESS EACH INDIVIDUAL OBJECT ?????
	// std::cout << " ..... individual amount:" << Account::arr[0]->_amount << ";\n";

}
////////////////////////////////////////////////////////////////////


void	Account::displayStatus( void ) const
{
	// std::cout << "   STATUS-ALL\n";

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";

	if (this->_accountIndex == this->_nbAccounts -1)
		std::cout << "\n";
}


// DEPOSITING //////////////////////////////////////////////////////
void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	_amount = _amount + deposit;
	this->_nbDeposits++;
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits << "\n";
	_totalNbDeposits++;
	_totalAmount += deposit;
}
////////////////////////////////////////////////////////////////////


// WITHDRAWING /////////////////////////////////////////////////////
bool	Account::makeWithdrawal( int withdrawal )
{
	if (this->_accountIndex == 0)
		std::cout << "\n";
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	std::cout << "withdrawal:";
	if (withdrawal <= _amount)
	{
		std::cout << withdrawal << ";";
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		_amount = _amount - withdrawal;
	}
	else
	{
		std::cout << "refused" << "\n";
		return (0);
	}
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals << "\n";
	return (1);
}


// MY ADDED FUNCTIONS ////////////////////////

// void print_all_accounts(Account **arr)
// {
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		arr[i]->displayStatus();
// 		i++;
// 	}
// 	std::cout << "\n";
// }

// void initialize_objects(Account **arr, int *amounts)
// {
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		arr[i] = new Account(amounts[i]);
// 		i++;
// 	}
// 	// std::cout << "\n";
// }

// void depositing(Account **arr, int *deposits)
// {
// 	//std::cout << "   DEPOSITING\n";
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		arr[i]->makeDeposit(deposits[i]);
// 		std::cout << "\n";
// 		i++;
// 	}
// }

// void withdrawing(Account **arr, int *withdrawals)
// {
// 	//std::cout << "   WITHDRAWING\n";
// 	int i = 0;
// 	while (i < 8)
// 	{
// 		arr[i]->makeWithdrawal(withdrawals[i]);
// 		i++;
// 	}
// }

////////////////////////////////////////////////////////////////////





// 	MY MAIN ////////////////////////////////////////
// int main()
// {
// 	Account *arr[8];

// 	int amounts[8] = {42, 54, 957, 432, 1234, 0, 754, 16576};
// 	int	deposits[8] = {5, 765, 564, 2, 87, 23, 9, 20};
// 	int withdrawals[8] = {999, 34, 657, 4, 76, 999, 657, 7654};

// 	int i;
// 	initialize_objects(arr, amounts);

// 	// GENERAL STATS
// 	Account::displayAccountsInfos();

// 	// PRINT ALL ACCOUNTS
// 	print_all_accounts(arr);
// 	// std::cout << "\n";

// 	//std::cout << "	DEPOSITING: \n";
// 	depositing(arr, deposits);

// 	// GENERAL STATS
// 	Account::displayAccountsInfos();
	
// 	// PRINT ALL ACCOUNTS
// 	print_all_accounts(arr);
// 	std::cout << "\n";

// 	// WITHDRAWING
// 	// std::cout << "	WITHDRAWALS: \n";
// 	withdrawing(arr, withdrawals);

// 	// GENERAL STATS
// 	Account::displayAccountsInfos();

// 	// CLOSING
// 	i = 0;
// 	while (i < 8)
// 	{
// 		delete arr[i];
// 		i++;
// 	}
// }
