#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Create a QLabel widget with text "Hello, World!"
    QLabel label("Hello, World!");

    // Show the label
    label.show();

    // Run the application event loop
    return app.exec();
}