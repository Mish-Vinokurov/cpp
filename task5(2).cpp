class Singleton {
private:
    static Singleton* pointer_to_object;
    Singleton() = default;

public:
    static Singleton& GetObject() {
        if (!pointer_to_object) {
            pointer_to_object = new Singleton();
        }
        return *pointer_to_object;
    }
    static void destroy() {
        delete pointer_to_object;
    }
};

Singleton* Singleton::pointer_to_object = nullptr;

int main() {
    Singleton a = Singleton::GetObject();
    Singleton::destroy();
}