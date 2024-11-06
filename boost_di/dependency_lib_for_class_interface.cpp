// https://www.linkedin.com/posts/nikolai-kutiavin_cpp-dependencyinjection-boostdi-activity-7259837027360075776-7K3h/?utm_source=share&utm_medium=member_desktop

//     C++14 Dependency Injection Library
// https://github.com/boost-ext/di
// include/boost and move to root folder di.hpp

#include "di.hpp" // or  brew install boost #include <boost/di.hpp>
#include <iostream>
#include <memory>
#include <string>

class Model {
    public: virtual ~Model() = default;
    
    public:
        virtual std::string getData( ) const = 0;
};

class View {
    public:
        virtual ~View() = default;
    
    public:
        virtual void render(const std::string &data) = 0;
};

class Application {
public:
    explicit Application(std::string name, std::unique_ptr<Model> &&model,
     std::unique_ptr<View> &&view)
    : m_appName(std::move(name)), m_model(std::move(model)),
    m_view(std::move(view)) {}
    
public:
    int run() {
        auto data = m_model->getData();
        m_view->render(data);
        std::cout << "App is run '" << m_appName << "'" << std::endl;
        return 0;
    }
    
private:
    std::string m_appName;
    std::unique_ptr<Model> m_model;
    std::unique_ptr<View> m_view;
};

class ModelImpl : public Model {
    public:
    std::string getData() const override { return "Some model data"; }
};

class ViewImpl : public View {
public:
    void render(const std::string &data) override {
        std::cout << "Render the data: " << data << std::endl;
    }
};
    
int main() {
    namespace di = boost::di;
    auto injector = di::make_injector(di::bind<std::string>.to( "Hello world"),
    di::bind<Model>.to<ModelImpl>(),
    di::bind<View>.to<ViewImpl>());
    auto app = injector.create<Application>();
    return app.run();
}

