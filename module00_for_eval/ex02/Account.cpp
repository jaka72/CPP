#include "Account.hpp"
#include <iostream>
#include <iomanip>      // std::get_time
#include <ctime>        // struct std::tm


int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


void set_field()
{
	std::cout << std::setfill('0') << std::setw(2);
}


void	Account::_displayTimestamp( void )
{
	// A)	Time since 1900
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

	// B)	To compare with the original
	std::cout << "[19920104_091532] ";
}

// Default Constructor
Account::Account()
{ }

// Constructor with parameter
Account::Account(int init_dep)
{
	static int i = 0;

	this->_accountIndex = i;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	this->_amount = init_dep;
	this->_displayTimestamp();

	this->_nbAccounts++;
	this->_totalAmount = _totalAmount + init_dep;
	
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created\n";
	i++;
}

// Destructor
Account::~Account()
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed\n";
}


////////////////////////////////////////////////////////////////////
// Static Public Member Functions

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


void	Account::displayAccountsInfos( void )	// DISPLAY STATISTICS IN ONE LINE
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << "\n";
}



////////////////////////////////////////////////////////////////////
// Public Member Functions

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << "\n";
}


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

bool	Account::makeWithdrawal( int withdrawal )
{
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
