template <typename T>
concept addable = requires (T a, T b) {
    a + b;
};

void my_function(addable auto x) {}

struct X {};

int main() {
    my_function(1); // OK
    // my_function(X{}); // Fails
}
