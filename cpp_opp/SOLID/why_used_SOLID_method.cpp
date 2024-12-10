  #include <iostream>
  #include <vector>

// https://t.me/easy_c_plus/717

class IPaymentMethod {
public:
    virtual void processPayment() const = 0;
    virtual ~IPaymentMethod() = default;
};

class CreditCardPayment : public IPaymentMethod {
public:
    void processPayment() const override {
        // логика обработки платежа по кредитной карте
    }
};

class PayPalPayment : public IPaymentMethod {
public:
    void processPayment() const override {
        // логика обработки платежа через PayPal
    }
};

class BitcoinPayment : public IPaymentMethod {
public:
    void processPayment() const override {
        // логика обработки платежа через Bitcoin
    }
};

class PaymentProcessor {
    std::vector<IPaymentMethod*> paymentMethods;
public:
    void addPaymentMethod(IPaymentMethod* method) {
        paymentMethods.push_back(method);
    }

    void processPayments() const {
        for (const auto& method : paymentMethods) {
            method->processPayment();
        }
    }
};


int main() {
 
    return 0;
}

/*
 class PaymentProcessor {
 public:
     void processCreditCardPayment() {
         // логика обработки платежа по кредитной карте
     }

     void processPayPalPayment() {
         // логика обработки платежа через PayPal
     }

     void processBitcoinPayment() {
         // логика обработки платежа через Bitcoin
     }
 };

 */

