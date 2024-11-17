
class IMessageService {
public:
    virtual void sendMessage(const std::string &message) = 0;
    virtual ~IMessageService() = default;
};

class EmailService : public IMessageService {
public:
    void sendMessage(const std::string &message) override {
        // Логика отправки email
    }
};

class SmsService : public IMessageService {
public:
    void sendMessage(const std::string &message) override {
        // Логика отправки SMS
    }
};

class Notification {
    IMessageService &messageService;
public:
    Notification(IMessageService &service) : messageService(service) {}

    void send(const std::string &message) {
        messageService.sendMessage(message);
    }
};



/*
 
class EmailService {
public:
    void sendEmail(const std::string &message) {
        // Логика отправки email
    }
};

class Notification {
    EmailService emailService;
public:
    void send(const std::string &message) {
        emailService.sendEmail(message);
    }
};


 
 Какова суть принципа dependency inversion в SOLID? 
https://t.me/easy_c_plus/554
 
 
Является одним из пяти принципов SOLID, которые используются для создания гибкого и легко поддерживаемого кода в объектно-ориентированном программировании. DIP гласит, что высокоуровневые модули не должны зависеть от низкоуровневых модулей. Оба типа модулей должны зависеть от абстракций. Абстракции не должны зависеть от деталей. Детали должны зависеть от абстракций.
*/
