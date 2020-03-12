#ifndef ROLES_HPP
#define ROLES_HPP

#include "Utility.hpp"
#include "Error.hpp"

class Account{
private:
	std::string m_id;
	std::string m_password;
	AccountStatus m_accountStatus;
	Person m_person;
public:

	Account(std::string id,std::string password){
		m_id = id;
		m_password = password;
		m_accountStatus = ACTIVE;
	}

	AccountStatus getAccountStatus() const {
		return m_accountStatus;
	}

	void setAccountStatus(AccountStatus accountStatus) {
		m_accountStatus = accountStatus;
	}

	std::string getId() const {
		return m_id;
	}

	void setId(std::string id) {
		m_id = id;
	}

	std::string getPassword() const {
		return m_password;
	}

	void setPassword(std::string password) {
		m_password = password;
	}

	Person getPerson() const {
		return m_person;
	}

	void setPerson(Person person) {
		m_person = person;
	}
};

class Member: public Account{
private:
	Date dateOfMembership;
	int totalBooksCheckedOut;
public:

	Member(std::string id,std::string password,Date date):Account(id,password),dateOfMembership(date){
	}

	Date getDateOfMembership() const {
		return dateOfMembership;
	}

	void setDateOfMembership(Date dateOfMembership) {
		this->dateOfMembership = dateOfMembership;
	}

	int getTotalBooksCheckedOut() const {
		return totalBooksCheckedOut;
	}

	void setTotalBooksCheckedOut(int totalBooksCheckedOut) {
		this->totalBooksCheckedOut = totalBooksCheckedOut;
	}
};

class Librarian: public Account{
public:
	Librarian(std::string id,std::string password):Account(id,password){
	}

	bool addBookItem(){
		//todo
	}

	bool blockMember(Member &member){
		if(member.getAccountStatus()==ACTIVE){
			member.setAccountStatus(BLACKLISTED);
			return true;
		}
		else{
			Error::showError("Can not block current member. Reason Member status:"+member.getAccountStatus());
			return false;
		}
	}

	bool unblockMember(Member &member){
		if(member.getAccountStatus()==BLACKLISTED){
			member.setAccountStatus(ACTIVE);
			return true;
		}
		else{
			Error::showError("Can not unblock current member. Reason Member status:"+member.getAccountStatus());
			return false;
		}
	}
};



#endif
