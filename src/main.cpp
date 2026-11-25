// bank-menu.cpp — console banking app (C++ P1)
// Teaches: classes, iostream, STL containers, RAII, enums, switch.

#include <iostream>
#include <map>
#include <string>
#include <vector>

class Account {
public:
    Account() : owner_(""), balance_(0.0) {}
    explicit Account(const std::string &owner, double balance = 0.0)
        : owner_(owner), balance_(balance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            std::cerr << "deposit must be positive\n";
            return;
        }
        balance_ += amount;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            std::cerr << "withdraw must be positive\n";
            return false;
        }
        if (amount > balance_) {
            std::cerr << "insufficient funds\n";
            return false;
        }
        balance_ -= amount;
        return true;
    }

    double balance() const { return balance_; }
    const std::string &owner() const { return owner_; }

private:
    std::string owner_;
    double balance_;
};

namespace {

void print_menu() {
    std::cout << "\n=== Bank Menu ===\n"
                 "1) Open account\n"
                 "2) Deposit\n"
                 "3) Withdraw\n"
                 "4) Check balance\n"
                 "5) List accounts\n"
                 "6) Quit\n"
                 "> ";
}

} // namespace

int main() {
    std::map<int, Account> accounts;
    int next_id = 1;
    int choice;

    do {
        print_menu();
        std::cin >> choice;
        std::cin.ignore(1024, '\n');

        switch (choice) {
        case 1: {
            std::string owner;
            double balance = 0;
            std::cout << "owner: ";
            std::getline(std::cin, owner);
            std::cout << "opening balance: ";
            std::cin >> balance;
            accounts[next_id] = Account(owner, balance);
            std::cout << "created account #" << next_id << "\n";
            next_id++;
            break;
        }
        case 2: {
            int id;
            double amt;
            std::cout << "account id: ";
            std::cin >> id;
            std::cout << "amount: ";
            std::cin >> amt;
            if (auto it = accounts.find(id); it != accounts.end()) {
                it->second.deposit(amt);
                std::cout << "deposited " << amt << "\n";
            } else {
                std::cout << "no such account\n";
            }
            break;
        }
        case 3: {
            int id;
            double amt;
            std::cout << "account id: ";
            std::cin >> id;
            std::cout << "amount: ";
            std::cin >> amt;
            if (auto it = accounts.find(id); it != accounts.end()) {
                if (it->second.withdraw(amt)) {
                    std::cout << "withdrew " << amt << "\n";
                }
            } else {
                std::cout << "no such account\n";
            }
            break;
        }
        case 4: {
            int id;
            std::cout << "account id: ";
            std::cin >> id;
            if (auto it = accounts.find(id); it != accounts.end()) {
                std::cout << "balance: " << it->second.balance() << "\n";
            } else {
                std::cout << "no such account\n";
            }
            break;
        }
        case 5: {
            for (const auto &[id, acc] : accounts) {
                std::cout << "#" << id << " " << acc.owner()
                          << " bal=" << acc.balance() << "\n";
            }
            break;
        }
        case 6:
            break;
        default:
            std::cout << "invalid choice\n";
        }
    } while (choice != 6);

    std::cout << "bye\n";
    return 0;
}
