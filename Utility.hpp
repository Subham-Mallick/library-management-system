#ifndef UTILITY_HPP
#define UTILITY_HPP

#include<string>
#include<iostream>

enum BookFormat{
	HARDCOVER,
	PAPERBACK,
	AUDIOBOOK,
	EBOOK,
	NEWSPAPER,
	MAGAZINE,
	JOURNAL
};

enum BookStatus{
	AVAILABLE,
	RESERVED,
	LOANED,
	LOST
};

enum ReservationStatus{
	WAITING,
	PENDING,
	COMPLETED,
	CANCELED_RESERVATION,
	NO_INFO_RESERVATION
};

enum AccountStatus{
	ACTIVE,
	CLOSED,
	CANCELED_ACCOUNT,
	BLACKLISTED,
	NO_INFO_ACCOUNT
};

class Address{
private:
	std::string m_streetAddress;
	std::string m_city;
	std::string m_state;
	std::string m_zipCode;
	std::string m_country;
public:
	std::string getCity() const {
		return m_city;
	}

	void setCity(std::string city) {
		m_city = city;
	}

	std::string getCountry() const {
		return m_country;
	}

	void setCountry(std::string country) {
		m_country = country;
	}

	std::string getState() const {
		return m_state;
	}

	void setState(std::string state) {
		m_state = state;
	}

	std::string getStreetAddress() const {
		return m_streetAddress;
	}

	void setStreetAddress(std::string streetAddress) {
		m_streetAddress = streetAddress;
	}

	std::string getZipCode() const {
		return m_zipCode;
	}

	void setZipCode(std::string zipCode) {
		m_zipCode = zipCode;
	}
};

class Person{
private:
	std::string m_name;
	Address m_address;
	std::string m_email;
	std::string m_phone;
public:
	const Address getAddress() const {
		return m_address;
	}

	void setAddress(const Address &address) {
		m_address = address;
	}

	std::string getEmail() const {
		return m_email;
	}

	void setEmail(std::string email) {
		m_email = email;
	}

	std::string getName() const {
		return m_name;
	}

	void setName(std::string name) {
		m_name = name;
	}

	std::string getPhone() const {
		return m_phone;
	}

	void setPhone(std::string phone) {
		m_phone = phone;
	}
};

class Constant{
public:
	static int MAX_BOOKS_ISSUE_TO_USER;
	static int MAX_LENDING_DAYS;
};

int Constant::MAX_BOOKS_ISSUE_TO_USER = 5;
int Constant::MAX_LENDING_DAYS = 60;

class Date{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day,int month,int year):m_day(day),m_month(month),m_year(year){}

	bool verifyDate(int day,int month,int year){

		const int MAX_VALID_YR = 9999;
		const int MIN_VALID_YR = 1800;

		if (year > MAX_VALID_YR ||	year < MIN_VALID_YR)
			return false;

		if (month < 1 || month > 12)
			return false;

		if (day < 1 || day > 31)
			return false;

		if (month == 2)
		{
			return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)) ? (day<=29) : (day<=28);
		}

		if (month == 4 || month == 6 ||	month == 9 || month == 11)
			return (day <= 30);

		return true;
	}

	int getDay() const {
		return m_day;
	}

	int getMonth() const {
		return m_month;
	}

	int getYear() const {
		return m_year;
	}

	void showDate(){
		std::cout<<getDay()<<"/"<<getMonth()<<"/"<<getYear()<<std::endl;
	}
};

#endif
