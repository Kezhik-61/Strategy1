#include <QCoreApplication>
#include <iostream>
#include <string>
using namespace std;

// Иерархия классов, определяющая алгоритмы сжатия файлов
class Compression {
  public:
    virtual ~Compression() {}
    virtual void compress() = 0;
};

class ZIP_Compression : public Compression {
  public:
    void compress() {
        cout << "ZIP compression" << endl;
    }
};

class ARJ_Compression : public Compression {
  public:
    void compress() {
        cout << "ARJ compression" << endl;
    }
};

class RAR_Compression : public Compression {
  public:
    void compress() {
        cout << "RAR compression" << endl;
    }
};


// Класс для использования
class Compressor {
  public:
    Compressor( Compression* comp): p(comp) {}
   ~Compressor() { delete p; }
    void compress() {
      p->compress();
    }
  private:
    Compression* p;
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Compressor* p = new Compressor( new ZIP_Compression);
    p->compress();
    delete p;
    return a.exec();
}
