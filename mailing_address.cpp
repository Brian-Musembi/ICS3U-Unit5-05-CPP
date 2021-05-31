// Copyright (c) 2021 Brian Musembi, All rights reserved
//
// Created by Brian Musembi
// Created on May 2021
// This program formats a user inputted address into a mailing address

#include <iostream>
#include <algorithm>
#include <string>


std::string Mailing(std::string name, std::string srtNum,
                    std::string srtName, std::string city,
                    std::string province, std::string postCode,
                    std::string aptNum = "") {
    // This function converts an address to a mailing address

    std::string mailAddress;

    // process
    mailAddress = name;
    if (aptNum != "") {
        mailAddress = (mailAddress + "\n" + aptNum + "-" + srtNum +
                        " " + srtName + "\n" + city + " " + province + "  "
                        + postCode);
    } else {
        mailAddress = (mailAddress + "\n" + srtNum +
                        " " + srtName + "\n" + city + " " + province + "  "
                        + postCode);
    }
    // capitalization
    std::transform(mailAddress.begin(), mailAddress.end(), mailAddress.begin(),
                   ::toupper);

    return mailAddress;
}


main() {
    // this function gets user input
    std::cout << "This program formats your address to a mailing address"
              << std::endl;
    std::cout << "" << std::endl;

    // variables
    std::string name;
    std::string question;
    std::string aptNum = "";
    std::string srtNum;
    std::string srtName;
    std::string city;
    std::string province;
    std::string postCode;
    std::string address;

    // input
    std::cout << "Please enter your full name: ";
    std::getline(std::cin, name);
    std::cout << "Do you live in an apartment? (Y/N): ";
    std::getline(std::cin, question);
    if (question == "Y" || question == "YES") {
        std::cout << "Please enter your apartment number: ";
        std::getline(std::cin, aptNum);
    }
    std::cout << "Please enter your street number: ";
    std::getline(std::cin, srtNum);
    std::cout << "Please enter your street name: ";
    std::getline(std::cin, srtName);
    std::cout << "Please enter your city: ";
    std::getline(std::cin, city);
    std::cout << "Please enter your province "
              << "(As an abbreviation, ex: ON, BC etc...): ";
    std::getline(std::cin, province);
    std::cout << "Please enter your postal code (A1B C2D): ";
    std::getline(std::cin, postCode);
    std::cout << "" << std::endl;

    // call functions
    if (aptNum != "") {
        address = Mailing(name, srtNum, srtName, city, province, postCode,
                          aptNum);
    } else {
        address = Mailing(name, srtNum, srtName, city, province, postCode);
    }
    // output
    std::cout << address << std::endl;
}
