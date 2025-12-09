#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

static void	displayTimestamp( void )
{
    std::time_t now = std::time(nullptr);
    std::tm *ptm = std::localtime(&now);

    std::cout << "[" << std::put_time(ptm, "%Y%m%d_%H%M%S") << "] ";
}

Account::Account( int initial_deposit )
{
    this->_accountIndex = _nbAccounts++;
    this->_amount = initial_deposit;

    _totalAmount += initial_deposit;

    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}


Account::~Account( void )
{
    displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}


int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos()
{
    displayTimestamp();
    std::cout << "accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals
              << std::endl;
}

void	Account::makeDeposit( int deposit )
{
    int p_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;

    _totalAmount += deposit;
    _totalNbDeposits++;

    displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}


bool	Account::makeWithdrawal( int withdrawal )
{
    int p_amount = this->_amount;

    if (withdrawal > p_amount)
    {
        displayTimestamp();
        std::cout << "index:" << this->_accountIndex
                  << ";p_amount:" << p_amount
                  << ";withdrawal:refused"
                  << std::endl;
        return false;
    }

    this->_amount -= withdrawal;
    this->_nbWithdrawals++;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;

    displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << p_amount
              << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals
              << std::endl;

    return true;
}


int Account::checkAmount() const
{
    return this->_amount;
}

void Account::displayStatus() const
{
    displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}
