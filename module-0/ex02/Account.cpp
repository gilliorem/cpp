#include "Account.hpp"
int Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
			  << "total:" << getTotalAmount() << ";"
			  << "deposits:" << getNbDeposits() << ";"
			  << "withdrawals:" << getNbWithdrawals() 
			  << std::endl;
}

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;  
	_nbAccounts++;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
			  << "amount:" << _amount << ";"
			  << "created" << std::endl;
}

//[19920104_091532] index:0;amount:47;closed
Account::~Account(void){
	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" 
			  << "amount:" << _amount << ";"
			  << "closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
	struct tm *t = localtime(&now);
	std::cout << std::setfill('0');
	std::cout << "[" << 1900 + t->tm_year ;
	std::cout << std::setw(2) << t->tm_mon + 1 ;
	std::cout << std::setw(2) << t->tm_mday ;

	std::cout << "_" ;

	std::cout << std::setw(2) << t->tm_hour;
	std::cout << std::setw(2) << t->tm_min;
	std::cout << std::setw(2) << t->tm_sec;

	std::cout << "] " ;
		
}

//[19920104_091532] index:1;p_amount:54;deposit:765;amount:819;nb_deposits:1
void Account::makeDeposit(int deposit)
{
	int p_amount = _amount;	
	_amount += deposit;
	_nbDeposits++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "deposit:" << deposit << ";"
			  << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits
			  << std::endl;

	_totalAmount += deposit;
	_totalNbDeposits++;
}

/*[19920104_091532] index:0;p_amount:47;withdrawal:refused // summary line ?
[19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1 */
bool	Account::makeWithdrawal( int withdrawal )
{
	int p_amount = _amount;	

	_displayTimestamp();
	if (withdrawal > _amount || withdrawal < 0)
	{
		std::cout << "index:" << _accountIndex << ";"
			<< "p_amount:" << p_amount << ";"
			<< "withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << p_amount << ";"
			  << "withdrawal:" << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	return true;
}

int		Account::checkAmount( void ) const
{
	return _amount;
}

//[19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals
			  << std::endl;
}

Account::Account (void){}
