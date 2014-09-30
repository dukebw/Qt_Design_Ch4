#include <QCoreApplication>
#include <QTextStream>
#include <QDirIterator>
#include <QDir>
#include <QString>

int main(int argc, char* argv[])
{
   QCoreApplication app{argc, argv};
   QTextStream cerr{stderr};
   QTextStream cout{stdout};

   QDir dir{QDir::current()};
   if (app.arguments().size() > 1)
      dir = app.arguments()[1];
   if (!dir.exists()) {
      cerr << dir.path() << " does not exist!" << endl;
      return -1;
   }
   QDirIterator qdi{dir.absolutePath(), QStringList() << "*.mp3",
      QDir::NoSymLinks | QDir::Files, QDirIterator::Subdirectories};
   while (qdi.hasNext())
      cout << qdi.next() << endl;
   return 0;
}
