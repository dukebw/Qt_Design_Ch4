// Tests for QDir
#include <QDir>
#include <QString>
#include <QTextStream>

int main()
{
   QTextStream cout{stdout};
   QDir directory{"Documents/Letters"};
   QString path{directory.filePath("contents.txt")};
   QString absolutePath{directory.absoluteFilePath("contents.txt")};

   cout << path << endl << absolutePath << endl;
}
