  #include <iostream>
   
/*
   𝐘𝐨𝐮 𝐚𝐫𝐞 𝐰𝐞𝐥𝐜𝐨𝐦𝐞 𝐭𝐨 "𝐅𝐨𝐥𝐥𝐨𝐰" 𝐦𝐞 𝐛𝐮𝐭 𝐈 𝐨𝐧𝐥𝐲 𝐜𝐨𝐧𝐧𝐞𝐜𝐭 𝐭𝐨 𝐩𝐞𝐨𝐩𝐥𝐞 𝐭𝐡𝐚𝐭 𝐈 𝐤𝐧𝐨𝐰.
   ● !!! 𝐈 𝐚𝐦 𝐍𝐎𝐓 𝐚𝐧 𝐎𝐩𝐞𝐧 𝐍𝐞𝐭𝐰𝐨𝐫𝐤𝐞𝐫 !!!
   ● Only invite me if you know me !
   ● If you invite me, tell me how you know me !
   ● I will "I Don't Know" you !
 
 
 ==========
 brew install crow 
 brew install asio
 
 /usr/local/Cellar/crow/1.2.0/include
 
 =======
 (2024-12-10 13:03:20) [INFO    ] Crow/master server is running at http://0.0.0.0:8080 using 8 threads
 (2024-12-10 13:03:20) [INFO    ] Call `app.loglevel(crow::LogLevel::Warning)` to hide Info level logs.

*/

#include <crow.h> // Include Crow header
// https://crowcpp.org/master/getting_started/setup/linux/
// https://crowcpp.org/master/getting_started/setup/linux/
// https://www.linkedin.com/posts/nikolai-kutiavin_cplusplus-restapi-crowlibrary-activity-7272158193286266881-S_9A/?utm_source=share&utm_medium=member_desktop

int main() {
    crow::SimpleApp app;
// Route: GET /
    CROW_ROUTE(app, "/")
    ([]() {
     return "Welcome to the Crow REST API!";
    });

     // Route: GET /hello
     CROW_ROUTE(app, "/hello")
    ([]() {
        return "Hello, Crow!";
    });
    // Route: POST /json
    CROW_ROUTE(app, "/json").methods(crow::HTTPMethod::POST)
    ([](const crow::request& req) {
        auto body = crow::json::load(req.body);
        if (!body) {
            return crow::response(400, "Invalid JSON");
        }
        
    // Parse JSON and prepare a response
        std::string name = body["name"].s();
        int age = body["age"].i();
        crow::json::wvalue response;
        response["message"] = "Hello, " + name + "!";
        response["your_age_in_5_years"] = age + 5;
                                                           
       return crow::response(response);
});
   // Run the server
       app.port(8080).multithreaded().run();
       return 0;
}

